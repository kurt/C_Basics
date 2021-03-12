// how to run:  gcc LinkedList.c LinkeListFunctions.c -o linked.out 


#include "LinkedList.h"



int main(){
  struct node *start = NULL;
  printf("Time to Go");
  start = create_ll(start);
  display(start);
  start = insert_end(start);
  display(start);
  start = insert_location(start,3);
  display(start);
  start = insert_location(start,0);
  display(start);
  start = insert_location(start,8);
  display(start);
  start = insert_location(start,22);
  display(start);
}



