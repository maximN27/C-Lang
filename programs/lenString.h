/*
struct string {
    int length;
    char *data;
};
*/

/* Create a length string */
struct string *makeString(const char *s);

/* Free the struct */
void destoryString(struct string *s);

/* Get the length of lenString */
int getLen(struct string *s);

/* Get the string from the struct */
char *getString(struct string *s);

/* Get a char from string */
int getCharAt(struct string *s, int index);

/* Append a string to the end of another len string */
int appendString(struct string *ls, char *s);
