/*
Functions Definitions


*/
#include "Header_Test.h"

int get_amazing_result(int input){
	//extern int global_test_variable;
	int local_rep=10000;
	int res;
	res=input*local_rep;
	//printf("Inside Function: %d",global_test_variable);
	return res;
}