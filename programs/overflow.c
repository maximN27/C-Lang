#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <inttypes.h>

#define MAX_SIZE ((UINT64_MAX - 1) / 3)

int main(int argc, char **argv) {
    uint64_t big;

    if (argc != 2) {
	fprintf(stderr, "Use %s number\n", argv[0]);
	exit(1);
    }

    sscanf(argv[1], "%" SCNu64, &big);

    while (big != 1) {
	printf("%" PRIu64 "\n", big);

	if (big % 2 == 0) 
	    big /= 2;
	else if (big < MAX_SIZE) 
	    big = big * 3 + 1;
	else { 
	    puts("Overflow"); return 0;
	}
    }

    puts("Reached 1\n");


    return 0;
}
