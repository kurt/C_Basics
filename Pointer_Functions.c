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

void generic_pointer_example(){
	void *generic_pointer;
	int val=10;
	float val2=2.0;
	generic_pointer=&val;
	printf("The generic_pointer points to an int %d\n\r",*(int*)generic_pointer);
	generic_pointer=&val2;
	printf("The generic_pointer points to an float %f\n\r",*(float*)generic_pointer);
}

//this is the parent that calls the child
void parent_pass_data_using_pointers(){
	int num1=10;
	int num2=3;
	int res;
	child_pass_data_using_pointers(&num1,&num2,&res);
	printf("The result of passing data through pointers is %d\n\r",res);
}

// the child that sums the inputs and stores in the result address
void child_pass_data_using_pointers(int *a, int *b, int *c){
	*c=*a+*b;
}


void pass_a_function_to_another(){
	receive_a_function_ptr(&function_to_be_passed);
}

void receive_a_function_ptr(int (*local_func_alias)(int input_a, int input_b)){
	int result=local_func_alias(2,3);
	printf("The result of passing a func as a pointer is %d\n\r",result);
	int result2=(*local_func_alias)(2,3);
	printf("The result of passing a func as a pointer is %d\n\r",result2);
}

int function_to_be_passed(int a, int b){
	int res=a+b;
	return res;
}