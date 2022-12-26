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
    elements: {
      point: {
        radius: 0,
      },
    },
    scales: {
      y: {
        title: {
          display: true,
          text: 'V/51',
        },
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
        label: 'Signal in time',
        data: dataOBJ.map((row) => row.value),
        borderColor: '#2d3436',
        backgroundColor: '#636e72',
      },
    ],
  },
});

// const plotChart = async () => {};
// (async () => {
//   await plotChart();
// })();
function addData(chart, label, data) {
  chart.data.labels.push(label);
  chart.data.datasets.forEach((dataset) => {
    dataset.data.push(data);
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
const getDataOsc = (data) => {
  lastDataSize = dataOBJ.length;
  dataOBJ = data;
  calcAvgFreqOsc(dataOBJ);
  calcPulseWidthOsc(dataOBJ);
  calcAvgVolt(dataOBJ);
  calcPeakVolt(dataOBJ);
  // myChart.destroy();
  myChart.update();
  for (let index = 0; index < lastDataSize; index++) {
    removeData(myChart);
  }
  for (let index = 0; index < dataOBJ.length; index++) {
    addData(
      myChart,
      (dataOBJ[index].time * (8 * Math.pow(10, -6)) * 1000).toFixed(1),
      dataOBJ[index].value
    );
  }
};
const getSamples = () => {
  readOscData(getDataOsc);
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