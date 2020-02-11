#include "main.h"
#include "definition.h"

using namespace pros;

void redAuton(){
  if(autoLayer == 0){
    simultaneous(600, 100);
    simultaneous(-600, 100);
  }
  else{
    simultaneous(-600, 100);
    simultaneous(600, 100);
  }
}
