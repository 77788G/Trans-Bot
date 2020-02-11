#include "main.h"
#include "definition.h"

using namespace pros;

void blueAuton(){
  if(autoLayer == 0){
    independent('R', 250, 100);
    simultaneous(-600, 100);
  }
  else{
    independent('L', 250, 100);
    simultaneous(600, 100);
  }
}
