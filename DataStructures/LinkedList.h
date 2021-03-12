
#ifndef ___LinkedList__
#define ___LinkedList__
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};


struct node *create_ll(struct node *);
struct node * display(struct node *);
struct node *insert_beg(struct node *);
struct node * insert_end(struct node *);
struct node * insert_location(struct node *start, int position);
int list_length(struct node *start);

#endif
