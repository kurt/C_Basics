/*
Functions Definitions

Author: Kurt Stewart
*/
#include "Header_Test.h"

// A basic function with multiplication
// Has a static count that is incremented each function calloc
// Also accesses a global variable
int get_amazing_result(int input){
	static int count=0;
	extern int global_test_variable; 
	int local_rep=10000;
	int res;

	//Operations 
	count++;
	printf("Count: %d - ", count);
	res=input*local_rep;
	printf("Global Inside Function: %d\n\r",global_test_variable);
	return res;
}

// Prints the sizes of variables
void get_sizes(){	
	printf("Size of int data type : %d bytes\n",sizeof(int));
	printf("Size of unsigned int data type : %d bytes\n",sizeof(unsigned int));
	printf("Size of short data type : %d bytes\n",sizeof(short));
	printf("Size of char data type : %d bytes\n",sizeof(char));
	printf("Size of float data type : %d bytes\n",sizeof(float));
	printf("Size of double data type : %d bytes\n",sizeof(double)); 
	printf("Size of long data type : %d bytes\n",sizeof(long));
	// Apparently Pointers are 8 bytes?
	//printf("Size of a pointer : %d\n",sizeof(*int));
	return;
}


// Allocates memory and passes it back to calling function
int * allocate_data(){
	int *ip=malloc(100*sizeof(int)); //allocate the memory for 100 
	int bool_int;
	if (ip==NULL){ //memory check
		printf("Out of memory");
	}
	else{
		printf("Memory Allocation Successful!\n\r");
		printf("Pointer in Function: %d\n\r",ip[0]);
		printf("Sizeof a pointer: %d bytes\n\r",sizeof(ip));
	}
	return ip;
}

// Size of a structure
void structure_size(){
	canPacketShortened CAN_Struct;
	printf("Size of struct: %ld bytes\n\r", sizeof(CAN_Struct));
	printf("Size of struct: %ld bits\n\r",8*sizeof(CAN_Struct));
	return;
}



