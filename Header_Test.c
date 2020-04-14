/*





*/
 //Preprocessor Commands 
#include "Header_Test.h"
//int global_test_variable=12212;

int main(){
	int result, input;
	//extern int global_test_variable;
	printf("This is the beginning of the file\n\r");
	printf("Starting Random Things\n\r");
	input=12;
	result=get_amazing_result(input);
	printf("%d is the answer",result);
	//printf("Inside %d",global_test_variable);
}