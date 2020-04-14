/*
Functions Definitions


*/
#include "Header_Test.h"

int get_amazing_result(int input){
	static int count=0;
	extern int global_test_variable;
	int local_rep=10000;
	int res;
	
	count++;
	printf("Count: %d - ", count);
	res=input*local_rep;
	printf("Inside Function: %d\n\r",global_test_variable);
	return res;
}