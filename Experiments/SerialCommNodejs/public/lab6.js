const ctx = document.getElementById('myChart');
const startBtn = document.getElementById('startBtn');
const stopBtn = document.getElementById('stopBtn');
let dataOBJ = [];
let pointsCounter = 0;
let lastDataSize = 0;
const myChart = new Chart(ctx, {
  type: 'line',
  options: {
    animation: false,
    resonsive: true,
    elements: {
      point: {
        radius: 0,
      },
    },
    options: {
      aspectRatio: 9,
    },
    scales: {
      y: {
        title: {
          display: true,
          text: 'Ch 1',
        },
        offset: true,
        position: 'left',
        stack: 'demo',
        // stackWeight: 1,
      },
      y1: {
        title: {
          display: true,
          text: 'Ch 2',
        },
        offset: true,
        position: 'left',
        stack: 'demo',
        // stackWeight: 1,
      },
      y2: {
        title: {
          display: true,
          text: 'Ch 3',
        },
        offset: true,
        position: 'left',
        stack: 'demo',
        stackWeight: 1,
      },
      y3: {
        title: {
          display: true,
          text: 'Ch 4',
        },
        offset: true,
        position: 'left',
        stack: 'demo',
        stackWeight: 1,
      },
      y4: {
        title: {
          display: true,
          text: 'Ch 5',
        },
        offset: true,
        position: 'left',
        stack: 'demo',
        stackWeight: 1,
      },
      y5: {
        title: {
          display: true,
          text: 'Ch 6',
        },
        offset: true,
        position: 'left',
        stack: 'demo',
        stackWeight: 1,
      },
      y6: {
        title: {
          display: true,
          text: 'Ch 7',
        },
        offset: true,
        position: 'left',
        stack: 'demo',
        stackWeight: 1,
      },
      y7: {
        title: {
          display: true,
          text: 'Ch 8',
        },
        offset: true,
        position: 'left',
        stack: 'demo',
        stackWeight: 1,
      },
      x: {
        title: {
          display: true,
          text: 'ms',
        },
      },
    },
    plugins: {
      legend: {
        display: false,
      },
      tooltip: {
        enabled: false,
      },
    },
  },
  data: {
    labels: dataOBJ.map((row) => row.time),
    datasets: [
      {
        label: 'Channel 1',
        data: dataOBJ.map((row) => {
          row.value;
        }),
        borderColor: '#2d3436',
        backgroundColor: '#636e72',
        stepped: true,
        yAxisID: 'y',
      },
      {
        label: 'Channel 2',
        data: dataOBJ.map((row) => row.value),
        borderColor: '#2d3436',
        backgroundColor: '#636e72',
        stepped: true,
        yAxisID: 'y1',
      },
      {
        label: 'Channel 3',
        data: dataOBJ.map((row) => row.value),
        borderColor: '#2d3436',
        backgroundColor: '#636e72',
        stepped: true,
        yAxisID: 'y2',
      },
      {
        label: 'Channel 4',
        data: dataOBJ.map((row) => row.value),
        borderColor: '#2d3436',
        backgroundColor: '#636e72',
        stepped: true,
        yAxisID: 'y3',
      },
      {
        label: 'Channel 5',
        data: dataOBJ.map((row) => row.value),
        borderColor: '#2d3436',
        backgroundColor: '#636e72',
        stepped: true,
        yAxisID: 'y4',
      },
      {
        label: 'Channel 6',
        data: dataOBJ.map((row) => row.value),
        borderColor: '#2d3436',
        backgroundColor: '#636e72',
        stepped: true,
        yAxisID: 'y5',
      },
      {
        label: 'Channel 7',
        data: dataOBJ.map((row) => row.value),
        borderColor: '#2d3436',
        backgroundColor: '#636e72',
        stepped: true,
        yAxisID: 'y6',
      },
      {
        label: 'Channel 8',
        data: dataOBJ.map((row) => row.value),
        borderColor: '#2d3436',
        backgroundColor: '#636e72',
        stepped: true,
        yAxisID: 'y7',
      },
    ],
  },
});

function addData(chart, label, data) {
  chart.data.labels.push(label);
  chart.data.datasets.forEach((dataset, index) => {
    if (data[index] > 0) {
      dataset.data.push(1);
    } else {
      dataset.data.push(0);
    }
    myChart.update();
  });
}
function removeData(chart) {
  chart.data.labels.pop();
  chart.data.datasets.forEach((dataset) => {
    dataset.data.pop();
  });
  chart.update();
}
const getDataLogic = (data) => {
  lastDataSize = dataOBJ.length;
  dataOBJ = data;
  calcAvgFreq(dataOBJ);
  calcPulseWidth(dataOBJ);
  calcAvgVolt(dataOBJ);
  calcPeakVolt(dataOBJ);
  for (let index = 0; index < lastDataSize; index++) {
    removeData(myChart);
  }
  for (let index = 0; index < dataOBJ.length - 1; index++) {
    addData(
      myChart,
      (dataOBJ[index].time * (8 * Math.pow(10, -6)) * 1000).toFixed(1),
      dataOBJ[index].value
    );
    //console.log(dataOBJ[index].value);
    //console.log(dataOBJ[index].value[6]);
    // console.log(dataOBJ[index]);
  }
};

const getSamples = () => {
  readLogicData(getDataLogic);
};

startBtn.addEventListener('click', () => {
  sendDataToPort('#D;');
});
stopBtn.addEventListener('click', () => {
  sendDataToPort('#S;');
});

setInterval(function () {
  getSamples();
}, 1000);
