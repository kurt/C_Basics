#include <stdio.h> 
#include<string.h>
#include<stdbool.h> 
int main()
{
   FILE *fileAddress;
   fileAddress = fopen("sample.txt", "w");
   char name[50] = "Tutorial Gateway";
   int i;
   int len = strlen(name);
   static bool FCCall =false;
   if (fileAddress != NULL) {
	for (i = 0; i < len; i++) {
           printf("Character we ar writing to the File = %c \n", name[i]);
	   // Let us use our fputc
	   fputc (name[i], fileAddress);
	}
	printf("\n We have written the Name successfully");
	printf("The boolean in: %d\n\r", FCCall);
	FCCall=!FCCall;
	printf("The boolean in: %d\n\r", FCCall);
	fclose(fileAddress);		
   }
   else {
  	  printf("\n Unable to Create or Open the Sample.txt File");
   }
   return 0;
}
