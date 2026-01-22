#include <stdio.h>

#include "snekstack.h"

int main() {
    stack_t *stack = stack_new(10);
    stack_push(stack, 10);
    
    return 0;
}
