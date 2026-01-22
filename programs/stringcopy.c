#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Given n pointer to idividual strings
 * it will copy them into a malloced array and 
 * can be accessed using a[i] syntax */
char **copyString(size_t n, char *s[]) {
    char **str;
    size_t length;

    // Find the total length of string including the \n
    for(size_t i = 0; i < n; i++) {
	length += strlen(s[i]) + 1;
    }

    // allocate size for the strings
    str = malloc(sizeof(char *) * length + n);

    char *top = (char *) (s + n);
    
    for(size_t i = 0; i < n; i++) {
	strcpy(top, s[i]);
	str[i] = top;
	top += strlen(s[i]) + 1;
    }

    return str;
}

void freeStr(char **s) {
    free(s);
}

int main(int argc, char **argv) {
    char **argv2;

    argv2 = copyString(argc, argv);

    for(size_t i = 0; i < argc; i++) {
	puts(argv[i]);
    }

    freeStr(argv2);

    return 0;
}
