#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

// Set WiFi
const char* ssid = "WISMA DAHLIA";
const char* password = "dahlia1A";

// Set Pin Lampu
const int ledDapur = 5;   // D1
const int ledKamar = 4;   // D2
const int ledRT = 0;      // D3
const int ledGarasi = 2;  // D4

// State Lampu
bool ledDapurState = false;
bool ledKamarState = false;
bool ledRTState = false;
bool ledGarasiState = false;

void setup() {
  Serial.begin(9600);

  // Inisialisasi Pin
  pinMode(ledDapur, OUTPUT);
  pinMode(ledKamar, OUTPUT);
  pinMode(ledRT, OUTPUT);
  pinMode(ledGarasi, OUTPUT);

  // Set semua lampu ke LOW
  digitalWrite(ledDapur, LOW);
  digitalWrite(ledKamar, LOW);
  digitalWrite(ledRT, LOW);
  digitalWrite(ledGarasi, LOW);

  // Hubungkan ke WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Rute HTTP GET dan POST
  server.on("/Dapur", HTTP_GET, getDapurLed);
  server.on("/Kamar", HTTP_GET, getKamarLed);
  server.on("/RT", HTTP_GET, getRTLed);
  server.on("/Garasi", HTTP_GET, getGarasiLed);

  server.on("/Dapur", HTTP_POST, setDapurLed);
  server.on("/Kamar", HTTP_POST, setKamarLed);
  server.on("/RT", HTTP_POST, setRTLed);
  server.on("/Garasi", HTTP_POST, setGarasiLed);

  // Mulai server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

// Function Set
void setDapurLed() {
  ledDapurState = !ledDapurState;
  digitalWrite(ledDapur, ledDapurState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledDapurState ? "ON" : "OFF");
}

void setKamarLed() {
  ledKamarState = !ledKamarState;
  digitalWrite(ledKamar, ledKamarState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledKamarState ? "ON" : "OFF");
}

void setRTLed() {
  ledRTState = !ledRTState;
  digitalWrite(ledRT, ledRTState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledRTState ? "ON" : "OFF");
}

void setGarasiLed() {
  ledGarasiState = !ledGarasiState;
  digitalWrite(ledGarasi, ledGarasiState ? HIGH : LOW);
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledGarasiState ? "ON" : "OFF");
}

// Function Get
void getDapurLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledDapurState ? "ON" : "OFF");
}

void getKamarLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledKamarState ? "ON" : "OFF");
}

void getRTLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledRTState ? "ON" : "OFF");
}

void getGarasiLed() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "text/plain", ledGarasiState ? "ON" : "OFF");
}
