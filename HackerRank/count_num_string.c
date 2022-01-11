#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s,strlen(s) +1);
    //printf("%s\n", s);
    size_t length;
     length = strlen(s); 
    int count[10] = {0};
    int y;    
    int i = 0;
    for(int k = 0; k < length; k++){
    //while(s[i] != '\n'){
        //y = atoi();
        switch (s[i]) {
            case '0' :
                count[0] ++;
                break;
            case '1' :
                count[1] ++;
                break;
            case '2' :
                count[2] ++;
                break;   
            case '3' :
                count[3] ++;
                break;
            case '4' :
                count[4] ++;
                break;
            case '5' :
                count[5] ++;
                break;
            case '6' :
                count[6] ++;
                break;
            case '7' :
                count[7] ++;
                break;
            case '8' :
                count[8] ++;
                break;
            case '9' :
                count[9] ++;
                break;
            default:
                //a letter or other character
                //printf("non number found\n");
                break;
        }   
        i ++;
    }
    for(int j = 0; j <=9; j ++){
        printf("%d ", count[j]);
    }
    printf("\n");

    //free pointer s
    free(s);
    return 0;
}

