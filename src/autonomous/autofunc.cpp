#include "main.h"
#include "definition.h"

using namespace pros;

void doBlue(){
  autoSelect = 0;
}

void doSkills(){
  autoSelect = 2;
}

void doRed(){
  autoSelect = 1;
}

void layerAdvance(){
  if (autoLayer == 2) autoLayer = 0;
  else autoLayer += 1;
}

void tareMotors(){
  driveFL.tare_position();
  driveFR.tare_position();
  driveBL.tare_position();
  driveBR.tare_position();
}

void simultaneous(int dist, int speed){
    tareMotors();
    driveFR.move_relative(dist, speed);
    driveFL.move_relative(dist, speed);
    driveBR.move_relative(dist, speed);
    driveBL.move_relative(dist, speed);
    while(fabs(driveFL.get_position() - dist) >= 25 ||
          fabs(driveFR.get_position() - dist) >= 25 ||
          fabs(driveBL.get_position() - dist) >= 25 ||
          fabs(driveBR.get_position() - dist) >= 25) delay(20);
}

void autoTurn(char dir, int rot, int speed){
  tareMotors();
  if(dir == 'L'){
    driveFR.move(speed);
    driveFL.move(-speed);
    driveBR.move(speed);
    driveBL.move(-speed);
    while(fabs(inertia.get_rotation() - rot) >= 5) delay(20);
  }
  else{
    driveFR.move(-speed);
    driveFL.move(speed);
    driveBR.move(-speed);
    driveBL.move(speed);
    while(fabs(inertia.get_rotation() - rot) >= 5) delay(20);
  }
}

void independent(char dir, int dist, int speed){
  tareMotors();
  if(dir == 'L'){
    driveFL.move_relative(dist, speed);
    driveBL.move_relative(dist, speed);
    while(fabs(driveFL.get_position() - dist) >= 25 ||
          fabs(driveBL.get_position() - dist) >= 25) delay(20);
  }
  else{
    driveFR.move_relative(dist, speed);
    driveBR.move_relative(dist, speed);
    while(fabs(driveFR.get_position() - dist) >= 25 ||
          fabs(driveBR.get_position() - dist) >= 25) delay(20);
  }
}

void liftPos(int height, int speed){
    lift.move_absolute(height, speed);
    while(fabs(driveFR.get_position() - height) >= 25) delay(20);
}

void startIntake(){
  intakeL.move(200);
  intakeR.move(200);
}

void stopIntake(){
  intakeL.move(0);
  intakeR.move(0);
}

void deposit(){
  angle.move_absolute(3300, 100);
  while(fabs(driveFR.get_position() - 3300) >= 25) delay(20);
  angle.move_absolute(3800, 40);
  while(fabs(driveFR.get_position() - 3800) >= 25) delay(20);
  simultaneous(-400, 75);
  angle.move_absolute(0, 100);
}
