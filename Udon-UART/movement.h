#pragma once
#include <MatrixMini.h>

//int FL=0;

// Set I2C
#define right_forward_arm 2
#define right_forward_hand 1

#define left_forward_arm 3
#define left_forward_hand 4

#define right_backward_arm 5
#define right_backward_hand 6

#define left_backward_arm 7
#define left_backward_hand 8

// define limit
//right_forward_arm_forward
#define RFAF 170
//right_forward_arm_backward
#define RFAB 30
//right_forward_arm_middle
#define RFAM 60 // 90-30

#define RFHF 50
#define RFHB 170

#define LFAF 12
#define LFAB 150
#define LFAM 120 // 90+30

#define LFHF 120
#define LFHB 0

#define RBAF 150
#define RBAB 10
#define RBAM 120 // 90+30

#define RBHF 0
#define RBHB 120

#define LBAF 30
#define LBAB 170
#define LBAM 70 // 90-30+10

#define LBHF 180
#define LBHB 60


// Basic Control
class BodyParts {
  private:
    MatrixServo BodyI2C;
  public:
    void setI2C(int i2cPort);
    void LeftF(int arm_angle, int hand_angle, int t = 0);
    void LeftB(int arm_angle, int hand_angle, int t = 0);
    void RightF(int arm_angle, int hand_angle, int t = 0);
    void RightB(int arm_angle, int hand_angle, int t = 0);
    void balanceRF(int val = 50);
    void balanceLF(int val = 50);
    void balanceRB(int val = 50);
    void balanceLB(int val = 50);
    int flag = 0;
};

// Single Poses
void layDown(int ang = 20);
void standUp();
void standBy();

// Combination Poses
void shakeHand(int cnt = 4);
void pushUp(int cnt = 5);
void warmUp(int ang);
void stretchF();
void stretchB();
void walk(int cnt = 1);

// TODO
void flip();
void headDown(int ang = 0);
void headUp(int ang = 0);
void balance(int ang = 0);

extern BodyParts Body;
//extern int FL;
