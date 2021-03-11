

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *create_ll(struct node *);
struct node * display(struct node *);
struct node *insert_beg(struct node *);
struct node * insert_end(struct node *);
struct node * insert_location(struct node *start, int position);
int list_length(struct node *start);

int main(){
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


struct node *create_ll(struct node *start){
    struct node *new_node;
    int num;
    for(int i=0;i<6;i++){
        new_node = (struct node*)malloc(sizeof(struct node*));
        new_node -> data = i;
        if(start == NULL){
            new_node -> next = NULL;
            start = new_node;
        }
        else{
            new_node->next = start;
            start = new_node;
        }
    }
    return start;
}

struct node * display(struct node *start){
    struct node *ptr;
    ptr = start;
    printf("\n");
    while(ptr != NULL){
        printf("\t %d", ptr -> data);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}

struct node *insert_beg(struct node *start){
    struct node *new_node;
    int num = 99;
    new_node=(struct node *)malloc(sizeof(struct node *));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    return start;
}

struct node * insert_end(struct node *start){
/*
    Returns: a pointer to a node structure
    Takes:   pointer to a node structure
    Modifies: the linked list
*/
    struct node *ptr, *new_node;
    int new_data = 10;
    new_node = (struct node *)malloc(sizeof(struct node *));
    new_node->data = new_data;
    ptr = start;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = new_node;
    new_node->next = NULL;
    return start;
}

struct node * insert_location(struct node *start, int position){
    if(position>list_length(start)){
        perror("position out of range");
        exit(EXIT_FAILURE);
    }
    int END_FLAG = 0;
    if(position == list_length(start)){
        start = insert_end(start);
        return start;
    }
    if(position == 0){
         //do nothing
         start = insert_beg(start);
         return start; 
    }
    struct node *ptr, *new_node;
    int new_data = 333, count =0;
    new_node = (struct node *)malloc(sizeof(struct node *));
    new_node -> data = new_data;
    ptr = start;
    while(count < position-1 && ptr->next !=NULL){
         ptr = ptr->next;
         //could throw a runtime error here if list length is an issue;
         count++;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
    return start;
}

int list_length(struct node *start){
    int count = 0;
    struct node *ptr;
    ptr = start;
    while(ptr->next != NULL){
        ptr=ptr->next;
        count++;
    }
    return count;
}
