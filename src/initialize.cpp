#include "main.h"
#include "definition.h"

using namespace pros;

int autoSelect;
void initialize() {
  autoSelect = 1;
  angle.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  lift.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  intakeL.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  intakeR.set_brake_mode(E_MOTOR_BRAKE_HOLD);
  lcd::print(0, "THE 0-6 CALIFORNIA DREAM BABY!!!");
  lcd::print(1, "DRIVING PRACTICE MOMENT");
  lcd::register_btn0_cb(doBlue);
  lcd::register_btn1_cb(doSkills);
  lcd::register_btn2_cb(doRed);

}
void competition_initialize() {}
void disabled() {}
