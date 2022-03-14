#include <stdio.h>
    
// student structure
typedef struct {
  char *id;
  char *firstname;
  char *lastname;
  float points;
  void (*stateMethod)(void);
}student;

// function declaration
void functionToPass(void);
void getDetail(student *);
void displayDetail(student *, int numPeople);
void initStudent(student *, int numPeople);

int main(void) {
  int numPeople;
  printf("Enter number of people you have\n\r");
  scanf("%d", &numPeople);
  //int val = *numPeople;
  //printf("%d\n\r", val);
  // student structure variable
  student std[numPeople];
  initStudent(std, numPeople);
  // get student detail
  //getDetail(std);
  
  printf("-----------------------\n\r");
  // display student detail
  displayDetail(std, numPeople);
 printf("-----------------------\n\r");
//  displayDetail(std, numPeople);
  return 0;
}

// function definition


void getDetail(student *ptr) {

  int i;

  for (i = 0; i < 3; i++) {
    printf("Enter detail of student #%d\n", (i + 1));
    printf("Enter ID: ");
    scanf("%s", ptr->id);
    printf("Enter first name: ");
    scanf("%s", ptr->firstname);
    printf("Enter last name: ");
    scanf("%s", ptr->lastname);
    printf("Enter Points: ");
    scanf("%f", &ptr->points);
    
    // update pointer to point at next element
    // of the array std
    ptr++;
  }

}

void displayDetail(student *ptr, int numPeople) {

  int i;

  for (i = 0; i < numPeople; i++) {
    printf("\nDetail of student #%d\n", (i + 1));
    
    // display result via ptr variable
    printf("\nResult via ptr\n");
    printf("ID: %s\n", ptr->id);
    printf("First Name: %s\n", ptr->firstname);
    printf("Last Name: %s\n", ptr->lastname);
    printf("Points: %f\n", ptr->points);
    ptr->stateMethod();
    
    // update pointer to point at next element
    // of the array std
    ptr++;
  }

}

void initStudent(student *ptr, int numPeople){
  char* id = "1";
  char* name = "Tommy";
  char* lastname = "Gunner";
  float value =10;
  
  for (int i = 0; i < numPeople; i++) {
      ptr->points = value;
      ptr->firstname = name;
      ptr->lastname = lastname;
      ptr->id = id;
      ptr->stateMethod = &functionToPass;
      ptr++;
  }
}

void functionToPass(void){
   printf("The passed function ran\n\r");

}
 


