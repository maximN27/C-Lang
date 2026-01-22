#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char **argv) {
    char c;
    int i;
    short s;
    long l;
    long long ll;

    if (argc != 2) {
	fprintf(stderr, "Usage %s n\n", argv[0]);
	exit(1);
    }

    c = atoi(argv[1]);
    i = atoi(argv[1]);
    s = atoi(argv[1]);
    l = atoi(argv[1]);
    ll = atoi(argv[1]);

    printf("char: %d\nint: %d\nlong: %ld\nlong long: %lld\n", c, i, l, ll);

    return 0;
}
