#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int min(int a, int b){
    if(a <= b){
        return a;
    }
    else{
        return b;
    }
}


int main() 
{

    int N;
    int minval, curval;
    scanf("%d", &N);
  	// Complete the code to print the pattern.
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            minval = min(i,j);
            curval = N - minval + 1;
            printf("%d ",curval);
        }
        for(int j = N - 1; j >= 1; j--){
            minval = min(i,j);
            curval = N - minval + 1;
            printf("%d ",curval);
        }
        printf("\n");
    }
    for(int i = N - 1; i >= 1; i--){
        for(int j = 1; j <= N; j++){
            minval = min(i,j);
            curval = N - minval + 1;
            printf("%d ",curval);
        }
        for(int j = N - 1; j >= 1; j--){
            minval = min(i,j);
            curval = N - minval + 1;
            printf("%d ",curval);
        }
        printf("\n");
    }
    
    return 0;
}
