#include <stdio.h>
#include <stdbool.h>



void printOutCorrectResponse(bool input){
     printf("The answer is: %s\n\r", input ? "Kurt" : "Joshua");

     return;
}


int main(){

printf("Who is cooking supper?\n\r");
bool input = 1;
printOutCorrectResponse(input);
input = 0;
printOutCorrectResponse(input);

}
