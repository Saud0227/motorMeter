// Carl Johan Ståhl & Emil "Henrik" Bergman 2B
// motor Pos Reader

// https://github.com/users/Saud0227/projects/1

#include <Keyboard.h>

#define PIEZO_PORT 7
#define BUTTON_IN 3

int readPins[8] = {A0, A1, A2, A3, A4, A5, 4, 5};

// <Rick roll section>

volatile int beatLength = 100; // determines tempo
float beatSeparationConstant = 0.3;

#define a4f 415 // 415 Hz
#define b4f 466 // 466 Hz
#define c5 523  // 523 Hz
#define c5s 554 // 554 Hz
#define e5f 622 // 622 Hz
#define f5 698  // 698 Hz
#define a5f 831 // 831 Hz
#define rest -1

int songNotes[] =
    {b4f, b4f, a4f, a4f,
     f5, f5, e5f, b4f, b4f, a4f, a4f, e5f, e5f, c5s, c5, b4f,
     c5s, c5s, c5s, c5s,
     c5s, e5f, c5, b4f, a4f, a4f, a4f, e5f, c5s,
     b4f, b4f, a4f, a4f,
     f5, f5, e5f, b4f, b4f, a4f, a4f, a5f, c5, c5s, c5, b4f,
     c5s, c5s, c5s, c5s,
     c5s, e5f, c5, b4f, a4f, rest, a4f, e5f, c5s, rest};

int songTime[] =
    {1, 1, 1, 1,
     3, 3, 6, 1, 1, 1, 1, 3, 3, 3, 1, 2,
     1, 1, 1, 1,
     3, 3, 3, 1, 2, 2, 2, 4, 8,
     1, 1, 1, 1,
     3, 3, 6, 1, 1, 1, 1, 3, 3, 3, 1, 2,
     1, 1, 1, 1,
     3, 3, 3, 1, 2, 2, 2, 4, 8, 4};

// <!Rick roll section>


void setup(){
    pinMode(PIEZO_PORT, 1);
    pinMode(BUTTON_IN, 0);
    Serial.begin(12500);
    delay(1000);
    // pinMode(13, 1);
    Keyboard.begin();
}

bool buttonPressed(){
    // IN:  buttonpin
    // OUT: boolean
    // DO: determines if the action-button is pressed
    return digitalRead(BUTTON_IN) == 1;
}

bool readVal(int iToRead){
    // IN:  iToRead
    // OUT: returns if the color is white or black
    // DO:  determines the resistance of the LDR-modules

    int Value = analogRead(readPins[iToRead]);
    // Serial.print("Analog read: ");
    // Serial.println(Value);
    return (Value < 100);
}

int getPos(){
    // IN:  No params in the function but uses the length of the global array in addition as the helper function readVal.
    // OUT: Integer between 0-255-
    // DO:  Reads every part of the greycode like an binary number and generates an val
    byte outCode = 0;
    for (byte i = 0; i < 8; i++){
        byte iVal = readVal(i) * 1;
        Serial.print(iVal);
        outCode += getPowTwo((7 - i)) * iVal;
    }



    delay(200);
    Serial.print("\n");
    return (outCode);
}

void writeOut(int toWrite){
    // IN:  String to type in the computer.
    // OUT: Nothing, void function.
    // DO:  Writes the string 
    Keyboard.print(toWrite);
}

void rick(){
    // IN:  Nothing
    // OUT: Nothing, void function.
    // DO:  Halts execution to rick roll everyone


    int cTime = 0;
    // Serial.print("!");
    while (cTime <= sizeof(songNotes) / sizeof(int)){
        // Serial.print(cTime);

        int noteLength = beatLength * songTime[cTime];
        // chorus

        if (songNotes[cTime] > 0){
            tone(PIEZO_PORT, songNotes[cTime], noteLength);
        }
        delay(noteLength);
        noTone(PIEZO_PORT);
        delay(noteLength * beatSeparationConstant);
        cTime++;
    }
}



void loop(){
    while (true){

        if (!buttonPressed()){
            break;
        }

        Serial.print(getPos());
        Serial.print("\n");

        tone(PIEZO_PORT, 1000);
        delay(250);
        noTone(PIEZO_PORT);
        delay(250);
    }
    // delay(500);
    // writeOut(1020);
    // delay(500);


    // rick();
}



int getPowTwo(int exp){
    if(exp == 0){
        return(1);
    }
    int out = 1;
    for (byte i = 0; i < exp; i++){
        out *= 2;
    }
    return(out);
}