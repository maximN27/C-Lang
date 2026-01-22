#include <stdio.h>
#include <stdlib.h>

typedef enum HttpErrorCodes {
    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_NOT_FOUND = 404,
    HTTP_TEAPOT = 418,
    HTTP_INTERNAL_SERVER_ERROR = 500
} HttpErrorCode;

void printErrorMessage(HttpErrorCode code) {
    switch(code) {
	case HTTP_BAD_REQUEST:
	    puts("Bad Request Error");
	    break;
	case HTTP_UNAUTHORIZED:
	    puts("Unauthorized access");
	    break;
	case HTTP_NOT_FOUND:
	    puts("Page not found");
	    break;
	case HTTP_INTERNAL_SERVER_ERROR:
	    puts("Internal Server Error");
	    break;
	 default:
	    puts("Not an HTTP error");
	    break;
    }
}

int main(int argc, char **argv) {
    if(argc != 2) {
	fprintf(stderr, "Usage %s code\n", argv[0]);
	exit(1);
    }

    int code = atoi(argv[1]);

    printErrorMessage(code);

    return 0;
}
