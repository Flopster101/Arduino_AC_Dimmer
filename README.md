# Arduino AC Dimmer

This project is based on this guide: https://circuitspedia.com/remote-control-ac-dimmer-arduino/  
Check it out for extra information.

## Photo of project
![project](https://user-images.githubusercontent.com/50512583/173338249-f9d19033-924f-47cf-8ca8-51359fa337f3.png)

## Components

**1x** **_4N35_** _Optocoupler_  
**1x** **_MOC3201_** _Optotriac_  
**1x** **_BT136_** _Triac_  
**1x** **_0.1nf 103J_** _Capacitor_  
**1x** **_1kΩ_** _Resistor_  
**1x** **_100Ω_** _Resistor_  
**5x** **_10kΩ_** _Resistors_  
**1x** **_HS0038_** _IR Receiver_  
**1x** **_KBU180_** _Full-Bridge rectifier (for zero-crossing side. You might [DEFINITELY] want to get a smaller one instead of this)_  
**1x** **_Passive_** _buzzer or speaker_  

> Optionally, you can also add an LED between 5v and GND, with a 10k resistor in series, like I did. Just for the looks :)  

## Credits
_(Library)_ **IRRemote**: https://github.com/Arduino-IRremote/Arduino-IRremote  
_(Library)_ **TimerFreeTone**: https://forum.arduino.cc/t/timerfreetone-library-v1-5-play-tones-without-timers-and-therefore-no-conflicts/229448  
_(Library)_ **TimerOne**: https://github.com/Arduino-IRremote/Arduino-IRremote/tree/master/examples/SimpleReceiver  
_(Original project)_ **Arduino Remote Control AC Dimmer**: https://circuitspedia.com/remote-control-ac-dimmer-arduino/  
_(Referenced)_ **(SimpleReceiver)**: https://github.com/Arduino-IRremote/Arduino-IRremote/tree/master/examples/SimpleReceiver  
