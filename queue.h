#pragma once

#include <stdint.h>

#define QUEUE_SIZE  (5)

typedef struct {
    char* string[QUEUE_SIZE];
    uint32_t counter;
    uint32_t head;
    uint32_t tail;
}queue_t;

extern queue_t queue;

void push(const char* new_str);
char* pop();
