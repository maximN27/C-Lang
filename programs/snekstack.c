#include <stdlib.h>

#include "snekstack.h"

stack_t *stack_new(size_t capacity) {
    stack_t *s = malloc(sizeof(stack_t));

    if(s == 0) {
	return NULL;
    }

    s -> count = 0;
    s -> capacity = capacity;
    s -> data = malloc(sizeof(void *) * s -> capacity);
    if(s -> data = 0) { 
	return NULL;
    }

    return s;
}

void push_stack(stack_t *stack, void *obj) {
    if(stack -> count == stack->capacity) {
	stack -> capacity *= 2;
	stack -> data = realloc(stack -> data, stack -> capacity);
	if(stack -> data == NULL) return;
    }

    stack -> data[(stack -> count)++] = obj;
}

void *stack_pop(stack_t *stack) {
    if (stack -> count == 0) return NULL;
    else if (stack -> count <= (stack -> capacity / 2)) {
	stack -> capacity /= 2;
	stack -> data = realloc(stack -> data, stack -> capacity);
    }

    return stack -> data[stack -> count--];
}
