#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct string {
	int length;
	char *data;
};

int main(int argc, char **argv) {	
	struct string s;
	s.data = "Hello World";
	s.length = strlen(s.data);	

	printf("Length: %d\n", s.length);
	printf("String: %s\n", s.data);

	return 0;
}