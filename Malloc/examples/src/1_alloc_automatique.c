#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

uint fibonacci(uint n)
{
    if (n == 0 || n == 1) {
        return n;
    }
    return (fibonacci(n - 1) + fibonacci(n - 2));
}

int main(int argc, char *argv[])
{
    uint n = 10;

    if (argc == 2) {
        n = atoi(argv[1]);
    }
    printf("fib(%d) = %d\n", n, fibonacci(n));
}
