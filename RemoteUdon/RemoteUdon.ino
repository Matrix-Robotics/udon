#include "movement.h"

#define roll 0
#define pitch 1
#define cmd 3

byte bf[cmd] = {0};

void setup()
{
  Mini.begin(7.4);
  Serial.begin(9600);
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
}

void loop() {
  int * Euler;
  Euler = new int[2];
  Euler[roll] = Mini.I2C3.MXmotion.getRoll();
  Euler[pitch] = Mini.I2C3.MXmotion.getPitch();
  if (Serial.available() > 0) {
    Serial.readBytes(bf, cmd);
  }
  if (bf[0] == 255) {
    switch (bf[1]) {
      case  0:
        Mini.RGB1.setRGB(255, 0, 0);
        Mini.RGB2.setRGB(255, 0, 0);
        standBy();
        Body.flag = 0;
        break;
      case  1:
        Mini.RGB1.setRGB(0, 255, 0);
        Mini.RGB2.setRGB(0, 255, 0);
        standUp();
        Body.flag = 0;
        break;
      case  2:
        Mini.RGB1.setRGB(0, 0, 255);
        Mini.RGB2.setRGB(0, 0, 255);
        shakeHand(4);
        Body.flag = 0;
        break;
      case  3:
        Mini.RGB1.setRGB(255, 255, 0);
        Mini.RGB2.setRGB(255, 255, 0);
        pushUp(5);
        Body.flag = 0;
        break;
      case  4:
        Mini.RGB1.setRGB(0, 255, 255);
        Mini.RGB2.setRGB(0, 255, 255);
        warmUp(30);
        Body.flag = 0;
        break;
      case  5:
        Mini.RGB1.setRGB(255, 0, 255);
        Mini.RGB2.setRGB(255, 0, 255);
        stretchF();
        delay(100);
        stretchB();
        delay(100);
        Body.flag = 0;
        break;
      case  6:
        Mini.RGB1.setRGB(255, 255, 255);
        Mini.RGB2.setRGB(255, 255, 255);
        walk();
        Body.flag = 0;
        break;
      case 7 :

//        balance(Euler[roll],Euler[pitch]);
        break;
      case 8 :
        Body.flag = 0;
        break;
      case 9 :
        layDown();
        Body.flag = 0;
        break;
      default:
        Mini.RGB1.setRGB(255, 0, 0);
        Mini.RGB2.setRGB(255, 0, 0);
        standBy();
        Body.flag = 0;
        break;
    }
  }

  if (Body.flag == 0) {
    for (int i = 0; i < cmd; i++) {
      bf[i] = 0;
    }
    Mini.RGB1.setRGB(0, 0, 0);
    Mini.RGB2.setRGB(0, 0, 0);
  }

  delete Euler;
}
