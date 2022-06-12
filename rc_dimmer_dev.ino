// Remote Control AC dimmer v1.0 for Arduino by Flopster101
// Project based on https://circuitspedia.com/remote-control-ac-dimmer-arduino/

#include <IRremote.hpp>
#define SEND_PWM_BY_TIMER
#include <TimerFreeTone.h>
#define TONE_PIN 3
#define TONE_RESPONSE_ENABLE 1  // Set to 0 for disabling beeps on button presses.

#define IR_RECEIVE_PIN 4


#include <TimerOne.h>           
volatile int i=0;               // Variable to use as a counter
volatile boolean zero_cross=0;  // Boolean to store a "switch" to tell us if we have crossed zero
volatile boolean power_bool=1;
boolean tone_enabled=TONE_RESPONSE_ENABLE;

int AC_pin = 5;                 // Output to Opto Triac
int last_dim = 101;
int is_first_dim = 1;

int dim2 = 0;                   // led control
int dim = 101;                  // Dimming level (0-128)  101 = nearly off, 68 = on  // For some reason the values are inverted
int freqStep = 75;    // This is the delay-per-brightness step in microseconds.

void setup() {   
  // Start the receiver and if not 3. parameter specified, take LED_BUILTIN pin from the internal boards definition as default feedback LED
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(AC_pin, OUTPUT);                          // Set the Triac pin as output
  attachInterrupt(0, zero_cross_detect, RISING);    // Attach an Interupt to Pin 2 (interupt 0) for Zero Cross Detection
  Timer1.initialize(freqStep);                      // Initialize TimerOne library for the freq we need
  Timer1.attachInterrupt(dim_check, freqStep);      
  Serial.begin(9600);
  // Just to know which program is running on my Arduino
  Serial.println(F("START Remote Control Dimmer v1.0 by Flopster101 \r\nUsing IRRemote library version " VERSION_IRREMOTE));
}

void dim_value_print() // Read current dim value and print to serial console.
{
Serial.println("Dim value:");
Serial.println(dim);
}

void zero_cross_detect() 
{    
  zero_cross = true;               // set the boolean to true to tell our dimming function that a zero cross has occured
  i=0;
  digitalWrite(AC_pin, LOW);
}                                 
// Turn on the TRIAC at the appropriate time

void dim_check() 
{                   
  if(zero_cross == true) {              
    if(i>=dim) {                     
      digitalWrite(AC_pin, HIGH);  // turn on light       
      i=0;  // reset time step counter                         
      zero_cross=false;    // reset zero cross detection
    } 
    else {
      i++;  // increment time step counter                     
}}}                                      


void translateIR() // takes action based on IR code received
{
  switch(IrReceiver.decodedIRData.decodedRawData)
  {
  case 0xF6097708: // Vol down button on remote
    {
    Serial.println("Received! (-)");
    dim_value_print();
    if (tone_enabled == true)
    {
      TimerFreeTone(TONE_PIN, 1760, 15);
    }
    if (dim<100)  
   {
    dim = dim + 5;
    if (dim>102) 
    {
      dim=100; // in vechiul sketch era 127
    }
    }}
    
    break;

  case 0xFD027708: // Vol up button on remote
    {
    Serial.println("Received! (+)");
    dim_value_print();
    if (tone_enabled == true)
    {
    TimerFreeTone(TONE_PIN, 2093, 15);
    }
      {
  if (dim>69)  
  {
     dim = dim - 5;
  if (dim<68) 
    {
      dim=68;  // in vechiul sketch era 1
    } }}}
    break;

  case 0xF40B7708: // Power button on remote
    {
    Serial.println("Received! (ON/OFF)");
    if (tone_enabled == true) {
      TimerFreeTone(TONE_PIN, 987, 15);
    }
       if(power_bool == true)
        {
          Serial.println("Power OFF");
          power_bool=0;
          last_dim = dim;
          if (is_first_dim=1) {
            dim=100;
            is_first_dim=0;
          }
          dim=103;
          dim_value_print();
        }
       else {
          Serial.println("Power ON");
          power_bool=1;
          dim=last_dim;
          dim_value_print();
       }
    }
    break;
  case 0xE51A7708: // Exit button on remote
    {
      Serial.println("Received! (Exit/RESET)");
      if (tone_enabled == true) {
        TimerFreeTone(TONE_PIN, 1046, 15);
        delay(50);
        TimerFreeTone(TONE_PIN, 1046, 15);
      }
      last_dim=101;
      dim=101;
      dim_value_print();
    }
    break;
  case 0xFE017708: // Info button on remote, used as mute.
    {
      Serial.println("Received! (Info/Mute)");
      if (tone_enabled == true) {
        tone_enabled=0;
      }
      else if (tone_enabled == false) {
        tone_enabled=1;
        TimerFreeTone(TONE_PIN, 987, 15);
        delay(50);
        TimerFreeTone(TONE_PIN, 987, 15);
      }
    }
  }
}

void loop() {  
 if (IrReceiver.decode()) { // have we received an IR signal?
    translateIR();
    delay(100);
    IrReceiver.resume(); // Enable receiving of the next value
 }
}
