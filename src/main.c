#include "vec.h"
#include <stdio.h>

int main() {
    /* create new vec_t */
    vec_t* vec = vec_new_int();
    
    /* add items to vec */
    vec_push_int(vec, 828);
    vec_push_int(vec, 9182);
    vec_push_int(vec, -7282);
    vec_abs_rm(vec, 0);
    
    /* print info about vec */
    printf("Item in 0 index: %d\n", vec_get_int(vec, 0));
    printf("Length of vec: %ld\n", vec_len(vec));
    
    /* free vec */
    vec_free(vec);
    
    return 0;
}