#include <stdbool.h>
#include <stdio.h>

void print_static(void){
    static bool testVal = true;
    printf("The value of the static is: %d\n\r", testVal);
    testVal = false;
}


int main(){
    for(int i = 0; i < 5; i++){
        print_static();
    }
}
