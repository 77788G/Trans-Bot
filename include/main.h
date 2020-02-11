
#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS

#include "api.h"

#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);

void tareMotors();
void simultaneous(int dist, int speed);
void autoTurn(char dir, int dist, int speed);
void independent(char dir, int dist, int speed);
void liftPos(int height, int speed);
void startIntake();
void stopIntake();
void deposit();

void doSkills();
void doRed();
void doBlue();
void blueAuton();
void redAuton();
void skillsAuton();
void layerAdvance();

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#endif

#endif
