/*



Author: Kurt Stewart

*/

//Preprocessor Commands
#ifndef ___Header_Test__
#define ___Header_Test__
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Structure Definitions -----------------------------------
typedef	struct{
	uint16_t StdID;
	uint8_t IDE;
	uint8_t RTR;
	uint8_t DLC;
	uint8_t data[8];
	uint8_t FilterMatchIndex;
}canPacketShortened;
// Inline Function Definitions
//inline function
static inline void inline_func(){
  printf("Inline function called\n\r");
}


// Function Definitions -----------------------------------
//Header_Funtioncs 
int get_amazing_result(int input);
void get_sizes();
int * allocate_data();
void structure_size();

// Pointer_Functions.c
void basic_pointer();
void dereference_pointer();
void generic_pointer_example();
void parent_pass_data_using_pointers();
void child_pass_data_using_pointers(int *a, int *b, int *c);
void pass_a_function_to_another();
void receive_a_function_ptr(int (*local_func_alias)(int input_a, int input_b));
int function_to_be_passed(int a, int b);
void pass_an_array();
void receive_an_array(int *arr, int length);
void receive_an_array2(int *arr, int length);



#endif //end of Header File
