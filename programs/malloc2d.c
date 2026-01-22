#include <stdio.h>
#include <stdlib.h>

/* Frees a given 2d array */
void free2d(void **a) {
    // Free the main array
    free(a[0]);

    // Free the array of pointers
    free(a);
}

/* Creates a 2d array and returns pointer to it
 * Caller is responsible for clearing using free2d
 */
void **malloc2d(size_t numRows, size_t rowSize) {
    void **a;

    // allocate space for pointers
    a = malloc(sizeof(void *) * numRows);
    if(a == 0) {
	return 0;
    }

    // allocate the space for actual data
    a[0] = malloc(numRows * rowSize);
    if(a[0] == 0) {
	free(a);
	return 0;
    }

    // assing the pointers
    for(size_t i = 1; i < numRows; i++) {
	a[i] = a[0] + i * rowSize;
    }

    return a;
}

int main(int argc, char **argv) {
    int rows, cols;
    int **a;

    if(argc != 3) {
	fprintf(stderr, "Usage %s rows cols\n", argv[0]);
	return 1;
    }

    rows = atoi(argv[1]);
    cols = atoi(argv[2]);

    a = (int **) malloc2d(rows, sizeof(int) * cols);
    if(a == 0) {
	fprintf(stderr, "Malloc2d failed!\n");
	return 1;
    }

    for(size_t i = 0; i < rows; i++) {
	for(size_t j = 0; j < cols; j++) {
	    a[i][j] = i - j;
	}
    }

    for(size_t i = 0; i < rows; i++) {
	for(size_t j = 0; j < cols; j++) {
	    printf("%d\t", a[i][j]);
	}
	printf("\n");
    }

    free2d((void **) a);
    
    return 0;
}
