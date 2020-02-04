#include "main.h"
#include "definition.h"

using namespace pros;

void doBlue(){
  autoSelect = 0;
}

void doSkills(){
  autoSelect = 1;
}

void doRed(){
  autoSelect = 2;
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

void autoTurn(char dir, int dist, int speed){
  tareMotors();
  if(dir == 'L'){
    driveFR.move_relative(dist, speed);
    driveFL.move_relative(-dist, speed);
    driveBR.move_relative(dist, speed);
    driveBL.move_relative(-dist, speed);
    while(fabs(driveFL.get_position() + dist) >= 25 ||
          fabs(driveFR.get_position() - dist) >= 25 ||
          fabs(driveBL.get_position() + dist) >= 25 ||
          fabs(driveBR.get_position() - dist) >= 25) delay(20);
  }
  else{
    driveFR.move_relative(-dist, speed);
    driveFL.move_relative(dist, speed);
    driveBR.move_relative(-dist, speed);
    driveBL.move_relative(dist, speed);
    while(fabs(driveFL.get_position() - dist) >= 25 ||
          fabs(driveFR.get_position() + dist) >= 25 ||
          fabs(driveBL.get_position() - dist) >= 25 ||
          fabs(driveBR.get_position() + dist) >= 25) delay(20);
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
