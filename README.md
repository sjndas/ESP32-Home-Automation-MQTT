# ESP32 Home Automation using MQTT and Node-RED

## Project Overview
This project implements an IoT-based home automation system using ESP32, MQTT, Node-RED, and a DHT11 sensor for real-time monitoring and appliance control.

## Features
- Temperature monitoring
- Humidity monitoring
- Light control
- Fan control
- Automatic exhaust fan control
- MQTT communication
- Node-RED dashboard visualization
- Real-time status updates

## Components Used
- ESP32
- DHT11 Sensor
- Relay Module
- Wi-Fi Router
- MQTT Broker
- Node-RED Dashboard

## Pin Connections

Device    ESP32 Pin 
---------------------
 1.DHT11----GPIO4    2.Light Relay----GPIO25   3.Fan Relay----GPIO26    4.Exhaust Relay----GPIO27

## MQTT Topics

```text
home/temp
home/hum
home/light
home/fan
home/exhaust
home/light_status
home/fan_status
home/exhaust_status
```

## Software Used

- Arduino IDE
- MQTT
- Node-RED
- ArduinoJson Library
- PubSubClient Library

## Future Improvements

- Mobile application support
- OLED display integration
- Voice control using Alexa or Google Assistant
- Data logging and cloud storage

  ## Libraries Used

* WiFi.h
* PubSubClient.h
* ArduinoJson.h
* DHT.h


## Author

Sajindas M
