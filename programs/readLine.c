#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INITIAL_LINE_LENGTH (2)

char *getLine() {
    char *line;
    int size, length;
    char c;

    size = INITIAL_LINE_LENGTH;

    line = malloc(size);
    assert(line);
    length = 0;

    while(((c = getchar()) != EOF) && (c != '\n')) {
	/* check is length is greater than size
	 * if yes allcoate more size */
	while(length >= size - 1) {
	    size *= 2;

	    line = realloc(line, size);
	    assert(line);
	}

	line[length++] = c;
    }
    line[length] = '\0';

    return line;
}

int main(int argc, char **argv) {
    char *name;

    printf("Enter your name: ");
    name = getLine();

    printf("Hi %s\n", name);

    free(name); // Very Very Important!!
    
    return 0;
}
