/*
Pointer_Functions.c

Author: Kurt Stewart
*/

#include "Header_Test.h"

void basic_pointer(){
	int var=10; 
	int *point;
	point=&var;
	printf("basic_pointer\n\r");
	printf("var value is %d at memory location %d\n\r",var,point);
}

void dereference_pointer(){
	int var=10;
	int *point;
	point=&var;
	printf("The pointer dereferenced is %d\n\r",*point); //print the value of the pointer by dereferencing it
}