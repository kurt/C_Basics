/*
Functions Definitions


*/
#include "Header_Test.h"

int get_amazing_result(int input){
	static int count=0;
	extern int global_test_variable;
	int local_rep=10000;
	int res;

	//Operations 
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
	// Apparently Pointers are 8 bytes?
	//printf("Size of a pointer : %d\n",sizeof(*int));
	return;
}


// Allocates memory and passes it back 
int * allocate_data(){
	int *ip=malloc(100*sizeof(int)); //allocate the memory for 100 
	int bool_int;
	if (ip==NULL){ //memory check
		printf("Out of memory");
	}
	else{
		printf("Memory Allocation Successful!\n\r");
		printf("Pointer in Function: %d\n\r",ip[0]);
		printf("Sizeof a pointer: %d\n\r",sizeof(ip));
	}
	return ip;
}