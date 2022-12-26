const avgFreq = document.getElementById('avg-freq');
const pulseWidth = document.getElementById('pulse-width');
const avgVolt = document.getElementById('avg-volt');
const peakVolt = document.getElementById('peak-volt');
const LENGTH = 20; // length of data you should do operation to
const calcAvgFreq = (data) => {
  // data is array of obiects {time:0,vlaue:0}
  let result = 0;
  let max = 0;
  let arr = [0, 0];
  let index = 0;
  let prevTime = 0;
  let currTime = 0;
  let period = 0;
  let flag = 0;
  if (data.length < LENGTH) {
    result = 0;
  } else {
    data.forEach((element) => {
      element.value[0] > max ? (max = element.value[0]) : (max = max);
    });
    for (let i = 0; i < data.length; i++) {
      if (data[i].value[0] === max) {
        if (flag == 1) {
          currTime = data[i].time;
          break;
        } else {
          prevTime = data[i].time;
          flag = 1;
        }
      }
    }
    period = (currTime - prevTime) * (8 * Math.pow(10, -6)); //time in s
    result = (1 / period).toFixed(0);
  }
  avgFreq.innerHTML = result;
};
const calcPulseWidth = (data) => {
  // data is array of obiects {time:0,vlaue:0}
  let result = 0;
  let flagMax = 0;
  let flagMin = 0;
  let prevTime = 0;
  let currTime = 0;
  let max = 0;

  if (data.length < LENGTH) {
    result = 0;
  } else {
    data.forEach((element) => {
      element.value[0] > max ? (max = element.value[0]) : (max = max);
    });

    for (let i = 0; i < data.length; i++) {
      if (data[i].value[0] === max) {
        if (flagMax == 0) {
          currTime = data[i].time;
          flagMax = 1;
        }
      } else {
        if (flagMin == 0) {
          prevTime = data[i].time;
          flagMin = 1;
        }
      }
      if (flagMax == 1 && flagMin == 1) {
        break;
      }
    }
    result = (
      (currTime > prevTime ? currTime - prevTime : prevTime - currTime) *
      (8 * Math.pow(10, -6)) *
      1000
    ).toFixed(2);
  }
  pulseWidth.innerHTML = result;
};
const calcAvgVolt = (data) => {
  // data is array of obiects {time:0,vlaue:0}
  let result = 0;
  let max = 0;
  if (data.length < LENGTH) {
    result = 0;
  } else {
    data.forEach((element) => {
      element.value > max ? (max = element.value) : (max = max);
    });
    result = ((2 * ((max * 5) / 255)) / Math.PI).toFixed(2);
  }
  avgVolt.innerHTML = result;
};

const calcPeakVolt = (data) => {
  // data is array of obiects {time:0,vlaue:0}
  let result = 0;
  let max = 0;
  if (data.length < LENGTH) {
    result = 0;
  } else {
    data.forEach((element) => {
      element.value > max ? (max = element.value) : (max = max);
    });
    result = ((max * 5) / 255).toFixed(2);
  }
  peakVolt.innerHTML = result;
};

const calcAvgFreqOsc = (data) => {
  // data is array of obiects {time:0,vlaue:0}
  let max = -1111;
  let min = 1000;
  let arr = [0, 0];
  let index = 0;
  let prevTime = 0;
  let currTime = 0;
  let period = 0;
  let flag = 0;
  let nextMaxFlag = 0;
  let nextMaxIndex = 0;
  let minIndex = 0;
  let maxIndex = 0;
  let result = 0;

  if (data.length < LENGTH) {
    result = 0;
  } else {
    if (data.length < LENGTH) {
      result = 0;
    } else {
      data.forEach((element, i) => {
        if (element.value > max) {
          max = element.value;
          minIndex = i;
        }
      });

      data.forEach((element, i) => {
        if (element.value < min) {
          min = element.value;
          minIndex = i;
        }
      });

      for (let i = 0; i < data.length; i++) {
        if (data[i].value > max - 5) {
          if (nextMaxFlag == 1) {
            // Second Max
            console.log(` ${i} Sec MAX: ${data[i].value}`);
            currTime = data[i].time;
            break;
          } else {
            // First Max
            if (flag === 0) {
              prevTime = data[i].time;
              console.log(` ${i} First MAX: ${data[i].value}`);
            }
            flag = 1;
          }
        }

        if (data[i].value == min && flag == 1) {
          //console.log(` ${i} OKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK `);
          nextMaxFlag = 1;
        }
      }

      console.log(`currTime: ${currTime} `);
      console.log(`prevTime: ${prevTime} `);
      period = (currTime - prevTime) * (8 * Math.pow(10, -6)); //time in s
      result = (1 / period).toFixed(0);
    }
  }
  avgFreq.innerHTML = result;
};

const calcPulseWidthOsc = (data) => {
  // data is array of obiects {time:0,vlaue:0}
  let max = -1111;
  let min = 1000;
  let arr = [0, 0];
  let index = 0;
  let prevTime = 0;
  let currTime = 0;
  let period = 0;
  let flag = 0;
  let nextMaxFlag = 0;
  let nextMaxIndex = 0;
  let minIndex = 0;
  let maxIndex = 0;
  let result = 0;
  let squareFlag = 0;
  if (data.length < LENGTH) {
    result = 0;
  } else {
    if (data.length < LENGTH) {
      result = 0;
    } else {
      data.forEach((element, i) => {
        if (element.value > max) {
          max = element.value;
          minIndex = i;
        }
      });

      data.forEach((element, i) => {
        if (element.value < min) {
          min = element.value;
          minIndex = i;
        }
      });

      for (let i = 0; i < data.length; i++) {
        if (data[i].value > max - 5) {
          if (nextMaxFlag == 1) {
            // Second Max
            console.log(` ${i} Sec MAX: ${data[i].value}`);
            currTime = data[i].time;
            break;
          } else {
            // First Max
            if (flag === 0) {
              prevTime = data[i].time;
              console.log(` ${i} First MAX: ${data[i].value}`);
            }
            flag = 1;
          }
        }

        if (data[i].value == min && flag == 1) {
          //console.log(` ${i} OKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK `);
          nextMaxFlag = 1;
        }
      }

      console.log(`currTime: ${currTime} `);
      console.log(`prevTime: ${prevTime} `);
      period = (currTime - prevTime) * (8 * Math.pow(10, -6)); //time in s
      result = (period * 1000).toFixed(2);
    }
  }
  pulseWidth.innerHTML = result;
};
