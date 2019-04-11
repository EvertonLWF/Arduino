#include <ESP8266WiFi.h>
#include <DHTesp.h>
#include <PubSubClient.h>
const char* ssid = "Rede Academica";
const char* password = "";
WiFiClient NodeMcuClient;
const char* mqtt_Broker = "172.17.15.220";//iot.eclipse.org
PubSubClient client(NodeMcuClient);
const char* topicoTemp = "Feijo/Temp";
const char* topicoUmid = "Feijo/Umid";
const char* topicoTexto = "Feijo/Texto";
const char* mqtt_clientId = "TemperaturaUmidadeFeijo";
DHTesp dht;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 setup_wifi();
 pinMode(BUILTIN_LED, OUTPUT); 
 dht.setup(16,DHTesp::DHT11);
 client.setServer(mqtt_Broker, 1883);
 client.setCallback(callback);
 }

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  if(!client.connected()){
    Reconect();
  }
 // client.loop();
  float temp = dht.getTemperature();
  float humid = dht.getHumidity();
  Serial.print("Temperatura = ");
  Serial.print(temp);
  Serial.print("   Humidade = ");
  Serial.println(humid);
  client.publish(topicoTemp,String(temp).c_str(),true);
  client.publish(topicoUmid,String(humid).c_str(),true);
  client.publish(topicoTexto,"TSI",true);
}
void Reconect(){
  while(!client.connected()){
    client.connect("TemperaturaUmidadeFeijo");
    delay(5000);
  }
}
void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(BUILTIN_LED, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
  } else {
    digitalWrite(BUILTIN_LED, HIGH);  // Turn the LED off by making the voltage HIGH
  }

}

