#include "main.h"
#include "definition.h"

using namespace pros;

int leftY;
int leftX;
int rightY;
int rightX;
bool controlA;
bool controlB;
bool controlY;
bool controlX;
bool controlUp;
bool controlDown;
bool controlLeft;
bool controlRight;
bool controlL1;
bool controlL2;
bool controlR1;
bool controlR2;

void opcontrol() {
  while(true){
    leftY = master.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
    leftX = master.get_analog(E_CONTROLLER_ANALOG_LEFT_X);
    rightY = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_Y);
    rightX = master.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);
    controlA = master.get_digital(E_CONTROLLER_DIGITAL_A);
    controlB = master.get_digital(E_CONTROLLER_DIGITAL_B);
    controlY = master.get_digital(E_CONTROLLER_DIGITAL_Y);
    controlX = master.get_digital(E_CONTROLLER_DIGITAL_X);
    controlUp = master.get_digital(E_CONTROLLER_DIGITAL_UP);
    controlDown = master.get_digital(E_CONTROLLER_DIGITAL_DOWN);
    controlLeft = master.get_digital(E_CONTROLLER_DIGITAL_LEFT);
    controlRight = master.get_digital(E_CONTROLLER_DIGITAL_RIGHT);
    controlL1 = master.get_digital(E_CONTROLLER_DIGITAL_L1);
    controlL2 = master.get_digital(E_CONTROLLER_DIGITAL_L2);
    controlR1 = master.get_digital(E_CONTROLLER_DIGITAL_R1);
    controlR2 = master.get_digital(E_CONTROLLER_DIGITAL_R2);

    lift.move((controlR2 - controlL2)*100);

    if(angle.get_position() < 0) angle.move(40);
    else if(controlRight) angle.move(-100);
    else if(controlL1) angle.move_velocity((-angle.get_position() + 5000) * 6.283); 
    /* else if(angle.get_position() < 1300) angle.move_velocity((controlL1) * 600);
    else if(angle.get_position() < 3500) angle.move_velocity((controlL1) * 480);
    else if(angle.get_position() < 4000) angle.move_velocity(controlL1 * 240); */
    else angle.move(-40);

    intakeL.move((controlR1 - controlY)*200);
    intakeR.move((controlR1 - controlY)*200);

    intakeL.move((controlL1)*50);
    intakeR.move((controlL1)*50);

    driveFL.move(leftY);
    driveBL.move(leftY);
    driveFR.move(rightY);
    driveBR.move(rightY);
  }
}
