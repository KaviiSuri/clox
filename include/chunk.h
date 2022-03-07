#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "common.h"
#include "value.h"

// OpCode is an enum that stores all the OpCodes for the Virtual Machine
typedef enum {
    OP_CONSTANT,            // Load the constant for use (from the value array) - 1 operand => OP_CONSTANT, constantAddress

    // === Unary Operators =============================================
    OP_NEGATE,              // negate top of stack and push back

    // === Binary Operators ============================================ 
    OP_ADD,                 // top1 + top2
    OP_SUBTRACT,            // top1 - top2
    OP_MULTIPLY,            // top1 * top2 
    OP_DIVIDE,              // top1 / top2 

    OP_RETURN,              // Return from the current function

} OpCode;

// Represents a chunk of code. (Implemented as dynamic arrays)
typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    ValueArray constants; // All the constants are maintained in a seperate buffer for later use
    int* lines;  // Array of integers that parallels the bytecodes array and stores line numbers for each one
} Chunk;

void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);
void freeChunk(Chunk *chunk);
int addConstant(Chunk *chunk, Value value); 
#endif
