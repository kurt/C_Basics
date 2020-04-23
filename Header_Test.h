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


// Function Definitions -----------------------------------
//Header_Funtioncs 
int get_amazing_result(int input);
void get_sizes();
int * allocate_data();
void structure_size();

// Pointer_Functions.c
void basic_pointer();
void dereference_pointer();

#endif //end of Header File