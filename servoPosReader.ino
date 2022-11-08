// Carl Johan Ståhl & Emil Bergman 2B
// Servo Pos Reader

// https://github.com/users/Saud0227/projects/1

int readPins [8] = {A0, A1, A2, A3, A4, A5, 3, 5};



/*
void setup(){
    Serial.begin(12500);
}


int getPos() {
    return(255);
}


void loop(){
    delay(1);
    getPos();
}


*/

int analog_IN = A0;  // This is our input pin
int digital_OUT = 13;

void setup() { 
    pinMode(digital_OUT, 1);
    pinMode(analog_IN, 0);
    Serial.begin(9600);
  
}

void loop() {
    int outVal = readVal(0);
    Serial.print(outVal);
    if (outVal) {
      digitalWrite(digital_OUT, HIGH);
    }else{
      digitalWrite(digital_OUT, LOW);
    }
}

bool readVal(int iToRead){
    int Value = analogRead(readPins[iToRead]);
    Serial.print("Analog read: ");
    Serial.println(Value);  
    delay(200);
    return (Value < 500);
    
}
