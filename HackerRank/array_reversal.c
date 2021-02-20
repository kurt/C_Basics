#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }

    
    /* Write the logic to reverse the array. */
    int temp_val;
    for(int j = 0; j <= num/2 + num%2 - 1; j++){
        temp_val = arr[j];
        arr[j] = arr[num - 1 - j];
        arr[num - 1 - j] = temp_val;
    }
    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
