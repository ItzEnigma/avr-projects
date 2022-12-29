const DoorOnBtn = document.querySelector('#door-control-btn');
const DoorOnBtnText = document.querySelector('#door-control-text-btn');
const DoorOnBtnBack = document.querySelector('#door-control-back');

const DeviceOnBtn = document.querySelector('#device-control-btn');
const DeviceOnBtnText = document.querySelector('#device-control-text-btn');
const DeviceOnBtnBack = document.querySelector('#device-control-back');

const MicOnBtn = document.querySelector('#mic-btn-id');
const VoiceValueElem = document.querySelector('.voice-output');

let currentDoorStatus = false;
let currentDeviceStatus = false;

const toggleSideBtn = (btn) => {
  switch (btn) {
    case 'door':
      if (currentDoorStatus !== true) {
        DoorOnBtn.style.order = 1;
        DoorOnBtnText.innerHTML = 'OFF';
        DoorOnBtnText.style.color = '#212c34';
        DoorOnBtnBack.style.background = '#faf4f4a2';
      } else {
        DoorOnBtn.style.order = 3;
        DoorOnBtnText.innerHTML = 'ON';
        DoorOnBtnText.style.color = '#faf4f4';
        DoorOnBtnBack.style.background =
          'linear-gradient(to left, #da4453, #89216b)';
      }
      break;
    case 'device':
      if (currentDeviceStatus !== true) {
        DeviceOnBtn.style.order = 1;
        DeviceOnBtnText.innerHTML = 'OFF';
        DeviceOnBtnText.style.color = '#212c34';
        DeviceOnBtnBack.style.background = '#faf4f4a2';
      } else {
        DeviceOnBtn.style.order = 3;
        DeviceOnBtnText.innerHTML = 'ON';
        DeviceOnBtnText.style.color = '#faf4f4';
        DeviceOnBtnBack.style.background =
          'linear-gradient(to left, #da4453, #89216b)';
      }
      break;
    default:
      break;
  }
};
toggleSideBtn('door');
toggleSideBtn('device');

const updateDoorStatus = (doorStatus) => {
  if (doorStatus) {
    // frame on
  } else {
    // frame off
  }
  toggleSideBtn('door');
};
const updateDeviceStatus = (deviceStatus) => {
  if (deviceStatus) {
    // frame on
  } else {
    // frame off
  }
  toggleSideBtn('device');
};
DoorOnBtn.addEventListener('click', () => {
  currentDoorStatus = !currentDoorStatus;
  updateDoorStatus(currentDoorStatus);
});
DeviceOnBtn.addEventListener('click', () => {
  currentDeviceStatus = !currentDeviceStatus;
  updateDeviceStatus(currentDeviceStatus);
});
MicOnBtn.addEventListener('click', () => {
  MicOnBtn.classList.remove('mic-btn');
  MicOnBtn.classList.add('mic-btn-active');
  const SpeechRecognition =
    window.SpeechRecognition || window.webkitSpeechRecognition;

  let recognition = new SpeechRecognition();

  recognition.onstart = () => {
    console.log('starting listening, speak in microphone');
  };
  recognition.onspeechend = () => {
    console.log('stopped listening');
    recognition.stop();
  };
  recognition.onresult = (result) => {
    let value = result.results[0][0].transcript;
    VoiceValueElem.innerHTML = value + '..';
    MicOnBtn.classList.remove('mic-btn-active');
    MicOnBtn.classList.add('mic-btn');
    if (value === 'turn on device') {
      currentDeviceStatus = true;
      updateDeviceStatus(currentDeviceStatus);
    } else if (value === 'turn off device') {
      currentDeviceStatus = false;
      updateDeviceStatus(currentDeviceStatus);
    } else if (value === 'open door') {
      currentDoorStatus = true;
      updateDoorStatus(currentDoorStatus);
    } else if (value === 'close door') {
      currentDoorStatus = false;
      updateDoorStatus(currentDoorStatus);
    } else if (value === 'turn on lights') {
      lightStatus = true;
      updateLightStatus();
    } else if (value === 'turn off lights') {
      lightStatus = false;
      updateLightStatus();
    } else if (value === 'turn on fan') {
      fanStatus = true;
      updateFandStatus();
    } else if (value === 'turn off fan') {
      fanStatus = false;
      updateFandStatus();
    }
    // sende frame
    speak('Okay');
    setTimeout(() => {
      VoiceValueElem.innerHTML = 'Say Something..';
    }, 1000);
  };
  recognition.start();
});

function setSpeech() {
  return new Promise(function (resolve, reject) {
    let synth = window.speechSynthesis;
    let id;

    id = setInterval(() => {
      if (synth.getVoices().length !== 0) {
        resolve(synth.getVoices());
        clearInterval(id);
      }
    }, 10);
  });
}

function speak(text) {
  var utterance = new SpeechSynthesisUtterance(text);
  let s = setSpeech();
  s.then((voices) => {
    utterance.voice = voices[3];
    speechSynthesis.speak(utterance);
  });
}
