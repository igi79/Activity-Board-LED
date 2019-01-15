void setup() {
 pinMode(0, OUTPUT);
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(4, INPUT_PULLUP);
}

unsigned long m = 0, pb = 0;
uint8_t d = 0, led = 0, tik = 100, p = 0;

uint8_t pingpong[4] = {0,1,2,1};
uint8_t ppindex = 0;
void loop() {

  
  
  if(digitalRead(4) == LOW && millis() - pb >= 50){   
    pb = millis();
    p++;
    if(p > 6) p = 0;
    alloff();
  }
  
  if(millis() - m >= tik){
    switch (p){
      case 0:
        alloff();
        break;
      case 1:
        program1();
        break;
      case 2:
        program2();
        break;
      case 3:
        program3();
        break;
      case 4:
        program4();
        break;
      case 5:
        program5();
        break;
      case 6:
        program6();
        break;

      default:
        break;
    }
    m = millis();
  }
}

void alloff() {
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
}

void program1() {
  tik = 100;
  d = d == HIGH ? LOW : HIGH;
  digitalWrite(0,d);
}


void program2() {
  tik = 75;
  d = d == HIGH ? LOW : HIGH;
  digitalWrite(1,d);
}


void program3() {
  tik = 50;
  d = d == HIGH ? LOW : HIGH;
  digitalWrite(2,d);
}

void program4() {
  tik = 50;
  d = d == HIGH ? LOW : HIGH;
  digitalWrite(0,d);
  digitalWrite(1,d);
  digitalWrite(2,d);
}

void program5() {
  tik = 30;
  digitalWrite(led,LOW);
  led++;
  if(led > 2) led = 0;
  digitalWrite(led,HIGH);
}

void program6() {
  tik = 30;
  digitalWrite(pingpong[ppindex],LOW);
  ppindex++;
  if(ppindex > 3) ppindex = 0;
  digitalWrite(pingpong[ppindex],HIGH);
}
