/*
Implement a message queue which has a fixed length of 64 elements and each element stores a string with  a dynamic length.Please implement
•   Push
•   Pop
•   The queue definition itself

[][][][][]
[hello][][][][]               push(“hello”)
[hello][world][][][]               push(“world”)
[hello][world][!][][]               push(“!”)

[][world][!][][]               pop() > returns “hello”
*/
#include <stdio.h>
#include <stdlib.h> // malloc
#include <string.h> // strlen memcpy
#include "queue.h"

queue_t queue;

void push(const char* new_str)
{
    if (queue.counter >= QUEUE_SIZE || new_str == NULL) {
        return;
    }
    char* str = malloc(strlen(new_str) + 1);
    if (str == NULL) {
        return;
    }
    memcpy(str, new_str, strlen(new_str) + 1);
    queue.string[queue.head++] = str;
    if (queue.head == QUEUE_SIZE) {
        queue.head = 0;
    }
    ++queue.counter;
}

/* return pointer value must be freeded after usage! */
char* pop()
{
    if (queue.counter == 0) {
        return NULL;
    }
    char* str = queue.string[queue.tail++];
    if (queue.tail == QUEUE_SIZE) {
        queue.tail = 0;
    }
    --queue.counter;
    return str;
}
