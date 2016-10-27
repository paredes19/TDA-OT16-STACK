#include <stdio.h>
#include <stdlib.h>


int push (int * stack, int pos, float Val){
  stack[pos] = Val;
  return Val;
}

int pop (int * stack, int pos){
  int val = stack[pos];
  stack[pos] = -9999;
  return val;
}
 
