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




void get_sizes(){	
	printf("Size of int data type : %d\n",sizeof(int));
	printf("Size of unsigned int data type : %d\n",sizeof(unsigned int));
	printf("Size of short data type : %d\n",sizeof(short));
	printf("Size of char data type : %d\n",sizeof(char));
	printf("Size of float data type : %d\n",sizeof(float));
	printf("Size of double data type : %d\n",sizeof(double)); 
	printf("Size of long data type : %d\n",sizeof(long));
	return;
}