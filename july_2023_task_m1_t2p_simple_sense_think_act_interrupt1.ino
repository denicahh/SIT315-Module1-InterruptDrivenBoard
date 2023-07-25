// C++ code
//

const int ledPin = 3;
const int PIR = 4;
const int Bttn = 2;
int PIRStateCurrent = LOW;
int PIRStatePrevious = LOW;
uint8_t led_state = HIGH;

  
void setup()
{
  
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(Bttn, INPUT);
  attachInterrupt(digitalPinToInterrupt(Bttn), switchOffLED, RISING);
}

void loop(){
  
  PIRStatePrevious = PIRStateCurrent;
  PIRStateCurrent = digitalRead(PIR);
  
  
  if(PIRStatePrevious == LOW && PIRStateCurrent == HIGH)
{
  Serial.println("Motion Detected!");
  digitalWrite(ledPin, HIGH);
  Serial.println("LED ON");
  delay(10000);
}
  else
  if (PIRStatePrevious == HIGH && PIRStateCurrent == LOW)
  {
    Serial.println("Motion Stopped or Interrupted!");
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF");
  }
  
}
void switchOffLED(){
    led_state = !led_state;
    digitalWrite(ledPin, led_state);
  	Serial.println("Interrupted! LED Switched Off");
    
  }

