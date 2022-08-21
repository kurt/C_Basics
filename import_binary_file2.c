#include <stdio.h>
#include <stdint.h>

int main () {
   FILE *fptr;
   int16_t fsrVoltageSample_mV;
  
   fptr = fopen("LeftLegFSRdata.bin","rb");
   while(1) {
      size_t readRet = fread(&fsrVoltageSample_mV, sizeof(int16_t), 1, fptr);
      if( feof(fptr) ) { 
         break ;
      }
      printf("%d\n\r", fsrVoltageSample_mV);
   }
   fclose(fptr);
   
   return(0);
}
