#include "LinkedList.h"
#include<assert.h>
#include<errno.h>
//Setup:
struct node *start = NULL;

void test_create_ll(); 
void test_insert_beg();
void test_insert_end();
void test_insert_location_middle();
void test_insert_location_end();
void test_insert_location_start();
void test_insert_location_outofrange();


int main(){
  printf("Time to Go\n\r");
  //These Tests result in full coverage but further tests could be implemented for more robust tests
  test_create_ll();
  test_insert_beg();
  test_insert_end();
  test_insert_location_middle();
  test_insert_location_outofrange();
  test_insert_location_end();
  test_insert_location_start();
  display(start);
  printf("Tests Complete\n\r");
}

void test_create_ll(){
    start = create_ll(start);
    assert(start != NULL); //assert will fail if this is not true
}


void test_insert_beg(){
    int len_list, init_data;
    init_data = start -> data;
    len_list = list_length(start);
    start = insert_beg(start);
    assert(list_length(start)==(len_list+1));
    assert(start->next->data == init_data);
}

void test_insert_end(){
    int len_list;
    len_list = list_length(start);
    start = insert_end(start);
    assert(list_length(start) == (len_list+1));
}

void test_insert_location_middle(){
    int len_list, init_data, middle;
    len_list = list_length(start);
    middle = len_list/2;
    struct node *ptr;
    ptr = start;
    for(int i=0; i<middle;i++){
         ptr=ptr->next;
    }
    init_data = ptr->data;
    start = insert_location(start,middle);
    ptr = start;
    for(int i=0; i<middle;i++){
         ptr=ptr->next;
    }
    assert(ptr->data == 333);
    assert(ptr->next->data == init_data); 
    assert(list_length(start) == (len_list+1));
}

void test_insert_location_outofrange(){
    int len_list, init_data, out_of_range;
    len_list = list_length(start);
    out_of_range = len_list*2;
    struct node *new_start;
    int errnum;
    start = insert_location(start,out_of_range);
    assert(list_length(start) == len_list);
}


void test_insert_location_end(){
    int len_list, init_data, end;
    len_list = list_length(start);
    end = len_list;
    struct node *ptr;
    ptr = start;
    while(ptr->next != NULL){
         ptr=ptr->next;
    }
    init_data = ptr->data;
    start = insert_location(start,end+1);
    ptr = start;
    for(int i=0; i<end;i++){
         ptr=ptr->next;
    }
    assert(ptr->data == init_data);
    assert(ptr->next->data == 10); 
    assert(list_length(start) == (len_list+1));
}

void test_insert_location_start(){
    int len_list, init_data;
    init_data = start -> data;
    len_list = list_length(start);
    start = insert_location(start,0);
    assert(list_length(start)==(len_list+1));
    assert(start->next->data == init_data);
}


