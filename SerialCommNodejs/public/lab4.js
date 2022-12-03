// Lab 4
const selectWave = document.querySelector("#selectWave");
const Freq = document.querySelector("#Freq");
const Amplitude = document.querySelector("#Amplitude");
const generateBtn = document.querySelector("#generateBtn");
const stopBtn = document.querySelector("#stopBtn");
generateBtn.addEventListener("click", () => {
  const waveID = +selectWave.value - 1;
  const waveFreq = +Freq.value;
  const waveAmp = +Amplitude.value;
  const frame = `#${waveID}${waveFreq}${waveAmp}$`;
  console.log(frame);
  sendDataToPort(frame);
});

stopBtn.addEventListener("click", () => {
  const frame = `#${5}${String.fromCharCode(0)}${0}$`;
  sendDataToPort(frame);
});
