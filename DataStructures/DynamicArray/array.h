// A simple dynamic array implementation
// It doesn't need explicit growing and shrinking, it is handled automatically.
//

typedef struct Array array_t;

// Create an array
array_t *makeArray(void);

// Return the value in array at given position
int arrayGet(array_t *, size_t position);

// Set the value in an array at given position. Returns the new value
int arraySet(array_t *, size_t position, int value);

// Free all space used by an array.
void destoryArray(array_t *);
