#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main(void){

  Stack* s = create_stack();
  push(&s, 10);
  return 0;
}
