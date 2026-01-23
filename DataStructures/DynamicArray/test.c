#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "array.h"

int main(int argc, char **argv) {
    if (argc != 2) {
	fprintf(stderr, "Usage %s n", argv[0]);
	exit(1);
    }

    array_t *arr = makeArray();
    size_t n = strtoull(argv[1], 0, 0);

    for(size_t i = 0; i < n; i++) {
	assert(arrayGet(arr, i) == 0);
	assert(arraySet(arr, i, i) == i);
	assert(arrayGet(arr, i) == i);
    }
    printf("Passed test 1\n");

    // One more pass to check
    for(size_t i = 0; i < n; i++) {
	assert(arrayGet(arr, i) == i);
    }
    printf("Passed test 2\n");

    assert(arraySet(arr, 3*n, 12) == 12);
    assert(arraySet(arr, 3*n+1, 13) == 13);
    printf("Passed test 3\n");

    assert(arrayGet(arr, 1ULL << 62) == 0);
    printf("Passed test 4\n");

    destoryArray(arr);

    return 0;
}
