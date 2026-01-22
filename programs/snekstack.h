#include <stdlib.h>

typedef struct Stack {
    size_t count;
    size_t capacity;
    void **data;
} stack_t;

// Create a new stack
stack_t *stack_new(size_t capacity);

// Push a new data
void stack_push(stack_t *stack, void *obj);
