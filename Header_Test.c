/*





*/
 //Preprocessor Commands 
#include "Header_Test.h"
//Global Variables
int global_test_variable=12212;

int main(){
	int i, result, input;
	//extern int global_test_variable;
	printf("---------------------------------\n\r");
	printf("This is the beginning of the file\n\r");
	printf("Starting Random Things\n\r");
	input=12;
	for (i=0;i<10;i++){
		result=get_amazing_result(input);
	}
	printf("%d is the answer\n\r",result);
	printf("Inside MAIN %d\n\r",global_test_variable);
}