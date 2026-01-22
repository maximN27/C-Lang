#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/* returns the next character without consuming it */
int peekchar(void) {
    int c;

    c = getchar();
    if (c != EOF) ungetc(c, stdin);

    return c;
}

/* reads an integer written in decimal notation from stdin until the first
 * non-digit and return it. Returns 0 if there are no digits */
int readNumber(void) {
    int accumulator;	// store the number
    int c;		//store the next character
			//
    accumulator = 0;

    while((c = peekchar()) != EOF && isdigit(c)) {
	c = getchar();
	accumulator *= 10;
	accumulator += (c - '0');
    }

    return accumulator;
}

int main(int argc, char **argv) {
    int c; // storing the peekchar output
    char i; // storing the stdin output

    c = peekchar();
    scanf("%c", &i);

    printf("Peeked: %d\n", c);
    printf("Stdin: %c\n", i);

    return 0;

}
