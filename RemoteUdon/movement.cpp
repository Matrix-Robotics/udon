#include "movement.h"

void layDown(int ang) {
  // Note: -40 <= ang <= 40
  Body.RightF(RFAB, RFHF + 10 - ang);
  Body.LeftF(LFAB, LFHF - 10 + ang);
  delay(100);
  Body.RightB(RBAF, RBHB - 5 + ang);
  Body.LeftB(LBAF, LBHB - ang);
  Body.flag = 0;
}

void standUp() {
  Body.RightF(-1, RFHB);
  Body.LeftF(-1, LFHB);
  Body.RightB(-1, RBHF);
  Body.LeftB(-1, LBHF);
  delay(100);

  Body.RightF(110, -1);
  Body.LeftF(80, -1);
  Body.RightB(95, -1);
  Body.LeftB(90, -1);
  delay(100);
  Body.flag = 0;
}

void standBy() {
  int bias = 10;
  Body.RightF(RFAM, RFHF + 40);
  Body.LeftF(LFAM, LFHF - 40);
  Body.RightB(RBAM, RBHB - 40);
  Body.LeftB(LBAM, LBHB + 40);
  delay(50);
  Body.flag = 0;
}

void balance(int R, int P) {
  if (R > 25) R = 25;
  if (R < -25) R = -25;
  if (P > 25) P = 25;
  if (P < -25) P = -25;
  if (R < 5 && R > -5) R = 0;
  if (P < 5 && P > -5) P = 0;
  /*
     Roll Up , Right extend
     Roll Down, Left extend

     P up , Back extend
     P down , Front extend

  */
  Body.RightF(RFAM + R * 0.4, RFHF + 40 + 0.8 * R);
  Body.LeftF(LFAM + R * 0.4, LFHF - 40 + 0.8 * R);

  Body.RightB(RBAM - R * 0.4, RBHB - 40 - 0.8 * R);
  Body.LeftB(LBAM - R * 0.4, LBHB + 40 - 0.8 * R);

  Body.flag = 1;
}

void walk(int cnt) {
  standBy();
  delay(100);
  for (int i = 0; i < 5; i++) {
    Body.RightF(RFAM , RFHF + 20); // RFAM, RFHF + 40
    delay(50);
    Body.RightF(RFAM + 70, -1); // RFAM, RFHF + 40
    delay(50);
    Body.LeftF(LFAM + 10 , LFHF - 40); // LFAM, LFHF - 40
    delay(50);
    Body.LeftB(-1, LBHB + 30); // LBAM, LBHB + 40
    delay(50);
    Body.RightF(-1, RFHF + 60); // RFAM, RFHF + 40
    delay(100);
    Body.LeftB(LBAM - 20, LBHB + 20); // LBAM, LBHB + 40
    delay(100);

    Body.RightB(RBAM, RBHB - 60); // RBAM, RBHB - 40
    delay(50);
    Body.RightB(RBAM - 60, -1); // RBAM, RBHB - 40
    delay(50);
    Body.RightF(-1, RFHB); // RFAM, RFHF + 40
    delay(50);
    Body.RightB(-1, RBHB - 80); // RBAM, RBHB - 40
    delay(250);


    Body.LeftF(LFAM , LFHF - 20); // LFAM, LFHF - 40
    delay(50);
    Body.LeftF(LFAM - 70, -1); // LFAM, LFHF - 40
    delay(50);
    Body.RightF(RFAM , RFHF + 40); // RFAM, RFHF + 40
    delay(50);
    Body.RightB(-1, RBHB - 30); // RBAM, RBHB - 40
    delay(50);
    Body.LeftF(-1, LFHF - 60); // LFAM, LFHF - 40
    delay(100);
    Body.RightB(RBAM + 20, RBHB - 20); // RBAM, RBHB - 40
    delay(100);

    Body.LeftB(LBAM, LBHB + 60); // LBAM, LBHB + 40
    delay(50);
    Body.LeftB(LBAM + 60, -1); // LBAM, LBHB + 40
    delay(50);
    Body.LeftF(-1, LFHB); // LFAM, LFHF - 40
    delay(50);
    Body.LeftB(-1, LBHB + 80); // LBAM, LBHB + 40
    delay(250);
  }
  Body.flag = 0;
}

void shakeHand(int cnt) {
  layDown(0);
  delay(1000);
  Body.RightF(90, RFHB);
  Body.LeftF(90, 30);
  Body.RightB(RBAF, RBHB - 5 + 20);
  Body.LeftB(LBAF, LBHB - 20);

  delay(400);

  for (int i = 0; i < cnt; i++) {
    Body.RightF(RFAF - 20, RFHB - 70);
    delay(500);
    Body.RightF(90 + 20, RFHB);
    delay(500);
  }

  Body.RightF(90, RFHB);
  Body.LeftF(90, 30);
  Body.RightB(RBAF, RBHB - 5 + 20);
  Body.LeftB(LBAF, LBHB - 20);

  Body.flag = 0;
}

void pushUp(int cnt) {
  Body.LeftF(90, LFHB);
  Body.LeftB(LBAB, LBHF);
  Body.RightF(95, RFHB);
  Body.RightB(RBAB + 5, RBHF);
  delay(1000);
  for (int i = 0; i < cnt; i++) {
    Body.RightF(RFAM, 90);
    Body.LeftF(LFAM, 80);
    delay(1200);

    Body.RightF(95, RFHB - 5);
    Body.LeftF(90, LFHB);
    delay(1200);
  }
  delay(10);
  Body.flag = 0;
}

void stretchF() {
  // TODO
  standUp();
  delay(300);
  Body.LeftF(LFAF, LFHB);
  Body.RightF(RFAF, RFHB);
  Body.LeftB(80, LBHF);
  Body.RightB(100, RBHF);

  delay(500);
  Body.flag = 0;
}

void stretchB() {
  // TODO
  standUp();
  delay(300);
  Body.LeftF(90, LFHB);
  Body.RightF(90, RFHB);
  Body.LeftB(LBAB, LBHF);
  Body.RightB(RBAB, RBHF);

  delay(500);
  Body.flag = 0;
}

void warmUp(int ang) {
  standBy();
  for (int i = 0; i < 6; i++) {
    Body.RightB(-1, RBHB - ang);
    Body.LeftF(-1, LFHF - ang);
    delay(80);
    Body.RightF(-1, RFHF);
    Body.LeftB(-1, LBHB);
    delay(80);

    Body.RightF(-1, RFHF + ang);
    Body.LeftB(-1, LBHB + ang);
    delay(80);
    Body.RightB(-1, RBHB);
    Body.LeftF(-1, LFHF);
    delay(80);
  }
  standBy();

  Body.flag = 0;
}

//
//void headDown(int ang) {
//  Body.RightF(RFAM + 10,  RFHF + 40);
//  Body.LeftF(LFAM - 10, LFHF - 40);
//  Body.RightB(RBAM - 30, RBHF);
//  Body.LeftB(LBAM + 30, LBHF);
//  FL = 0;
//}
//
//void headUp(int ang) {
//  Body.RightF(RFAM + 40, RFHF + 120);
//  Body.LeftF(LFAM - 40, LFHF - 120);
//  Body.RightB(RBAM, RBHF + 80);
//  Body.LeftB(LBAM, LBHF - 80);
//  FL = 0;
//}
//
//void balance(int ang) {
//  if (ang > 20) ang = 20;
//  if (ang < -20) ang = -20;
//  Body.RightF(RFAM + 25 - ang, RFHF + 80 - ang * 2);
//  Body.LeftF(LFAM - 25 + ang, LFHF - 80 + ang * 2);
//
//  Body.RightB(RBAM - 15 - ang, RBHF + 40 - ang * 2);
//  Body.LeftB(LBAM + 15 + ang, LBHF - 40 + ang * 2);
//  
//  Body.flag = 0;
//}
