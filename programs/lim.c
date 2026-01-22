#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    printf("Int: %zu bytes %zu bits\n", sizeof(int), sizeof(int) * CHAR_BIT);

    return 0;
}
