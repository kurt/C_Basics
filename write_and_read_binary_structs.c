
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct
{
    int age;
    char * name;
    double iq;
} Person;

typedef struct
{
    int age;
    int mileage;
    char * name;
    char * brand;
}Tractor;

bool write_data(char *filename, Person *studentData, Tractor *tractorData);
void print_data(char *filename);

int main()
{
   Person joshua;
   Tractor tim;
   joshua.name = "Joshua";
   joshua.age = 28;
   joshua.iq = 129;
   tim.age = 55;
   tim.mileage = 3500030;
   tim.name = "Tim";
   tim.brand = "Ford";
   bool writeSuccess = write_data("struct_file.bin",&joshua,&tim);
    print_data("struct_file.bin");
}


bool write_data(char *filename, Person *personData, Tractor *tractorData){
     FILE *file;
     file = fopen(filename, "wb");
     if(file == NULL) return false;

     if(fwrite(personData,sizeof(Person),1,file)!=1){
        return false;
     }
     if (fclose(file) == EOF) return false;
     return true;
}


void print_data(char *filename){
  FILE *file;

  // open the file with name filename in 'read a binary file mode'
  file = fopen(filename, "rb");

  // if fopen() failed to open the file, return NULL
  if (file == NULL) return;
  Person joshua;
  fread(&joshua, sizeof(Person), 1, file);
  printf("%s\n\r",joshua.name);
  printf("%lf\n\r",joshua.iq);
  printf("%d\n\r", joshua.age);
  }

