int nClicks;
int pv2;
bool led12On = false;
bool led11On = false;

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


// button
  int v2 = digitalRead(2); //read whatever that is on pin 2 and put in that variable;

  if(v2 == 1 && pv2 == 0) {
    nClicks += 1;
  }

  pv2 = v2; //update the previous value of v2

  // Serial.println("hello"); // print hello and go on to a new line
  Serial.println("v2:" + String(v2) + "count" + String(nClicks));

  // If the button has been pressed 3 times, turn on pin 12
  if (nClicks >= 5 && !led12On) {
    digitalWrite(12, HIGH);  // Turn on pin 12 (LED)
    Serial.println("Pin 12 UNLOCKED!");  // Print message for feedback
    led12On = true;  // Set the LED status to "on"
  }

  delay(100);

// photosensor
  int a0In = analogRead(A0);

  Serial.println(a0In);

if (a0In == 0) {
    digitalWrite(11, HIGH);  // Turn on pin 11 (LED)
    Serial.println("Pin 11 UNLOCKED!");
  } else {
    digitalWrite(11, LOW);  // Turn off pin 11 if the value is not 0
  }

  delay(100);



// rotary
int a1In = analogRead(A1);

  Serial.println(a1In);

  if (a1In >= 1000 && a1In < 2000) {
    digitalWrite(10, HIGH);  // Turn on pin 10 (LED)
    Serial.println("Pin 10 UNLOCKED!");
  } else {
    digitalWrite(10, LOW);  // Turn off pin 10 if the value is less than 1010
  }

  delay(100);


  

}