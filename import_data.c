#include <stdio.h>
#include <stdlib.h>

// Import numeric txt file data into C using fscanf
// See data/ for examples 
#define MAX_LINE_LENGTH 80

static int sum(int val){
   static int value;
   value += val;
   return value;
}

int main(){
	printf("Started\n\r");
	int num;
        int a;
	int line[MAX_LINE_LENGTH]={0};
        FILE *fptr;
	fptr = fopen("data/LeftLegAngleData.txt","r");
	
	if(fptr == NULL)
	{
		printf("Error This file does not exist\n\r");
		exit(1);
	}	
        fscanf(fptr,"%d", &num);
	printf("The first value is = %d\n\r",num);
        while(!feof(fptr)){
	fscanf(fptr,"%d", &num);//imported
        //a = sum(num);
	//printf("The next value is = %d\n\r",num);
        }
        printf("done import");
	fclose(fptr);
	return 0;
}
