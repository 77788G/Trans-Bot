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

    liftL.move((controlR2 - controlL2)*100);
    liftR.move((controlR2 - controlL2)*100);

    intakeL.move((controlR1 - controlY)*200);
    intakeR.move((controlR1 - controlY)*200);
    //this is a test comment
  }
}
