// Carl Johan Ståhl & Emil "Henrik" Bergman 2B
// Servo Pos Reader

// https://github.com/users/Saud0227/projects/1

#include <Keyboard.h>



int readPins [8] = {0, 1, 2, 3, 4, 5, 6, 7};


void setup(){
    //Serial.begin(12500);
    // delay(1000);
    pinMode(13, 1);
    Keyboard.begin();
}


int getPos() {
    return(255);
}


void loop(){
    // delay(500);
    // writeOut(1020);
    // delay(500);
}



void writeOut(int toWrite){
    Keyboard.print(toWrite);

}

