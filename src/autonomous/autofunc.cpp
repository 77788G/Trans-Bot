#include "main.h"
#include "definition.h"

using namespace pros;

void tareMotors(){
  driveL.tare_position();
  driveR.tare_position();
  transL.tare_position();
  transR.tare_position();
}

void simultaneous(int dist, int speed){
    tareMotors();
    driveR.move_relative(dist, speed);
    driveL.move_relative(dist, speed);
    transR.move_relative(dist, speed);
    transL.move_relative(dist, speed);
    while(fabs(driveL.get_position() - dist) >= 25 ||
          fabs(driveR.get_position() - dist) >= 25 ||
          fabs(transL.get_position() - dist) >= 25 ||
          fabs(transR.get_position() - dist) >= 25) delay(20);
}

void autoTurn(char dir, int dist, int speed){
  tareMotors();
  if(dir == 'L'){
    driveR.move_relative(dist, speed);
    driveL.move_relative(-dist, speed);
    transR.move_relative(dist, speed);
    transL.move_relative(-dist, speed);
    while(fabs(driveL.get_position() + dist) >= 25 ||
          fabs(driveR.get_position() - dist) >= 25 ||
          fabs(transL.get_position() + dist) >= 25 ||
          fabs(transR.get_position() - dist) >= 25) delay(20);
  }
  else{
    driveR.move_relative(-dist, speed);
    driveL.move_relative(dist, speed);
    transR.move_relative(-dist, speed);
    transL.move_relative(dist, speed);
    while(fabs(driveL.get_position() - dist) >= 25 ||
          fabs(driveR.get_position() + dist) >= 25 ||
          fabs(transL.get_position() - dist) >= 25 ||
          fabs(transR.get_position() + dist) >= 25) delay(20);
  }
}

void independent(char dir, int dist, int speed){
  tareMotors();
  if(dir == 'L'){
    driveL.move_relative(dist, speed);
    transL.move_relative(dist, speed);
    while(fabs(driveL.get_position() - dist) >= 25 ||
          fabs(transL.get_position() - dist) >= 25) delay(20);
  }
  else{
    driveR.move_relative(dist, speed);
    transR.move_relative(dist, speed);
    while(fabs(driveR.get_position() - dist) >= 25 ||
          fabs(transR.get_position() - dist) >= 25) delay(20);
  }
}
