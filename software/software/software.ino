// Gauri Prasad, Tim Hoer, Jocelyn Corey
// Finger Tremor Project

int led0 = 0;
int led1 = 1;
int led2 = 2;
int led3 = 3;

int digitalPinIn = 2;
int resetPinIn = 13;

int currRead = 0;
int prevRead = 0;

int count = 0;
boolean changeOccurred = 0;


void setup() {
  Serial.begin(9600);
  computeBits(count);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(resetPinIn, INPUT);
  pinMode(digitalPinIn, INPUT);
  prevRead = digitalRead(digitalPinIn);
}

void loop() {
  
  // read current state
  currRead = digitalRead(digitalPinIn);
  
  // high to low, a finger is passing the photoresistor
  if (!(changeOccurred) && (currRead == 0) && (prevRead == 1)){
    Serial.println("finger passing");
    changeOccurred = 1;
  }

  // low to high, a finger finished passing the photoresistor
  if ((changeOccurred) && (currRead == 1) && (prevRead == 0)){
    Serial.println("finger passed");
    count+=1;
    Serial.println(count);
    computeBits(count);
    changeOccurred = 0;
  }
  
  if ((count == 15) || (digitalRead(resetPinIn) == 0)){
    reset();
  }
  
  prevRead = currRead;
}

void reset(){
  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  count = 0;
}

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

