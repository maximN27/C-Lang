#include <stdio.h>
#include <stdlib.h>

int *readIntegers(int *count) {
    int mycount, *a, size, n;
    size = 1;

    a = malloc(sizeof(int) * size); // The memory block
    if(a == 0) abort();

    while(scanf("%d", &n) == 1) {
	// reallocate with double the size
	while(mycount >= size) {
	    size *= 2;
	    a = realloc(a, sizeof(int) * size);
	}

	// assign the value
	a[mycount++] = n;
    }
    a = realloc(a, sizeof(int) * mycount);

    *count = mycount;

    return a;
}

int main(int argc, char ** argv) {
    int *nums;
    int count;

    nums = readIntegers(&count);

    for(int i = 0; i < count; ++i) {
	printf("%d\t", nums[i]);
    }
    printf("\n");

    return 0;
}
