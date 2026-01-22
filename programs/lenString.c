#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lenString.h"

struct string {
    int length;
    char *data;
};

struct string *makeString(const char *s) {
    struct string *s1 = malloc(sizeof(struct string));
    if(s1 == 0) return 0;

    s1 -> length = strlen(s);
    s1 -> data = malloc(s1 -> length);
    if(s1 -> data == 0) return 0;

    strcpy(s1->data, s);

    return s1;
}

void destoryString(struct string *s) {
    free(s);
}

int getLen(struct string *s) {
    return s -> length;
}

char *getString(struct string *s) {
    return s -> data;
}

int getCharAt(struct string *s, int index) {
    if(index < 0 || index > s-> length) {
	fprintf(stderr, "Invalid index %d\n", index);
	return 0;
    }

    return s -> data[index];
}

int appendString(struct string *ls, char *s) {
    int newLength = strlen(ls -> data) + strlen(s) + 1;

    ls -> data = realloc(ls -> data, newLength);
    if(ls == 0) return 0;

    strcat(ls -> data, s);
}
