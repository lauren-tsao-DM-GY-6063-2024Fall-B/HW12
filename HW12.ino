int pv2;  // previous value of pin 2
int nClicks; // number of clicks

bool led12On = false;
bool led11On = false;
bool led10On = false;

void setup() {
  pinMode(12, OUTPUT); // receives messages from Arduino
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(2, INPUT); // sends messages to Arduino

// initiate serial communication between Arduino board and computer
// Serial = allows sending and receiving data to and from Arduino via USB port, typically using the Serial.print(), Serial.println(), Serial.read()
// begin = start serial communication
// 9600 = baud rate (defines the speed the data is transmitted in bits/bauds pr second (bps)), so this is 9600 bps
Serial.begin(9600);

pv2 = 0;
nClicks = 0; 
}


void loop() {

// BUTTON
  int v2 = digitalRead(2); // read input from pin 2 and put it in v2 variable;

  if(v2 == 1 && pv2 == 0) { // if current value of pin 2 is 1 (HIGH)(pressed) and previous value of pin 2 is 0 (LOW)(released)..
    nClicks += 1; // .. increase nClicks counter by 1
  }

  pv2 = v2; // update the previous value of pin 2 (pv2) to current value of pin 2 (v2)

  // print the following line everytime the above is executed
  // "v2:" = title for v2's value (String(v2))
  // String(v2) = converts value of v2 (either 1 or 0 dependant on pin 2's state (HIGH/LOW)) into a string
  // "count" = another title, for number of clicks (String(nClicks))
  // String(nClicks) = converts nClicks into a string
  // so if button is pressed 3 times, it should read as "v2:1count3"
  Serial.println("v2:" + String(v2) + "count" + String(nClicks));

  // if the button has been pressed 5 times, turn on LED on pin 12
  if (nClicks == 5 && !led12On) { // if number of clicks is equals to 5 and LED on pin 12 is not on
    digitalWrite(12, HIGH);  // Turn on LED on pin 12
    Serial.println("Pin 12 UNLOCKED!");  // print "Pin 12 UNLOCKED" as visual feedback
    led12On = true;  // ensure that LED on pin 12 is unlocked only when button is pressed 5 times, and prevents LED from being turned on again from subsequent presses
  }

  delay(100);


// PHOTORESISTOR
  int a0In = analogRead(A0); // read value from analog pin A0..

  Serial.println(a0In); // .. and print it on the Serial Monitor

if (a0In == 0) { // if reading is 0..
    digitalWrite(11, HIGH);  // .. turn on LED on pin 11
    Serial.println("Pin 11 UNLOCKED!"); // print "Pin 11 UNLOCKED" as visual feedback
    led11On = true;
  } else { // otherwise.. 
    led11On = false;  // .. leave LED on pin 11 off
  }

  delay(100);


// ROTARY POTENTIOMETER
int a1In = analogRead(A1); // read value from analog pin A1..

  Serial.println(a1In); // .. and print it on the Serial Monitor

  if (a1In >= 1000 && a1In < 2000) { // if the reading ranges between 1000 and 2000..
    digitalWrite(10, HIGH);  // .. turn on LED on pin 10
    Serial.println("Pin 10 UNLOCKED!");  // print "Pin 10 UNLOCKED" as visual feedback
    led10On = true;
  } else { // otherwise..
    led10On = false;  // .. leave LED on pin 10 off
  }

  delay(100);

//////

 // check if all LEDs on pins 10, 11 and 12 are on 
  if (led12On && led11On && led10On) {
    // blink the LEDs forever
    while (true) {  // creates an infinte loop (because true will always be true) (not related to the 'true' statuses of the pins 10-12) 
      // make all LEDs blink (turn on(HIGH) and off(LOW) at 500ms intervals)
      digitalWrite(12, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(10, HIGH);
      delay(500); 

      digitalWrite(12, LOW);
      digitalWrite(11, LOW);
      digitalWrite(10, LOW);
      delay(500);
    }
  }
}