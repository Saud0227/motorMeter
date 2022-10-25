// Carl Johan Ståhl & Emil Bergman 2B
// Servo Pos Reader

// https://github.com/users/Saud0227/projects/1

int readPins [8] = {0, 1, 2, 3, 4, 5, 6, 7};




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