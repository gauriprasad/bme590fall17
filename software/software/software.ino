// Gauri Prasad, Tim Hoer, Jocelyn Corey
// Finger Tremor Project

int led0 = 0;
int led1 = 1;
int led2 = 2;
int led3 = 3;

int digitalPinIn = 8;
int currRead = 0;
int prevRead = 0;

int count = 0;
boolean changeOccured = 0;


void setup() {
  Serial.begin(9600);
  computeBits(count);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(digitalPinIn, INPUT);
  preRead = digitaRead(digitalPinIn);
}

void loop() {
  
//  if something is true, then 
//  count+=1
// change LED state



}

// Compute Bits for 
void computeBits(int c){
  boolean bit0 = bitRead(c,0);
  changeLEDState(bit0, led0);
  boolean bit1 = bitRead(c,1);
  changeLEDState(bit1, led1);
  boolean bit2 = bitRead(c,2);
  changeLEDState(bit2, led2);
  boolean bit3 = bitRead(c,3);
  changeLEDState(bit3, led3);
}

void changeLEDState(boolean bitValue, int LEDNum){
  if (bitValue){
    digitalWrite(LEDNum, HIGH);
  }
  else{
    digitalWrite(LEDNum, LOW);
  }
}

