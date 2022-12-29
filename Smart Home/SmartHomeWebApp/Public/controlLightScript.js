const lightOnBtn = document.querySelector('#light-on-btn');
const lightOnBtnText = document.querySelector('#light-btn-text');
const lightOnBtnBack = document.querySelector('#light-btn-back');
const lightControlOption = document.querySelectorAll('.light-control-option');

const autoLightBtn = document.querySelector('#auto-light-btn');
const autoLightBtnText = document.querySelector('#auto-light-text-btn');
const autoLightBtnBack = document.querySelector('#auto-light-btn-back');

const lightBar = document.querySelector('#intensity-bar-progress');
const incLightBtn = document.querySelector('#plus-light');
const decLightBtn = document.querySelector('#minus-light');
const ligthBarValue = document.querySelector('#light-inten-value');

let currentLightIntensity = lightIIntensityStatus;
let lightStatus = false;
let autoLightStatus = false;

const updateLigthControl = () => {
  lightBar.style.width = currentLightIntensity;
  ligthBarValue.innerHTML = currentLightIntensity;
};
const toggleBtnLight = (btn) => {
  switch (btn) {
    case 'light':
      if (lightStatus !== true) {
        lightOnBtn.style.order = 1;
        lightOnBtnText.innerHTML = 'OFF';
        lightOnBtnText.style.color = '#212c34';
        lightOnBtnBack.style.background = '#faf4f4a2';
        lightControlOption.forEach((el, index) => {
          el.style.opacity = '50%';
          autoLightStatus = false;
        });
      } else {
        lightOnBtn.style.order = 3;
        lightOnBtnText.innerHTML = 'ON';
        lightOnBtnText.style.color = '#faf4f4';
        lightOnBtnBack.style.background =
          'linear-gradient(to left, #da4453, #89216b)';
        lightControlOption.forEach((el, index) => {
          el.style.opacity = '100%';
        });
      }
      break;
    case 'auto-light':
      if (autoLightStatus !== true) {
        autoLightBtn.style.order = 1;
        autoLightBtnText.innerHTML = 'OFF';
        autoLightBtnText.style.color = '#212c34';
        autoLightBtnBack.style.background = '#faf4f4a2';
      } else {
        autoLightBtn.style.order = 3;
        autoLightBtnText.innerHTML = 'ON';
        autoLightBtnText.style.color = '#faf4f4';
        autoLightBtnBack.style.background =
          'linear-gradient(to left, #da4453, #89216b)';
      }
      break;
    default:
      break;
  }
};
// init
toggleBtnLight('light');
toggleBtnLight('auto-light');
updateLigthControl();
const updateLightStatus = () => {
  if (lightStatus) {
    // frame on
  } else {
    // frame off
  }
  toggleBtnLight('light');
  toggleBtnLight('auto-light');
};
lightOnBtn.addEventListener('click', () => {
  lightStatus = !lightStatus;
  updateLightStatus();
});
autoLightBtn.addEventListener('click', () => {
  autoLightStatus = !autoLightStatus;
  toggleBtnLight('auto-light');
  //   frame
});

incLightBtn.addEventListener('click', () => {
  let value = +currentLightIntensity.replace('%', '');
  if (value < 100) {
    value++;
  } else {
    value = 100;
  }
  currentLightIntensity = value + '%';
  //   frame
  updateLigthControl();
});
decLightBtn.addEventListener('click', () => {
  let value = +currentLightIntensity.replace('%', '');
  if (value > 0) {
    value--;
  } else {
    value = 0;
  }
  currentLightIntensity = value + '%';
  //   frame
  updateLigthControl();
});
