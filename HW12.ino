int nClicks;
int pv2;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(2, INPUT); // Doesn't put out any energy on the pin

Serial.begin(9600);

pv2 = 0;
nClicks = 0;
}

// the loop function runs over and over again forever
void loop() {
  // digitalWrite(12, HIGH);  // turn the LED on (HIGH is the voltage level)   
  // digitalWrite(11, HIGH);  // turn the LED on (HIGH is the voltage level)
  // digitalWrite(10, HIGH);  // turn the LED on (HIGH is the voltage level)


// button
  int v2 = digitalRead(2); //read whatever that is on pin 2 and put in that variable;

  if(v2 == 1 && pv2 == 0) {
    nClicks += 1;
  }

  pv2 = v2; //update the previous value of v2

  // Serial.println("hello"); // print hello and go on to a new line
  Serial.println("v2:" + String(v2) + "count" + String(nClicks));

  delay(1);

// photosensor
  int a0In = analogRead(A0);

  Serial.println(a0In);

  delay(100);



// rotary
int a1In = analogRead(A1);

  Serial.println(a1In);

  delay(100);


  

}