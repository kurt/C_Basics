#include <stdio.h>
#include <setjmp.h>

jmp_buf jumper;

   int SomeFunction(int a, int b)
   {
      if (b == 0) // can't divide by 0
         longjmp(jumper, -3);
      return a / b;
   }

   void main(void)
   {
      if (setjmp(jumper) == 0)
      {
         int Result = SomeFunction(7, 0);
         // continue working with Result
      }
      else
         printf("an error occured\n");
   }
