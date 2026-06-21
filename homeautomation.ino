#include<WiFi.h>
#include<PubSubClient.h>
#include<ArduinoJson.h>
#include<DHT.h>
DHT dht(4,DHT11);
const char *ssid="SAJIN";
const char *pswd="Sajindas@550";
int light_pin=25;
int fan_pin=26;
int exhaust_pin=27;
bool exhaustState=false;
float temp = 0;
float hum = 0;


WiFiClient espclient;
PubSubClient client(espclient);

void callback(char *topic, byte *payload,unsigned int length)
{String msg="";
for(int i=0;i<length;i++)
{msg+=(char)payload[i];}
 if(strcmp(topic,"home/light")==0)
{if(msg=="ON")
{digitalWrite(light_pin,HIGH);}
else if(msg=="OFF")
{digitalWrite(light_pin,LOW);}}

else if(strcmp(topic,"home/fan")==0)
{if(msg=="ON")
digitalWrite(fan_pin,HIGH);
else if(msg=="OFF")
digitalWrite(fan_pin,LOW);}}

void SensorTask(void *pvParameters)
{while(1)
 {temp = dht.readTemperature();
  hum = dht.readHumidity();
if (!isnan(temp) && !isnan(hum))
  {StaticJsonDocument<100> doc;
  doc["temp"] = temp;
  doc["hum"] = hum;
  char buffer[100];
  serializeJson(doc, buffer);
  client.publish("home/data", buffer);}
  vTaskDelay(5000/portTICK_PERIOD_MS);}}

void MQTTTask(void *pvParameters)
{while(1)
{if(!client.connected())
{client.connect("ESP32_HOME_AUTOMATION");
client.subscribe("home/light");
client.subscribe("home/fan");}
client.loop();
vTaskDelay(100/portTICK_PERIOD_MS);}}

void ExhaustTask(void *pvParameters)
{while(1)
{if (temp >= 30 && !exhaustState)
{digitalWrite(exhaust_pin, HIGH);
 client.publish("home/exhaust_status", "ON");
 exhaustState = true;}
else if (temp <= 28 && exhaustState)
{digitalWrite(exhaust_pin, LOW);
 client.publish("home/exhaust_status", "OFF");
 exhaustState = false;}
 vTaskDelay(500/portTICK_PERIOD_MS);}}



void setup() {
  Serial.begin(115200);
  pinMode(light_pin,OUTPUT);
  pinMode(fan_pin,OUTPUT);
  pinMode(exhaust_pin,OUTPUT);
  WiFi.begin(ssid,pswd);
    while(WiFi.status()!=WL_CONNECTED)
    {delay(1000);
    Serial.print("connecting....");}
  Serial.println("wifi connected");
  client.setServer("broker.hivemq.com",1883);
  client.setCallback(callback);
  Serial.println("mqtt connected");
  dht.begin();
  xTaskCreatePinnedToCore(MQTTTask,"MQTT Task",4096,NULL,1,NULL,0);
  xTaskCreatePinnedToCore(SensorTask,"Sensor Task",4096,NULL,1,NULL,1);
  xTaskCreatePinnedToCore(ExhaustTask,"Exhaust Task",2048,NULL,1,NULL,1);}

void loop() 
{}
