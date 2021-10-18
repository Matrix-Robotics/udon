#include "movement.h"

//int roll, Yaw;
const int cmd = 2;
char bf[cmd] = {0};
char bf2[6] = {0};
int pos[8] = {0};

void setup() {
  Mini.begin(7.4);
  Serial.begin(115200);
  Body.setI2C(1);


  Mini.RGB1.setRGB(255, 0, 0);
  Mini.RGB2.setRGB(255, 0, 0);
  standBy();
  while (!Mini.BTN1.get()) {
    ;
  } while (Mini.BTN1.get()) {
    ;
  }
  Serial.println("Begin ...");
  Mini.RGB1.setRGB(0, 255, 0);
  Mini.RGB2.setRGB(0, 255, 0);
}

void loop() {
  int *po;
  po = new int[2] ;
  if (Serial.available() > 0) {
    Serial.readBytes(bf, cmd);
  }
  if (bf[0] == 'r' || bf[0] == 'l') {
    while (Serial.available() == 0) {
    }
    if (Serial.available() > 0) {
      Serial.readBytes(bf2, 6);
    }


    po[0] = (bf2[0] - '0') * 100 + (bf2[1] - '0') * 10 + (bf2[2] - '0');
    po[1] = (bf2[3] - '0') * 100 + (bf2[4] - '0') * 10 + (bf2[5] - '0');

    if (bf[0] == 'r' ) {
      if (bf[1] == 'f') {
        Body.RightF(po[0], po[1]);
      } else if (bf[1] == 'b') {
        Body.RightB(po[0], po[1]);
      }
      po[0] = -1;
      po[1] = -1;

      bf[0] = 0;
    } else if (bf[0] == 'l') {
      if (bf[1] == 'f') {
        Body.LeftF(po[0], po[1]);
      } else if (bf[1] == 'b') {
        Body.LeftB(po[0], po[1]);
      }
      po[0] = -1;
      po[1] = -1;

      bf[0] = 0;
    }
  } else if (bf[0] == 'm') {
    if (bf[1] == 's') {
      standBy();
      bf[0] = 0;
    } else if (bf[1] == 'p') {
      pushUp();
      bf[0] = 0;
    } else if (bf[1] == 'w') {
      walk();
      bf[0] = 0;
    } else if (bf[1] == 'l') {
      layDown();
      bf[0] = 0;
    }
  }
  delete po;
}
