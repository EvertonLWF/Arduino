//This example shows how to read and write database rules

//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

//#define WIFI_SSID "Feijo"
#define WIFI_SSID "kitchen_NetWork"
#define WIFI_PASSWORD "renizia62378evej"
#define FIREBASE_HOST "home-c80b6.firebaseio.com" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "a3lxQNIzTzRcmIlqdjvw7kSMAgjmmLs4mufWzFYd"

//Define Firebase Data object
FirebaseData firebaseData;

void setup()
{

  Serial.begin(115200);
  Serial.println();
  Serial.println();

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

void loop()
{
  Firebase.setInt(firebaseData,"/Home/Room/Light",9);
  //Firebase.getInt(firebaseData,"/Home/Front/Light");
  
  Print();
  delay(5000);

    
}

void Print(){
  Serial.println("**********************************************************");
  Serial.print("Room -> Light = ");
  Firebase.getInt(firebaseData,"/Home/Room/Light");
  Serial.println(firebaseData.intData());
  Serial.print("Room -> Ar = ");
  Firebase.getInt(firebaseData,"/Home/Room/Ar");
  Serial.println(firebaseData.intData());
  Serial.print("Garage -> Light = ");
  Firebase.getInt(firebaseData,"/Home/Garage/Light");
  Serial.println(firebaseData.intData());
  Serial.print("Garage -> Gate = ");
  Firebase.getInt(firebaseData,"/Home/Garage/Gate");
  Serial.println(firebaseData.intData());
  Serial.print("Front -> Light = ");
  Firebase.getInt(firebaseData,"/Home/Front/Light");
  Serial.println(firebaseData.intData());
  Serial.print("Kitcken -> Light = ");
  Firebase.getInt(firebaseData,"/Home/Kitcken/Light");
  Serial.println(firebaseData.intData());
  Serial.print("Bathroom -> Light = ");
  Firebase.getInt(firebaseData,"/Home/bathroom/Light");
  Serial.println(firebaseData.intData());
  Serial.print("Bathroom -> Shower = ");
  Firebase.getInt(firebaseData,"/Home/bathroom/Shower");
  Serial.println(firebaseData.intData());
  Serial.print("LivingRoom -> Light = ");
  Firebase.getInt(firebaseData,"/Home/livingRoom/Light");
  Serial.println(firebaseData.intData());
  Serial.print("LivingRoom -> Ar = ");
  Firebase.getInt(firebaseData,"/Home/livingRoom/Ar");
  Serial.println(firebaseData.intData());
  Serial.print("LivingRoom -> Tv = ");
  Firebase.getInt(firebaseData,"/Home/livingRoom/Tv");
  Serial.println(firebaseData.intData());
  Serial.print("Back -> Light = ");
  Firebase.getInt(firebaseData,"/Home/Back/Light");
  Serial.println(firebaseData.intData());
  Serial.print("Back -> Irrigator = ");
  Firebase.getInt(firebaseData,"/Home/Back/irrigator");
  Serial.println(firebaseData.intData());
  Serial.print("Back -> Dog = ");
  Firebase.getInt(firebaseData,"/Home/Back/Dog");
  Serial.println(firebaseData.intData());
  Serial.print("Front -> Light = ");
  Firebase.getInt(firebaseData,"/Home/Front/Light");
  Serial.println(firebaseData.intData());
  Serial.print("Front -> Irrigator = ");
  Firebase.getInt(firebaseData,"/Home/Front/irrigator");
  Serial.println(firebaseData.intData());
  Serial.println("**********************************************************");

}
