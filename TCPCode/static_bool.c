#include <stdio.h> 
#include<string.h>
#include<stdbool.h>



 
int fun() 
{ 
  static bool count = false; 
  count=!count; 
  return count; 
} 
   
int main() 
{ 
  printf("%d ", fun()); 
  printf("%d ", fun()); 
  return 0; 
}
