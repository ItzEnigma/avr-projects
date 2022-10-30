const connectBtn = document.querySelector("#connectBtn");
const disconnectBtn = document.querySelector("#disconnectBtn");
const refresh = document.querySelector("#refresh");
const sendData = document.querySelector("#sendData");
const writeDataBtn = document.querySelector("#writeDataBtn");
const consolePort = document.querySelector("#consolePort");
const connectContainer = document.querySelector("#connectContainer");
const message = document.querySelector("#message");
const address_write = document.querySelector("#address-write");
const address_read = document.querySelector("#address-read");
const data_write = document.querySelector("#data-write");
const port_list = document.querySelector("#port-list");
const sendAddressRead = document.querySelector("#sendAddressRead");
const fileInput = document.querySelector("#fileInputHex");
const flashHexFile = document.querySelector("#flashHexFile");
const selectMem = document.querySelector("#selectMem");
const selectMemRead = document.querySelector("#selectMemRead");
let codeHex;
let recData = "Empty";
consolePort.innerHTML = recData;
let connected = false;
const url = "http://127.0.0.1:8000";

const connectPort = (port) => {
  let data = JSON.stringify({
    port,
  });
  $.ajax({
    url: `${url}/connect`,
    dataType: "json",
    type: "post",
    contentType: "application/json",
    data,
    processData: false,
  }).done((response) => {
    console.log(response);
    if (response.status === "Success") {
      connectContainer.classList.remove("deactive");
      connectContainer.classList.add("active");
    }
  });
};
const sendDataToPort = (message) => {
  let data = JSON.stringify({
    data: message,
  });
  /* Send Data */
  $.ajax({
    url: `${url}/sendData`,
    dataType: "json",
    type: "post",
    contentType: "application/json",
    data,
    processData: false,
  }).done((response) => {
    console.log(response);
  });
};
const readDataFromPort = () => {
  /* get request to get data*/
  $.ajax({
    url: `${url}/ReadData`,
    type: "GET",
    success: function (res) {
      console.log(res);
      const data = res.data;
      let recData = "";
      if (data != "") {
        console.log("0x" + data);
        recData = "0x" + data;
      }
      consolePort.innerHTML = recData;
    },
  });
};

const disconnect = () => {
  /* get request to close port*/
  $.ajax({
    url: `${url}/disconnect`,
    type: "GET",
    success: function (res) {
      if (res.status === "Success") {
        connectContainer.classList.add("deactive");
        connectContainer.classList.remove("active");
      }
    },
  });
};

connectBtn.addEventListener("click", async () => {
  const port = port_list.value;
  connectPort(port);
});
disconnectBtn.addEventListener("click", () => {
  disconnect();
});

refresh.addEventListener("click", () => {
  readDataFromPort();
});

writeDataBtn.addEventListener("click", () => {
  let data = data_write.value.toUpperCase();
  let address = address_write.value;
  address = address.replace("0x", "").toUpperCase();
  while (address.length < 4) address = "0" + address;
  while (data.length < 2) data = "0" + data;
  const selectedMem = selectMem.value;
  let frame;
  if (selectedMem === "RAM") {
    frame = `#w${address}^${data};`;
  } else {
    frame = `$w${address}^${data};`;
  }
  console.log(frame);
  sendDataToPort(frame);
});

sendAddressRead.addEventListener("click", () => {
  let address = address_read.value;
  address = address.replace("0x", "").toUpperCase();
  while (address.length < 4) address = "0" + address;
  const selectedMem = selectMemRead.value;
  let frame;
  if (selectedMem === "RAM") {
    frame = `#r${address}^z;`;
  } else {
    frame = `$r${address}^z;`;
  }
  console.log(frame);
  sendDataToPort(frame);
  setTimeout(() => {
    readDataFromPort();
  }, 200);
});

/* Flash Hex */
fileInput.addEventListener("change", function () {
  let fr = new FileReader();
  fr.onload = function () {
    codeHex = fr.result;
  };
  fr.readAsText(this.files[0]);
});
flashHexFile.addEventListener("click", () => {
  console.log(codeHex);
  const codeHexArr = codeHex.split(":");
  codeHexArr.shift();
  const codeHexArrNew = codeHexArr.map((el) => {
    let indexLength = 1 * (el.length - 4);
    console.log(indexLength);
    return el.replace("\r\n", "").slice(8, indexLength);
  });

  const hexFile = codeHexArrNew.join("").trim();
  console.log(hexFile);
  sendDataToPort(hexFile);
});
///////////////////////////////
sendData.addEventListener("click", () => {
  const data = message.value;
  sendDataToPort(data);
});
