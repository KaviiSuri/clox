#include <stdio.h>

#include "memory.h"
#include "value.h"

// initialize empty value array
void initValueArray(ValueArray *array) {
    array->values = NULL;
    array->capacity = 0;
    array->count = 0;
}

// write a value to array
void writeValueArray(ValueArray *array, Value value) {
    if(array->capacity < array->count + 1) {
        int oldCapacity = array->capacity;
        array->capacity = GROW_CAPACITY(oldCapacity);
        array->values = GROW_ARRAY(Value, array->values, oldCapacity, array->capacity);
    }
    array->values[array->count] = value;
    array->count++;
}

// free value array and initilaize it to 0
void freeValueArray(ValueArray *array) {
    FREE_ARRAY(array, array->values, array->capacity);
    initValueArray(array);
}

// print Value 
void printValue(Value value) {
    printf("%g", value);
}
