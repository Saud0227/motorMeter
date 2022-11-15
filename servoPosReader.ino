// Carl Johan Ståhl & Emil "Henrik" Bergman 2B
// Servo Pos Reader

// https://github.com/users/Saud0227/projects/1

#include <Keyboard.h>

int readPins [8] = {A0, A1, A2, A3, A4, A5, 3, 5};

int analog_IN = A0;  // This is our input pin

void setup() {
    pinMode(analog_IN, 0);
    Serial.begin(12500);
    delay(1000);
    // pinMode(13, 1);
    Keyboard.begin();
}

void loop() {
    // delay(500);
    // writeOut(1020);
    // delay(500);

    // int outVal = readVal(0);
    // Serial.print(outVal);
    // if (outVal) {
    //   digitalWrite(13, 1);
    // }else{
    //   digitalWrite(13, 1);
    // }
}



bool readVal(int iToRead){
    int Value = analogRead(readPins[iToRead]);
    Serial.print("Analog read: ");
    Serial.println(Value);
    delay(200);
    return (Value < 500);
}

int getPos() {

    // test if line 49 gives a binary 0 1 or a bool
    byte outCode = 0;
    for (byte i = 0; i < 8; i++){
        Serial.print(readVal(i)*1);
    }
}



void writeOut(int toWrite){
    Keyboard.print(toWrite);

}
