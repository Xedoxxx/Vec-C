#include "vec.h"
#include <stdio.h>

int main() {
    /* create new vec_t */
    vec_t* vec = vec_new(sizeof(int));
    
    /* Add test items */
    int one = 272;
    int two = -2;
    int three = 817172;
    vec_push(vec, &one);
    vec_push(vec, &two);
    vec_push(vec, &three);
    
    int* getted = vec_get(vec, 2);
    printf("Item in 2 index: %d\n", *getted);
    
    vec_free(vec);
    
    return 0;
}