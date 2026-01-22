#include <stdio.h>
#include <stdlib.h>

static int compareInt(const void *key1, const void *key2) {
    return *((int *) key1) - *((int *) key2);
}

void sort_int_array(int *a, int n) {
    qsort(a, 10, sizeof(*a), compareInt);
}

int main(int argc, char **argv) {
    int arr[10] = {100, 50, 20, 10, 60, 90, 30, 70, 40, 80};
    int n = 10;

    sort_int_array(arr, 10);

    for(int i = 0; i < 10; i++) {
	printf("%d\t", arr[i]);
    }
    printf("\n");

    return 0;
}
