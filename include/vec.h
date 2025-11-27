#ifndef VEC_H
#define VEC_H
#define VEC_DEFAULT_CAPACITY 1

#include <stddef.h>
#include <stdbool.h>

typedef char* string;

/*
  Struct for keep array list
 */
typedef struct vec_t {
    size_t capacity;
    size_t item; // Bytes for one item
    size_t len;
    void* items;
} vec_t;

/*
  Create new vec_t.
  Return NULL in case of error.
 */
vec_t* vec_new(size_t item);

/*
  Free vec_t and inside data.
 */
void vec_free(vec_t *vec);

/*
  Push item to vec_t.
  Return is successful.
 */
bool vec_push(vec_t *vec, void *new_item);

/*
  Get item ptr from vec_t by index.
  Return NULL in case of error.
*/
void* vec_get(vec_t *vec, size_t index);

/*
  Safely get item ptr from vec_t by index.
  Return NULL in case of error.
*/
void* vec_gets(vec_t* vec, size_t index);

/* 
  Remove item by index in vec_t. 
  Return is successful.
 */
bool vec_rm(vec_t *vec, void* buffer, size_t index);

/* 
  Absolute remove item by index in vec_t. 
  Return is successful.
 */
bool vec_abs_rm(vec_t *vec, size_t index);

/*
  Remove items in range.
  Return is successful.
 */
bool vec_rm_range(vec_t* vec, void* buffer, size_t from, size_t to);

/*
  Absolute remove items in range.
  Return is successful.
 */
bool vec_abs_rm_range(vec_t* vec, size_t from, size_t to);

/*
  Get length of items in vec_t
 */
size_t vec_len(vec_t *vec);

/*
  Find index of pointer.
  Return index of item or -1 in case of error.
 */
int vec_indexof(vec_t* vec, void* to_find);

/* macros for comfortable using types */
#define GEN_FUNCS_FOR_TYPE(TYPE) \
    static inline bool vec_push_##TYPE(vec_t *vec, TYPE new_item) {\
        return vec_push(vec, &new_item); \
    } \
    static inline TYPE vec_get_##TYPE(vec_t *vec, size_t index) {\
        TYPE* ptr = (TYPE*) vec_get(vec, index); \
        return ptr ? *ptr : (TYPE){0};\
    }\
    static inline vec_t* vec_new_##TYPE() {\
        return vec_new(sizeof(TYPE));\
    }

/* Example use
GEN_FUNCS_FOR_TYPE(int);
GEN_FUNCS_FOR_TYPE(float);
GEN_FUNCS_FOR_TYPE(double);
 */

#endif // VEC_H