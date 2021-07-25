#include <Arduino_JSON.h>
#include <ESP8266WiFi.h>
#include "JSONobject.h"
#include "mqtt.h"


int MQTT_PORT = 1883;
char* MQTT_SERVER = "192.168.0.28";//"190.26.36.58";

// struct Node{
//   String uuid;
//   String username;
//   String name;
//   String hostname;
//   String pid;
// };

String testerName = "Kevin";
String clientId = "ESP8266Client-" +  testerName + "-paramo el verjon";

void setup(){
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Proyect has started");

  JSONVar node;
  node["uuid"] = "uuid-"+testerName;
  node["username"] = clientId;
  node["name"] = testerName;
  node["hostname"] = "Node-"+testerName;
  node["pid"] = 12;
	setupObject(node);

  WiFi.begin("No robes we", "@override");
  while (WiFi.status() != WL_CONNECTED){
    delay(400);
    Serial.print(".");
  }
  if(WiFi.status() == WL_CONNECTED){
    setupMqtt(MQTT_SERVER, MQTT_PORT, clientId);
  }

  setMetric("temperature", 1, "C");
  setMetric("humidity", 30, "S");
  setMetric("wind", 90, "m/s");

  // setMetric("temperaturer", 10, "C");
  // setMetric("te", 10, "C");
  // setMetric("teme", 10, "C");
  // setMetric("temture1", 10, "C");
  // setMetric("temture32", 10, "C");
  // setMetric("temture4", 10, "C");
  // setMetric("temture5", 10, "C");
  // setMetric("temture6", 10, "C");
  // setMetric("temture7", 10, "C");
  // setMetric("temture8", 10, "C");
  // setMetric("temture9", 10, "C");
  // setMetric("temture11", 10, "C");
  // setMetric("temture12", 10, "C");
  // setMetric("t1", 10, "C");
  // setMetric("t2", 10, "C");
  // setMetric("t3", 10, "C");
  // setMetric("t4", 10, "C");
  // setMetric("t5", 10, "C");
  // setMetric("t6", 10, "C");
  // setMetric("t7", 10, "C");
  // setMetric("t8", 10, "C");
  // setMetric("t9", 10, "C");
}


void loop(){
  mqttLoop();
  delay(5000);
  sendMessage("node/message", getMessage());
}
