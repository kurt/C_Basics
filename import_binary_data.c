#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MAX_LINE_LENGTH 80



int main(){
	printf("Started\n\r");
	int num;
        int a;
	int line[MAX_LINE_LENGTH]={0};
        FILE *fptr;
	fptr = fopen("data/RightLegAngleData.bin","rb");
	
	if(fptr == NULL)
	{
		printf("Error This file does not exist\n\r");
		exit(1);
	}	
        fread(&num,sizeof(int32_t),1, fptr);
	printf("The first value is = %d\n\r",num);
        while(!feof(fptr)){
	fread(&num,sizeof(int32_t),1, fptr);//imported
	printf("The next value is = %d\n\r",num);
        }
        printf("done import\n\r");
	fclose(fptr);
	return 0;
}
