#include <stdio.h>

#define MACRO_FUNCTION()    printf("Macro function\n\r");
#define MACRO_FUNCTION_WITH_Input(x)   printf("Macro with input: %d\n\r", (int) x);
#define MACRO_FUNCTION_WITH_RETURN()   ({int val; val = 10; val;})

int main(){
  int input = 100;
  int output;
  MACRO_FUNCTION();
  MACRO_FUNCTION_WITH_Input(input);
  output = MACRO_FUNCTION_WITH_RETURN();
  printf("Macro with return: %d", output);
}
