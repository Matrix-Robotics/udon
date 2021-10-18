#include "movement.h"

BodyParts Body;

void BodyParts::setI2C(int i2cPort) {
  switch (i2cPort) {
    case 1:
      BodyI2C = Mini.I2C1.MXservo;
      break;
    case 2:
      BodyI2C = Mini.I2C2.MXservo;
      break;
    case 3:
      BodyI2C = Mini.I2C3.MXservo;
      break;
    case 4:
      BodyI2C = Mini.I2C4.MXservo;
      break;
    default:
      BodyI2C = Mini.I2C1.MXservo;
      break;
  }
}

void BodyParts::LeftF(int arm_angle, int hand_angle, int t) {
  if (hand_angle != -1) {
    BodyI2C.setAngle(left_forward_hand, hand_angle);
  }
  delay(t);
  if (arm_angle != -1) {
    BodyI2C.setAngle(left_forward_arm, arm_angle);
  }
}

void BodyParts::RightF(int arm_angle, int hand_angle, int t) {
  if (hand_angle != -1) {
    BodyI2C.setAngle(right_forward_hand, hand_angle);
  }
  delay(t);
  if (arm_angle != -1) {
    BodyI2C.setAngle(right_forward_arm, arm_angle);
  }
}

void BodyParts::LeftB(int arm_angle, int hand_angle, int t) {
  if (hand_angle != -1) {
    BodyI2C.setAngle(left_backward_hand, hand_angle);
  }
  delay(t);
  if (arm_angle != -1) {
    BodyI2C.setAngle(left_backward_arm, arm_angle);
  }
}

void BodyParts::RightB(int arm_angle, int hand_angle, int t) {
  if (hand_angle != -1) {
    BodyI2C.setAngle(right_backward_hand, hand_angle);
  }
  delay(t);
  if (arm_angle != -1) {
    BodyI2C.setAngle(right_backward_arm, arm_angle);
  }
}
void BodyParts::balanceRF(int val) {
  RightF(map(val, 0, 100, 40, 110), map(val, 0, 100, 55, 170));
  //RF 110 170 Straight
  //RF 040 055 Bend

}
void BodyParts::balanceLF(int val) {
  LeftF(map(val, 0, 100, 150, 80), map(val, 0, 100, 120, 15));
  //LF 080 015 Straight
  //LF 150 120 Bend
  ;
}
void BodyParts::balanceRB(int val) {
  RightB(-1, map(val, 0, 100, 120, 0));
  delay(50);
  RightB(map(val, 0, 100, 150, 90), -1);
  //RB 090 000 Straight
  //RB 150 120 Bend
  ;
}
void BodyParts::balanceLB(int val) {
  RightB(-1, map(val, 0, 100, 60, 180));
  delay(50);
  RightB(map(val, 0, 100, 30, 90), -1);
  //LB 090 180 Straight
  //LB 030 060 Bend
  ;
}
