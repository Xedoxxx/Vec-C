#ifndef VEC_H
#define VEC_H
#define VEC_DEFAULT_CAPACITY 1

#include <stddef.h>
#include <stdbool.h>

/*
  Struct for keep array list
 */
typedef struct vec_t {
    size_t capacity;
    size_t item_size;
    size_t len;
    void* items;
} vec_t;
/* 
  Create new vec_t.
  Return NULL in case of error.
 */
vec_t *vec_new(size_t item_size);

/* 
  Push item to vec_t.
  Return is successful.
 */
bool vec_push(vec_t *vec, void *new_item);

/*
  Get item ptr from vec_t by index.
  Return NULL in case of error.
*/
void *vec_get(vec_t *vec, size_t index);

/* 
  Remove item by index in vec_t. 
  Return deleted item pointer or NULL in case of error.
 */
void *vec_rm(vec_t *vec, size_t index);

/* 
  Absolute remove item by index in vec_t. 
  Return is successful.
 */
bool vec_abs_rm(vec_t *vec, size_t index);

/*
  Free vec_t and inside data.
 */
void vec_free(vec_t *vec);

/*
  Get length of items in vec_t
 */
size_t vec_len(vec_t *vec);

#endif // VEC_H