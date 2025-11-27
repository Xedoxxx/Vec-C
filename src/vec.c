#include "vec.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

vec_t* vec_new(size_t item) {
    vec_t* vec = (vec_t*) malloc(sizeof(vec_t));
    if(!vec) {
        fprintf(stderr, "Error allocating memory for vec_t");
        return NULL;
    }
    
    vec->capacity = VEC_DEFAULT_CAPACITY;
    vec->len = 0;
    vec->item = item;
    
    void* items = (void*) malloc(item * vec->capacity);
    if(!items) {
        free(vec);
        fprintf(stderr, "Error allocating memory for items in vec_t");
        return NULL;
    }
    vec->items = items;
    return vec;
}

int vec_indexof(vec_t* vec, void* to_find) {
    for (int i=0; i<vec->len; i++) {
        void* item = (char*)vec->items + i * vec->item;
        if (item == to_find) {
            return i;
        }
    }
    return -1;
}

bool vec_push(vec_t* vec, void* new_item) {
    if(!vec) {
        fprintf(stderr, "vec_push: Pointer of vec_t cannot be NULL");
        return false;
    }
    if(!new_item) {
        fprintf(stderr, "vec_push: Pointer of item for vec_t cannot be NULL");
        return false;
    }
    if(vec->len + 1 > vec->capacity) {
        vec->capacity *= 2;
        size_t new_size = vec->capacity * vec->item;
        void* new_items = (void*) realloc(vec->items, new_size);
        
        if(!new_items) {
            fprintf(stderr, "vec_push: Error reallocating memory for items in vec_t");
            return false;
        }
        vec->items = new_items;
    }
    void* start = (char*) vec->items + (vec->len*vec->item);
    memcpy(start, new_item, vec->item);
    vec->len += 1;
    return true;
}

void* vec_gets(vec_t* vec, size_t index) {
    if(index >= vec->len) {
        fprintf(stderr, "vec_gets: Index out of bounds: %ld", index);
        return NULL;
    }
    return vec_gets(vec, index);
}

void* vec_get(vec_t* vec, size_t index) {
    return (char*) vec->items + index * vec->item;
}

bool vec_rm(vec_t* vec, void* buffer, size_t index) {
    if(index >= vec->len) {
        fprintf(stderr, "vec_rm: Index out of bounds: %ld", index);
        return false;
    }
    memcpy(buffer, (char*) vec->items + (vec->item*index), vec->item);
    
    /* Moving items back after index */
    if(index < vec->len - 1) {
        memmove((char*)vec->items+index, (char*)vec->items+index+1, (vec->len - index-1) * vec->item);
    }    
    vec->len -= 1;
    return true;
}

bool vec_rm_range(vec_t* vec, void* buffer, size_t from, size_t to) {
    if(from >= vec->len) {
        fprintf(stderr, "vec_rm_range: The from index out of bounds: %ld", from);
        return false;
    } else if(to >= vec->len) {
        fprintf(stderr, "vec_rm_range: The to index out of bounds: %ld", to);
        return false;
    }
    if(from>to) {
        size_t bff = from;
        from = to;
        to = bff;
    }
    memcpy(buffer, (char*) vec->items + (vec->item*from), vec->item * (to-from));
    /* Moving items back after the to index */
    char* items = (char*)vec->items;
    if(to < vec->len - 1) {
        memmove(items+from*vec->item, 
            items+(from+1)*vec->item, 
            (vec->len-to-1)*vec->item);
    }    
    vec->len -= (to - from) + 1;
    return true;
}

bool vec_abs_rm_range(vec_t* vec, size_t from, size_t to) {
    if(from >= vec->len) {
        fprintf(stderr, "vec_abs_rm_range: The from index out of bounds: %ld", from);
        return false;
    } else if(to >= vec->len) {
        fprintf(stderr, "vec_abs_rm_range: The to index out of bounds: %ld", to);
        return false;
    }
    if(from>to) {
        size_t bff = from;
        from = to;
        to = bff;
    }
    char* items = (char*)vec->items;
    if(to < vec->len - 1) {
        memmove(items+from*vec->item, 
            items+(from+1)*vec->item, 
            (vec->len-to-1)*vec->item);
    }    
    vec->len -= (to - from) + 1;
    return true;
}

bool vec_abs_rm(vec_t* vec, size_t index) {
    if(index >= vec->len) {
        fprintf(stderr, "vec_rm: Index out of bounds: %ld", index);
        return false;
    }
    
    /* Moving items back after index */
    if(index < vec->len - 1) {
        memmove((char*)vec->items+index, (char*)vec->items+index+1, (vec->len - index-1) * vec->item);
    }    
    vec->len -= 1;
    return true;
}

void vec_free(vec_t* vec) {
    free(vec->items);
    free(vec);
}

size_t vec_len(vec_t* vec) {
    return vec->len;
}