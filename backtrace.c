/*
    backtrace.c this needs to be compiled as: gcc -rdynamic backtrace.c -o my_program
    the rdynamic optimization is needed
*/
#include <execinfo.h>
#include <stdio.h>
#include <string.h>

#define MAX_DEPTH 64

void check_function_in_stack(const char* function_name) {
    void *buffer[MAX_DEPTH];
    int depth;
    char **symbols;

    depth = backtrace(buffer, MAX_DEPTH);
    symbols = backtrace_symbols(buffer, depth);

    for (int i = 0; i < depth; i++) {
        if (strstr(symbols[i], function_name) != NULL) {
            printf("Function %s is in the call stack\n", function_name);
            return;
        }
    }

    printf("Function %s is not in the call stack\n", function_name);
}

void my_function() {
    check_function_in_stack("my_function");
}

int main() {
    my_function();
    return 0;
}
