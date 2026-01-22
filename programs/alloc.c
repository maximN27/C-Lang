#include <stdio.h>
#include <stdlib.h>

int *makeIntArray(size_t n) {
    int *a;

    a = malloc(sizeof(int) *n);
    if(a == 0) abort();

    return a;
}

void destory(int *a) {
    free(a);
}

int main(int argc, char **argv) {
    int *arr, n;
    n = 10;
    arr = makeIntArray(10);

    for(int i = 0; i < n; i++) {
	printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}
