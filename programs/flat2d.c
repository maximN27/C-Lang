#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct flat2d {
    size_t rows;
    size_t cols;
    int data[];
};

/* Create a flat2d struct with space for array at end. */
struct flat2d *createFlat2d(size_t rows, size_t cols) {
    struct flat2d *a = malloc(sizeof(struct flat2d) + sizeof(int) * rows * cols);
    assert(a);

    a -> rows = rows;
    a -> cols = cols;

    return a;
}
    
int *refFlat2d(struct flat2d *a, int i, int j) {
    if(i > a -> rows || j > a -> cols) {
	return 0;
    }
    else {
	return &a -> data[i * a -> cols + j];
    }
}

void freeFlat2d(struct flat2d *a) {
    free(a);
}

int main(int argc, char **argv) {
    struct flat2d *a;
    int rows, cols;

    if(argc != 3) {
	fprintf(stderr, "Usage %s rows cols\n", argv[0]);
	return 1;
    }

    rows = atoi(argv[1]);
    cols = atoi(argv[2]);

    a = createFlat2d(rows, cols);

    for(int i = 0; i < rows; i++) {
	for(int j = 0; j < rows; j++) {
	    *refFlat2d(a, i, j) = i - j;
	}
    }

     for(int i = 0; i < rows; i++) {
	for(int j = 0; j < rows; j++) {
	    printf("%d\t", *refFlat2d(a, i, j));
	}
	printf("\n");
     }

     freeFlat2d(a);
    
    return 0;
}
