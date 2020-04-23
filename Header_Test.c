/*
This is a set of programs that are used for reference for working in C basics



Author: Kurt Stewart!
*/
 //Preprocessor Commands 
#include "Header_Test.h"
//Global Variables
int global_test_variable=12212;

int main(){
	int i, result, input, *data_pointer;
	//extern int global_test_variable;
	printf("---------------------------------\n\r");
	printf("This is the beginning of the file\n\r");
	input=12;
	for (i=0;i<10;i++){
		result=get_amazing_result(input);
	}
	printf("%d is the answer\n\r",result);
	printf("Global Inside MAIN %d\n\r",global_test_variable);
	get_sizes();
	data_pointer=allocate_data();
	printf("Pointer in Main: %d\n\r",data_pointer[0]);
	free(data_pointer);
	printf("data freed\n\r");
	
	//Call Pointer Functions
	basic_pointer();
	dereference_pointer();
	structure_size();
}