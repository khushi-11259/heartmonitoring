# Smart Pulse Oximeter with Real-Time Web Monitoring

## Overview

This project is a pulse oximeter system built using Arduino and the MAX30100 sensor. It measures heart rate and SpO₂ levels and uploads the data to ThingSpeak, where it can be viewed in real-time through graphs on a web/mobile interface.

## Features

* Real-time heart rate (BPM) monitoring
* SpO₂ (blood oxygen level) measurement
* Live data visualization on ThingSpeak
* Accessible from mobile or desktop browser
* Serial Monitor output for debugging

## Components Used

* Arduino board
* MAX30100 Pulse Oximeter Sensor
* ESP8266 WiFi module
* wires

## How It Works

The MAX30100 sensor collects pulse and oxygen data from the user. Arduino processes this data and sends it to ThingSpeak via the ESP8266 module. The platform displays the readings as live graphs, which can be accessed anytime using a browser.

## Setup

1. Connect MAX30100 sensor to Arduino
2. Connect ESP8266 for internet access
3. Add WiFi credentials and ThingSpeak Write API Key in code
4. Upload code using Arduino IDE
5. Open ThingSpeak channel to view live data

## Output

* Field 1 → Heart Rate
* Field 2 → SpO₂
* Graphs available on ThingSpeak dashboard (mobile + web)

## Author

Khushi Gupta
Vedant Garthe 
Garv Saxena
Abhijeet Verma 
