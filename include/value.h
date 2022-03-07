#ifndef CLOX_VALUE_H
#define CLOX_VALUE_H

#include "common.h"

// All values must be double precision floating-point numbers for now
typedef double Value;

// A dynamically allocated array for `Values`
typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray *array);
void writeValueArray(ValueArray *array, Value value);
void freeValueArray(ValueArray *array);
void printValue(Value value);

#endif

