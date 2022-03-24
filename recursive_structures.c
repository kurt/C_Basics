#include <stdio.h>

struct node {
    char * word;
    int count;
    struct node *left, *right;
};


int main(){

  struct node a = {.word = "hello"};
  printf("%s\n\r", a.word);
}
