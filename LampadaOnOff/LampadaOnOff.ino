 #include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "dht-11-14408.firebaseio.com"
#define FIREBASE_AUTH "gk28yKKVABIkUeOkYvZTDrcuPFrLe3AhZ9Z1ZrB8"
#define WIFI_SSID "TP-LINK_C860"
#define WIFI_PASSWORD "56360202"

FirebaseData firebaseData;

void setup()
{
  pinMode(D5, OUTPUT);
  Serial.begin(115200);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Firebase.setInt(firebaseData, path + "/Int/Data" + (i + 1), (i + 1) * 10)) 
  //Firebase.getInt(firebaseData, path + "/Int/Data" + (i + 1)))
  //Firebase.pushInt(firebaseData, path + "/Push/Int", (i + 1)))
   
}

void loop()
{


  if(WiFi.status() != WL_CONNECTED){
    
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
      Serial.print(".");
      delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();
  
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);
  }  
    Firebase.getInt(firebaseData,"dht11/lamp/");
    int lamp = (firebaseData.intData());
    if(lamp == 1){
      digitalWrite(D5, HIGH);
    }else{
      digitalWrite(D5, LOW);

    }
    Serial.println(lamp);
}
