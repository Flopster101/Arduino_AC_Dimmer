# Arduino AC Dimmer

This project is based on this guide: https://circuitspedia.com/remote-control-ac-dimmer-arduino/  
Check it out for extra information.

## Photo
![project](https://user-images.githubusercontent.com/50512583/173338249-f9d19033-924f-47cf-8ca8-51359fa337f3.png)
> It's a mess, isn't it?

## Schematic
![rc_dimmer_arduino_esquemático](https://user-images.githubusercontent.com/50512583/173363683-739a890d-da57-4296-9655-e194628bc8ef.png)
> Far from being a good schematic, but it'll do.

## Remote Button Layout
![project_remote](https://user-images.githubusercontent.com/50512583/173350540-67a08f2e-c302-44b1-b848-d2fbddbd6b16.png)
> There is dedicated MUTE button, but I decided to use the Info button for easier access.  
> Feel free to reprogram this project to use whatever remote you have. It can be easily done with the help of SimpleReceiver.


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
