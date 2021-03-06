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

void BodyParts::LeftF(int arm_angle, int hand_angle, int t){
  if (hand_angle != -1){
    BodyI2C.setAngle(left_forward_hand, hand_angle);
  }
  delay(t);
  if (arm_angle != -1){
    BodyI2C.setAngle(left_forward_arm, arm_angle);
  }
}

void BodyParts::RightF(int arm_angle, int hand_angle, int t){
  if (hand_angle != -1){
    BodyI2C.setAngle(right_forward_hand, hand_angle);
  }
  delay(t);
  if (arm_angle != -1){
    BodyI2C.setAngle(right_forward_arm, arm_angle);
  }
}

void BodyParts::LeftB(int arm_angle, int hand_angle, int t){
  if (hand_angle != -1){
    BodyI2C.setAngle(left_backward_hand, hand_angle);
  }
  delay(t);
  if (arm_angle != -1){
    BodyI2C.setAngle(left_backward_arm, arm_angle);
  }
}

void BodyParts::RightB(int arm_angle, int hand_angle, int t){
  if (hand_angle != -1){
    BodyI2C.setAngle(right_backward_hand, hand_angle);
  }
  delay(t);
  if (arm_angle != -1){
    BodyI2C.setAngle(right_backward_arm, arm_angle);
  }
}
