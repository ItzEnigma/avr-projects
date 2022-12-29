const express = require('express');
const superagent = require('superagent');
const app = express();
const cors = require('cors');
const serialController = require('./controllers/serialController');
const fs = require('fs/promises');
let localBuffer = 'Empty';
let portObjTemp;
const statusObj = {
  outdoorTemp: '34°',
  outdoorHum: '10%',
  indoorTemp: '31°',
  doorStatus: 'Closed',
  lightIIntensityStatus: '70%',
};
const hexToDecimal = (hex) => {
  return parseInt(hex, 16);
};
const getWeather = async () => {
  const response = await superagent.get(
    'http://api.weatherapi.com/v1/current.json?key=1e2e153b52cc4f3ca55212643222812&q=Cairo&aqi=no'
  );
  // console.log(response.body.current);
  let temp = response.body.current.temp_c;
  let hum = response.body.current.humidity;
  statusObj.outdoorTemp = temp + '°';
  statusObj.outdoorHum = hum + '%';
};
getWeather();
setInterval(() => {
  getWeather();
}, 10000);
const saveData = async (data) => {};
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

app.get('/statusData', (req, res) => {
  res.status(200).json({
    data: statusObj,
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
