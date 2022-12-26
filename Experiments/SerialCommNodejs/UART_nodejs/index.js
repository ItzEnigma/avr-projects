const express = require('express');
const app = express();
const cors = require('cors');
const serialController = require('./controllers/serialController');
const fs = require('fs/promises');
let localBuffer = 'Empty';
let portObjTemp;
let dataType = 'A';
let oscObj = [];
let logicObj = [];
let valueOSCi;
let valueLogic;
let osciByteCounter = 0;
let logicByteCounter = 0;
let valueLogicArray = [];
const hexToDecimal = (hex) => {
  return parseInt(hex, 16);
};
const oscliscopeHandler = (data) => {
  let stampTime;
  if (data !== 'Q') {
    switch (osciByteCounter) {
      case 0:
        valueOSCi = hexToDecimal(data);
        osciByteCounter++;
        break;
      case 1:
        osciByteCounter = 0;
        stampTime = hexToDecimal(data);
        oscObj.push({ time: stampTime, value: valueOSCi });
        break;
      default:
        break;
    }
  } else {
    osciByteCounter = 0;
    console.log('OSCI');
    console.log(oscObj);
    dataType = 'A';
  }
};
const digitalHandler = (data) => {
  let stampTime;
  if (data !== 'Q') {
    switch (logicByteCounter) {
      case 0:
        valueLogic = hexToDecimal(data);
        logicByteCounter++;
        break;
      case 1:
        logicByteCounter = 0;
        stampTime = hexToDecimal(data);
        valueLogicArray = [];
        valueLogicArray[0] = valueLogic & 1;
        valueLogicArray[1] = valueLogic & 2;
        valueLogicArray[2] = valueLogic & 4;
        valueLogicArray[3] = valueLogic & 8;
        valueLogicArray[4] = valueLogic & 16;
        valueLogicArray[5] = valueLogic & 32;
        valueLogicArray[6] = valueLogic & 64;
        valueLogicArray[7] = valueLogic & 128;
        let localObj = { time: stampTime, value: valueLogicArray };
        // console.log(localObj);
        logicObj.push(localObj);
        console.log(logicObj);
        break;
      default:
        break;
    }
  } else {
    console.log('LOGIC');
    logicByteCounter = 0;
    console.log(logicObj);
    dataType = 'A';
  }
};
const saveData = async (data) => {
  if (data === '~') {
    oscObj = [];
    dataType = 'Oscli';
  } else if (data === 'R') {
    oscObj = [];
    logicObj = [];
  } else if (data === 'L') {
    dataType = 'Digital';
    logicObj = [];
  } else {
    switch (dataType) {
      case 'Oscli':
        oscliscopeHandler(data);
        break;
      case 'Digital':
        digitalHandler(data);
        break;
      default:
        console.log(data);
        localBuffer = data;
        break;
    }
  }
};
/*
const logIT = (data) => {
  console.log('from local ' + data);
};
const { message: openStatus, PortObj: portObj } = serialController.Open('COM3');
console.log(openStatus);
const writeStatus = serialController.sendData('HI From Express', portObj);
console.log(writeStatus);

serialController.readData(portObj, logIT);
*/
const readingPort = () => {
  if (portObjTemp) {
  }
};
/* Turn on reading */
readingPort();
//////////////////////////////////
// Server
app.use(cors());
app.use(express.json({ limit: '50kb' }));
/////////////////////////
// init
app.post('/connect', async (req, res) => {
  /* Writing For Now */
  const port = req.body.port;
  console.log(port);
  const { status, message, PortObj: portObj } = serialController.Open(port);
  /* save object to global variable */
  portObjTemp = portObj;
  /* Turn on reading */
  serialController.readData(portObjTemp, saveData);
  if (status === 'Success') {
    res.status(200).json({
      status,
      message,
    });
  } else {
    res.status(400).json({
      status,
      message,
    });
  }
});
/////////////////////////
// POST Data
app.post('/sendData', async (req, res) => {
  const data = req.body.data;
  const { status, message } = serialController.sendData(data, portObjTemp);

  if (status === 'Success') {
    res.status(200).json({
      status,
      message,
    });
  } else {
    res.status(400).json({
      status,
      message,
    });
  }
});
/////////////////////////
// GET Reading
app.get('/ReadData', async (req, res) => {
  console.log(localBuffer);
  res.status(200).json({
    data: localBuffer,
  });
});
app.get('/oscData', async (req, res) => {
  // console.log(localBuffer);
  res.status(200).json({
    data: oscObj,
  });
});
app.get('/logicData', async (req, res) => {
  // console.log(localBuffer);
  res.status(200).json({
    data: logicObj,
  });
});
const port = 8000;
const server = app.listen(port, () => {
  console.log(`works on ${port} ...`);
});

app.get('/disconnect', (req, res) => {
  const { status, message } = serialController.Close(portObjTemp);
  if (status === 'Success') {
    res.status(200).json({
      status,
      message,
    });
  } else {
    res.status(400).json({
      status,
      message,
    });
  }
});
