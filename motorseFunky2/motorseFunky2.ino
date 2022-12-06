//byte array of pinOuts
byte pinOut[] = {
  1, 2, 3, 4,
  5, 6, 7, 8, 
  9, 10, 11, 12
};// = 12

int interval = 64;
unsigned long lastMs = 0;
byte tempRand = 0;
byte baseMin = 240;
byte baseAdd = 15;
boolean pinType = false;
byte mainCount = 0;

//Counters for functions
byte kCounter = 0;
byte aCounter = 0;
byte tCounter = 0;
byte iCounter = 0;
byte eCounter = 0;
byte kCounter2 = 0;
byte rCounter = 0;
byte oCounter = 0;
byte kCounter3 = 0;
byte oCounter2 = 0;
byte num8Counter = 0;
byte num7Counter = 0;

//booleans for motor toggles
boolean kState = false;
boolean aState = false;
boolean tState = false;
boolean iState = false;
boolean eState = false;
boolean kState2 = false;
boolean rState = false;
boolean oState = false;
boolean kState3 = false;
boolean oState2 = false;
boolean num8State = false;
boolean num7State = false;
//random contral values for motor toggles
byte switcher = 0;
//1 in 12 probability to change motor toggles
byte switchMax = 12;


//morse code low - high values
byte kVal[] = {
  1, 1, 1,
  0,
  1,
  0,
  1, 1, 1,
  0
};// = 10

byte aVal[] = {
  1,
  0,
  1, 1, 1,
  0
};// = 6

byte tVal[] = {
  1, 1, 1,
  0
};// = 4

byte iVal[] = {
  1,
  0,
  1,
  0
};// = 4

byte eVal[] = {
  1,
  0
};// = 2

byte rVal[] = {
  1,
  0,
  1, 1, 1,
  0,
  1,
  0
};// = 8

byte oVal[] = {
  1, 1, 1,
  0,
  1, 1, 1,
  0,
  1, 1, 1,
  0
};// = 12

byte eightVal[] = {
  1, 1, 1,
  0,
  1, 1, 1,
  0,
  1, 1, 1,
  0,
  1,
  0,
  1,
  0
};// = 16

byte sevenVal[] = {
  1, 1, 1,
  0,
  1, 1, 1,
  0,
  1,
  0,
  1,
  0,
  1,
  0
};// = 14



void setup() {
  Serial.begin(57600);
  randomSeed(analogRead(0));
  for(byte i = 0; i < 12; i++) {
    pinMode(pinOut[i], OUTPUT);
    Serial.print("Assigning pin# ");
    Serial.print(pinOut[i]);
    Serial.println(" as OUTPUT");
  }
}



void loop() {
  
  if (millis() - lastMs > interval) {

    //Toggle motors LOW/HIGH based on morse code
    letterK(0);
    letterA(1);
    letterT(2);
    letterI(3);
    letterE(4);

    letterK2(5);
    letterR(6);
    letterO(7);
    letterK3(8);
    letterO2(9);

    number8(10);
    number7(11);

    //set lastMs to current millis();
    lastMs = millis();
    
    mainCount += 1;
    if (mainCount == 255) {
      interval = random(37, 640);
      mainCount = 0;
    }
  }
  
}



/*
  Functions
*/
void letterK(byte aPindex) {
  if (kCounter == 0) {
    kState = switchMotorState(kState);
  }
  //check boolean state of motor
  if (kState == true) {
    if (kVal[kCounter] == 1) {
      if (pinBool(aPindex) == true) {
        tempRand = randomBase();
        analogWrite(pinOut[aPindex], tempRand);
      }
      else {
        digitalWrite(pinOut[aPindex], HIGH);
      }
    }
    else {
      digitalWrite(pinOut[aPindex], LOW);
    }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length
  kCounter += 1;
  if (kCounter == 10) {
    kCounter = 0;
  }
}

void letterA(byte aPindex) {
  if (aCounter == 0) {
    aState = switchMotorState(aState);
  }
  //check boolean state of motor
  if (aState == true) {
  if (aVal[aCounter] == 1) {
    if (pinBool(aPindex) == true) {
      tempRand = randomBase();
      analogWrite(pinOut[aPindex], tempRand);
    }
    else {
      digitalWrite(pinOut[aPindex], HIGH);
    }
  }
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length
  aCounter += 1;
  if (aCounter == 6) {
    aCounter = 0;
  }
}

void letterT(byte aPindex) {
  if (tCounter == 0) {
    tState = switchMotorState(tState);
  }
  //check boolean state of motor
  if (tState == true) {
  if (tVal[tCounter] == 1) {
    if (pinBool(aPindex) == true) {
      tempRand = randomBase();
      analogWrite(pinOut[aPindex], tempRand);
    }
    else {
      digitalWrite(pinOut[aPindex], HIGH);
    }
  }
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length
  tCounter += 1;
  if (tCounter == 4) {
    tCounter = 0;
  }
}

void letterI(byte aPindex) {
  if (iCounter == 0) {
    iState = switchMotorState(iState);
  }
  //check boolean state of motor
  if (iState == true) {
  if (iVal[iCounter] == 1) {
    if (pinBool(aPindex) == true) {
      tempRand = randomBase();
      analogWrite(pinOut[aPindex], tempRand);
    }
    else {
      digitalWrite(pinOut[aPindex], HIGH);
    }
  }
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length (yay java comments in C++)
  iCounter += 1;
  if (iCounter == 4) {
    iCounter = 0;
  }
}

void letterE(byte aPindex) {
  if (eCounter == 0) {
    eState = switchMotorState(eState);
  }
  //check boolean state of motor
  if (eState == true) {
  if (eVal[eCounter] == 1) {
    if (pinBool(aPindex) == true) {
      tempRand = randomBase();
      analogWrite(pinOut[aPindex], tempRand);
    }
    else {
      digitalWrite(pinOut[aPindex], HIGH);
    }
  }
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length
  eCounter += 1;
  if (eCounter == 2) {
    eCounter = 0;
  }
}

void letterK2(byte aPindex) {
  if (kCounter2 == 0) {
    kState2 = switchMotorState(kState2);
  }
  //check boolean state of motor
  if (kState2 == true) {
  if (kVal[kCounter2] == 1) {
    if (pinBool(aPindex) == true) {
      tempRand = randomBase();
      analogWrite(pinOut[aPindex], tempRand);
    }
    else {
      digitalWrite(pinOut[aPindex], HIGH);
    }
  }
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length
  kCounter2 += 1;
  if (kCounter2 == 10) {
    kCounter2 = 0;
  }
}

void letterR(byte aPindex) {
  if (rCounter == 0) {
    rState = switchMotorState(rState);
  }
  //check boolean state of motor
  if (rState == true) {
  if (rVal[rCounter] == 1) {
    if (pinBool(aPindex) == true) {
      tempRand = randomBase();
      analogWrite(pinOut[aPindex], tempRand);
    }
    else {
      digitalWrite(pinOut[aPindex], HIGH);
    }
  }
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length
  rCounter += 1;
  if (rCounter == 8) {
    rCounter = 0;
  }
}

void letterO(byte aPindex) {
  if (oCounter == 0) {
    oState = switchMotorState(oState);
  }
  //check boolean state of motor
  if (oState == true) {
  if (oVal[oCounter] == 1) {
    if (pinBool(aPindex) == true) {
      tempRand = randomBase();
      analogWrite(pinOut[aPindex], tempRand);
    }
    else {
      digitalWrite(pinOut[aPindex], HIGH);
    }
  }
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length
  oCounter += 1;
  if (oCounter == 12) {
    oCounter = 0;
  }
}

void letterK3(byte aPindex) {
  if (kCounter3 == 0) {
    kState3 = switchMotorState(kState3);
  }
  //check boolean state of motor
  if (kState3 == true) {
  if (kVal[kCounter3] == 1) {
    if (pinBool(aPindex) == true) {
      tempRand = randomBase();
      analogWrite(pinOut[aPindex], tempRand);
    }
    else {
      digitalWrite(pinOut[aPindex], HIGH);
    }
  }
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length
  kCounter3 += 1;
  if (kCounter3 == 10) {
    kCounter3 = 0;
  }
}

void letterO2(byte aPindex) {
  if (oCounter2 == 0) {
    oState2 = switchMotorState(oState2);
  }
  //check boolean state of motor
  if (oState2 == true) {
  if (oVal[oCounter2] == 1) {
    if (pinBool(aPindex) == true) {
      tempRand = randomBase();
      analogWrite(pinOut[aPindex], tempRand);
    }
    else {
      digitalWrite(pinOut[aPindex], HIGH);
    }
  }
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length
  oCounter2 += 1;
  if (oCounter2 == 12) {
    oCounter2 = 0;
  }
}

void number8(byte aPindex) {
  if (num8Counter == 0) {
    num8State = switchMotorState(num8State);
  }
  //check boolean state of motor
  if (num8State == true) {
  if (eightVal[num8Counter] == 1) {
    if (pinBool(aPindex) == true) {
      tempRand = randomBase();
      analogWrite(pinOut[aPindex], tempRand);
    }
    else {
      digitalWrite(pinOut[aPindex], HIGH);
    }
  }
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length
  num8Counter += 1;
  if (num8Counter == 16) {
    num8Counter = 0;
  }
}

void number7(byte aPindex) {
  if (num7Counter == 0) {
    num7State = switchMotorState(num7State);
  }
  //check boolean state of motor
  if (num7State == true) {
  if (sevenVal[num7Counter] == 1) {
    if (pinBool(aPindex) == true) {
      tempRand = randomBase();
      analogWrite(pinOut[aPindex], tempRand);
    }
    else {
      digitalWrite(pinOut[aPindex], HIGH);
    }
  }
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  }
  //ensure motor is low if xState == false
  else {
    digitalWrite(pinOut[aPindex], LOW);
  }
  //reset Counter if > xVal.length
  num7Counter += 1;
  if (num7Counter == 14) {
    num7Counter = 0;
  }
}

boolean pinBool(int aPindex) {
  if (aPindex == 3) {
    pinType = true;
    return pinType;
  }
  else if (aPindex == 5) {
    pinType = true;
    return pinType;
  }
  else if (aPindex == 6) {
    pinType = true;
    return pinType;
  }
  else if (aPindex == 9) {
    pinType = true;
    return pinType;
  }
  else if (aPindex == 10) {
    pinType = true;
    return pinType;
  }
  else if (aPindex == 11) {
    pinType = true;
    return pinType;
  }
  else {
    pinType = false;
    return pinType;
  }
}

byte randomBase() {
  byte tempRandom = random(1, baseAdd) + baseMin;
  return tempRandom;
}

boolean switchMotorState(boolean argState) {
  switcher = random(1, switchMax);
  if (switcher == 1) {
    return !argState;
  }
  else {
    return argState;
  }
}


