// Gauri Prasad, Tim Hoer, Jocelyn Corey
// Finger Tremor Project

int led0 = 2;
int led1 = 4;
int led2 = 6;
int led3 = 8;

int digitalPinIn = 10;
//int resetPinIn = 12;

int currRead = 0;
int prevRead = 0;
int resetRead = -1;

int count = 0;
boolean changeOccurred = 0;

void setup() {
  Serial.begin(9600);
  computeBits(count);
  pinMode(led0, OUTPUT); // green
  pinMode(led1, OUTPUT); // orange
  pinMode(led2, OUTPUT); // red
  pinMode(led3, OUTPUT); // yellow
//  pinMode(resetPinIn, INPUT);
  pinMode(digitalPinIn, INPUT);
  prevRead = digitalRead(digitalPinIn);
}

void loop() {
  // read current state
  currRead = digitalRead(digitalPinIn);
//  resetRead = digitalRead(resetPinIn);
//  Serial.println(resetRead);
//  Serial.println(currRead);
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
  
  if (count == 16){
    backToOne();
  }

  prevRead = currRead;
  delay(50);
}

void backToOne(){
  digitalWrite(led0, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  count = 1;
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

