# Project Description

## Objective

To develop an IoT-based home automation system using ESP32, MQTT, and Node-RED for real-time monitoring and appliance control.

## Components Used

* ESP32
* DHT11 Sensor
* Relay Module
* Wi-Fi Router
* MQTT Broker
* Node-RED Dashboard

## Features

* Temperature monitoring
* Humidity monitoring
* Light control
* Fan control
* Automatic exhaust fan control
* Real-time status monitoring using MQTT
* Node-RED dashboard visualization

## Software Used

* Arduino IDE
* Node-RED
* MQTT Explorer
* PubSubClient Library
* ArduinoJson Library

## Pin Connections

| Device        | ESP32 Pin |
| ------------- | --------- |
| DHT11         | GPIO4     |
| Light Relay   | GPIO25    |
| Fan Relay     | GPIO26    |
| Exhaust Relay | GPIO27    |

## MQTT Topics

* home/data
* home/light
* home/fan
* home/exhaust_status

## Future Improvements

* Mobile application support
* OLED display integration
* Cloud data logging
* Voice control using Alexa or Google Assistant
