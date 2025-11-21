#include "vec.h"
#include <stdio.h>

int main() {
    /* create new vec_t */
    vec_t* vec = vec_new_int();
    
    vec_push_int(vec, 828);
    vec_push_int(vec, 9182);
    vec_push_int(vec, -7282);
    
    printf("Item in 2 index: %d\n", vec_get_int(vec, 2));
    
    vec_free(vec);
    
    return 0;
}