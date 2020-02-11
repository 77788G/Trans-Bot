#include "main.h"
#include "definition.h"

using namespace pros;

int autoSelect = 0;
int autoLayer = 0;
void initialize() {
  lcd::initialize();

  angle.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  lift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  intakeL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  intakeR.set_brake_mode(E_MOTOR_BRAKE_HOLD);

  lcd::register_btn0_cb(doBlue);
  lcd::register_btn1_cb(layerAdvance);
  lcd::register_btn2_cb(doRed);
}

void competition_initialize() {}
void disabled() {}
