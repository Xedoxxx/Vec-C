#include "vec.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

vec_t* vec_new(size_t item_size) {
    vec_t* vec = (vec_t*) malloc(sizeof(vec_t));
    if(!vec) {
        fprintf(stderr, "Error allocating memory for vec_t");
        return NULL;
    }
    
    vec->capacity = VEC_DEFAULT_CAPACITY;
    vec->len = 0;
    vec->item_size = item_size;
    
    void* items = (void*) malloc(item_size * vec->capacity);
    if(!items) {
        free(vec);
        fprintf(stderr, "Error allocating memory for items in vec_t");
        return NULL;
    }
    vec->items = items;
    return vec;
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
        size_t new_size = vec->capacity * vec->item_size;
        void* new_items = (void*) realloc(vec->items, new_size);
        
        if(!new_items) {
            fprintf(stderr, "vec_push: Error reallocating memory for items in vec_t");
            return false;
        }
        vec->items = new_items;
    }
    void* start = (char*) vec->items + (vec->len*vec->item_size);
    memcpy(start, new_item, vec->item_size);
    vec->len += 1;
    return true;
}

void* vec_get(vec_t* vec, size_t index) {
    if(index >= vec->len) {
        fprintf(stderr, "vec_get: Index out of bounds: %ld", index);
        return NULL;
    }
    return (char*) vec->items + index * vec->item_size;
    
}

void* vec_rm(vec_t* vec, size_t index) {
    if(index >= vec->len) {
        fprintf(stderr, "vec_rm: Index out of bounds: %ld", index);
        return NULL;
    }
    void* removed = (void*) malloc(vec->item_size);
    if(!removed) {
        fprintf(stderr, "vec_rm: Error allocating memory for return item");
        return NULL;
    }
    memcpy(removed, (char*) vec->items + (vec->item_size*index), vec->item_size);
    
    /* Moving items back after index */
    for(int i=index+1; i<vec->len; ++i) {
        void* to = (char*) vec->items + (i-1)*vec->item_size;
        void* from = (char*) vec->items + i * vec->item_size;
        memmove(to, from, vec->item_size);
    }
    vec->len -= 1;
    return removed;
}

bool vec_abs_rm(vec_t* vec, size_t index) {
    if(index >= vec->len) {
        fprintf(stderr, "vec_rm: Index out of bounds: %ld", index);
        return false;
    }
    
    /* Moving items back after index */
    for(int i=index+1; i<vec->len; ++i) {
        void* to = (char*) vec->items + (i-1)*vec->item_size;
        void* from = (char*) vec->items + i * vec->item_size;
        memmove(to, from, vec->item_size);
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