#include <stdio.h>
#include "stack.h"
#include "stdUI.h"

int main(void){
  format(INVISIBLE);
  while(getCommandFromStdIn() != INPUT_ERROR);
}
