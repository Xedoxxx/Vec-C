#include "vec.h"
#include <stdio.h>
#include <assert.h>

int main(void) {
    printf("\033[35mTesting vec int...\033[0m\n");
    /* create new vec_t */
    vec_t* vec = vec_new_int();
    assert(vec);
    
    /* add items to vec */
    vec_push_int(vec, 828);
    vec_push_int(vec, 9182);
    vec_push_int(vec, -7282);
    vec_abs_rm(vec, 0);
    
    /* print info about vec */
    int item = vec_gets_int(vec, 0);
    size_t len = vec_len(vec);
    printf("Item in 0 index: %d\n", item);
    printf("Length of vec: %ld\n", len);
    
    /* free vec */
    vec_free(vec);
    printf("\033[34mSuccessful testing vec int...\033[0m\n");
    return 0;
}