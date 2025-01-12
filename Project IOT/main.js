const endpoint = "http://192.168.1.13";

// get function
function getDapurLed() {
  fetch(endpoint + "/Dapur")
    .then((response) => response.text())
    .then((result) => {
      let ket;
      if (result == "ON") {
        ledDapur.style.backgroundColor = "green";
        ket = "TURN ON";
        ledImageDapur.src = "./assets/led-on.png";
      } else {
        ledDapur.style.backgroundColor = "red";
        ket = "TURN OFF";
        ledImageDapur.src = "./assets/led-off.png";
      }
      ledDapur.innerHTML = ket;
    });
}

function getKamarLed() {
  fetch(endpoint + "/Kamar")
    .then((response) => response.text())
    .then((result) => {
      let ket;
      if (result == "ON") {
        ledKamar.style.backgroundColor = "green";
        ket = "TURN ON";
        ledImageKamar.src = "./assets/led-on.png";
      } else {
        ledKamar.style.backgroundColor = "red";
        ket = "TURN OFF";
        ledImageKamar.src = "./assets/led-off.png";
      }
      ledKamar.innerHTML = ket;
    });
}

function getRTLed() {
  fetch(endpoint + "/RT")
    .then((response) => response.text())
    .then((result) => {
      let ket;
      if (result == "ON") {
        ledRuangTamu.style.backgroundColor = "green";
        ket = "TURN ON";
        ledImageRT.src = "./assets/led-on.png";
      } else {
        ledRuangTamu.style.backgroundColor = "red";
        ket = "TURN OFF";
        ledImageRT.src = "./assets/led-off.png";
      }
      ledRuangTamu.innerHTML = ket;
    });
}

function getGarasiLed() {
  fetch(endpoint + "/Garasi")
    .then((response) => response.text())
    .then((result) => {
      let ket;
      if (result == "ON") {
        ledGarasi.style.backgroundColor = "green";
        ket = "TURN ON";
        ledImageGarasi.src = "./assets/led-on.png";
      } else {
        ledGarasi.style.backgroundColor = "red";
        ket = "TURN OFF";
        ledImageGarasi.src = "./assets/led-off.png";
      }
      ledGarasi.innerHTML = ket;
    });
}

// set function
function setDapurLed() {
  fetch(endpoint + "/Dapur", {
    method: "POST",
  })
    .then((response) => response.text())
    .then((result) => {
      console.log("Dapur LED Status: " + result);
      getDapurLed();
    });
}

function setKamarLed() {
  fetch(endpoint + "/Kamar", {
    method: "POST",
  })
    .then((response) => response.text())
    .then((result) => {
      console.log("Kamar LED Status: " + result);
      getKamarLed();
    });
}

function setRTLed() {
  fetch(endpoint + "/RT", {
    method: "POST",
  })
    .then((response) => response.text())
    .then((result) => {
      console.log("RT LED Status: " + result);
      getRTLed();
    });
}

function setGarasiLed() {
  fetch(endpoint + "/Garasi", {
    method: "POST",
  })
    .then((response) => response.text())
    .then((result) => {
      console.log("Garasi LED Status: " + result);
      getGarasiLed();
    });
}

getDapurLed();
getKamarLed();
getRTLed();
getGarasiLed();
