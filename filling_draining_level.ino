//declear pinout for switches
const int pin1 = 13;
const int pin2 = 12;
const int pin3 = 14;
const int pin4 = 27;
const int pin5 = 26;

//pin for modeswitch 
const int modeSwitchPin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // define pins as input pullup
  pinMode(pin1, INPUT_PULLUP);
  pinMode(pin2, INPUT_PULLUP);
  pinMode(pin3, INPUT_PULLUP);
  pinMode(pin4, INPUT_PULLUP);
  pinMode(pin5, INPUT_PULLUP);
  
  pinMode(modeSwitchPin, INPUT_PULLUP);

  Serial.println("Tank level Monitor");

}

void loop() {
  // put your main code here, to run repeatedly:
  //read the modeSwitch pin
  int modeState = digitalRead(modeSwitchPin);
  bool isFilling = (modeState == HIGH);

  bool s1 = (digitalRead(pin1) == LOW);
  bool s2 = (digitalRead(pin2) == LOW);
  bool s3 = (digitalRead(pin3) == LOW);
  bool s4 = (digitalRead(pin4) == LOW);
  bool s5 = (digitalRead(pin5) == LOW);

  //Get condition on serial monitor
  Serial.print("Mode Switch (GPIO 4):");
  Serial.print(modeState == HIGH ? "OFF [Filling]": "ON[Draining]");

  if (isFilling){
    //while filling
    if (s1 && s2 && s3 && s4 && s5) {
      Serial.println("100% (Full)");
    } else if (s1 && s2 && s3 && s4) {
      Serial.println("90%[cite: 2]");
    } else if (s1 && s2 && s3) {
      Serial.println("70%[cite: 2]");
    } else if (s1 && s2) {
      Serial.println("50%[cite: 2]");
    } else if (s1) {
      Serial.println("30%[cite: 2]");
    } else {
      Serial.println("10%[cite: 2]");
    }
  }
  else{
    //for draining
    Serial.print(" | Level: ");
    
    if (s1 && s2 && s3 && s4 && s5) {
      Serial.println("100% (Full)");
    } else if (s1 && s2 && s3 && s4) {
      Serial.println("80%[cite: 2]");
    } else if (s1 && s2 && s3) {
      Serial.println("60%[cite: 2]");
    } else if (s1 && s2) {
      Serial.println("40%[cite: 2]");
    } else if (s1) {
      Serial.println("20%[cite: 2]");
    } else {
      Serial.println("10%[cite: 2]");
    }
  }
  delay(1000);//check cycle times

}


