#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "array.h"

#define INITIALSIZE (16)
#define SIZEMULTIPLIER (2)

struct Array {
    size_t size;
    int *data;
};

array_t *makeArray(void) {
    array_t *arr = malloc(sizeof(array_t));
    assert(arr);

    arr->size = INITIALSIZE;
    
    // calloc zeros out array
    arr->data = calloc(arr->size, sizeof(int));
    assert(arr->data);

    return arr;
}

static void resizeArray(array_t *arr, size_t position) {
    if (position >= arr->size) {
	size_t newSize = arr->size * SIZEMULTIPLIER;

	if(position >= newSize) {
	    newSize = position + 1;
	}

    	arr->data = realloc(arr->data, sizeof(int) * newSize);
    	assert(arr->data);

    	memset(&arr->data[arr->size], 0, sizeof(int) * (newSize - arr->size));

    	arr->size = newSize;
    }
}

int arrayGet(array_t *arr, size_t position) {
    if (position >= arr->size) return 0;

    return arr->data[position];
}

int arraySet(array_t *arr, size_t position, int value) {
    resizeArray(arr, position);

    arr->data[position] = value;

    return arr->data[position];
}

void destoryArray(array_t *arr) {
    free(arr->data);
    free(arr);
}
