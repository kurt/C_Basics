#include <stdio.h>
#define VER_USE_MYPREPROC                (1)
#define VER_USE_YOURPREPROC              (2)
#define VER_USE_THEIRPREPROC             (3)

#define WHICH_PREPROC                    (VER_USE_YOURPREPROC)

#define MYPREPROCESSOR  10;
#if (WHICH_PREPROC == VER_USE_MYPREPROC)
#define MY_HEIGHT                 (185)
#elif (WHICH_PREPROC == VER_USE_YOURPREPROC) || (WHICH_PREPROC == VER_USE_THEIRPREPROC)
#define MY_HEIGHT                 (190)
#else
#error "Height not defined"
#endif


int main(){
    for(int i = 0; i < 4; i++){

        printf("Today I am: %d cm tall\n\r",MY_HEIGHT);
    }
}
