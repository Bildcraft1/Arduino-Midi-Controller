int val = 0; //Our initial pot values. We need one for the first value and a second to test if there has been a change made. This needs to be done for all 3 pots.
int lastVal = 0;
int buttonApin = 9;
int buttonBpin = 10;
int buttonCpin = 11;
int buttonDpin = 4;
int buttonEpin = 7;
#define BLUE 3
#define GREEN 5
#define RED 6
int velocity = 100; //velocity of MIDI notes, must be between 0 and 127
int noteON = 144; //144 = 10010000 in binary, note on command
int noteOFF = 128; //128 = 10000000 in binary, note off command
int redValue;
int greenValue;
int blueValue;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
  pinMode(buttonCpin, INPUT_PULLUP);
  pinMode(buttonDpin, INPUT_PULLUP);
  pinMode(buttonEpin, INPUT_PULLUP);
  Serial.begin(9600); // Set the speed of the midi port to the same as we will be using in the Hairless Midi software 
}

void loop() {
  #define delayTime 10 // fading time between colors

  redValue = 255; // choose a value between 1 and 255 to change the color.
  greenValue = 0;
  blueValue = 0;

  // this is unnecessary as we've either turned on RED in SETUP
  // or in the previous loop ... regardless, this turns RED off
  // analogWrite(RED, 0);
  // delay(1000);

  for (int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
  {
    redValue -= 1;
    greenValue += 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(RED, 255 - redValue);
    // analogWrite(GREEN, 255 - greenValue);
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for (int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
  {
    greenValue -= 1;
    blueValue += 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(GREEN, 255 - greenValue);
    // analogWrite(BLUE, 255 - blueValue);
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 0;
  blueValue = 255;

  for (int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
  {
    // The following code has been rearranged to match the other two similar sections
    blueValue -= 1;
    redValue += 1;
    // The following was reversed, counting in the wrong directions
    // analogWrite(BLUE, 255 - blueValue);
    // analogWrite(RED, 255 - redValue);
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    delay(delayTime);
  }
  val = analogRead(0) / 8; // Divide by 8 to get range of 0-127 for midi
  if (val != lastVal) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
  {
    MIDImessage(176, 1, val);
  } // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
  lastVal = val;

  if (digitalRead(buttonApin) == LOW) {
    MIDImessage(noteON, 36, velocity); //turn note on
    delay(1000); //hold note for 300ms
    MIDImessage(noteOFF, 36, velocity); //turn note off
  }

  if (digitalRead(buttonBpin) == LOW) {
    MIDImessage(noteON, 38, velocity); //turn note on
    delay(1000); //hold note for 300ms
    MIDImessage(noteOFF, 38, velocity); //turn note off
  }

  if (digitalRead(buttonCpin) == LOW) {
    MIDImessage(noteON, 40, velocity); //turn note off
    delay(1000); //hold note for 300ms
    MIDImessage(noteOFF, 40, velocity); //turn note off
  }

  if (digitalRead(buttonDpin) == LOW) {
    MIDImessage(noteON, 41, velocity); //turn note off
    delay(1000); //hold note for 300ms
    MIDImessage(noteOFF, 41, velocity); //turn note off
  }

  if (digitalRead(buttonEpin) == LOW) {
    MIDImessage(noteON, 43, velocity); //turn note off
    delay(1000); //hold note for 300ms
    MIDImessage(noteOFF, 43, velocity); //turn note off
  }

  delay(2);
}

void MIDImessage(byte command, byte data1, byte data2) //pass values out through standard Midi Command
{
  Serial.write(command);
  Serial.write(data1);
  Serial.write(data2);
}
