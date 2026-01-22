#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char *strcatAlloc(const char *s1, const char *s2) {
    char *res;
    size_t length = strlen(s1) +  strlen(s2) + 1;

    res = malloc(length);
    assert(res);
    char *pos = res;

    while(*s1) *pos++ = *s1++;
    while(*s2) *pos++ = *s2++;

    *pos = '\0';

    return res;
}

int main(int argc, char **argv) {
    char *s1 = argv[1];
    char *s2 = argv[2];

    if(argc != 3) {
	fprintf(stderr, "Usage %s string1 string2\n", argv[0]);
	exit(1);
    }

    char *res;

    res = strcatAlloc(s1, s2);

    puts(res);

    free(res);
    
    return 0;
}
