#include <stdio.h>
#include "queue.h"


#define INPUT_SIZE    (100)

const char menu_string[] =  "**********************  MENU  **************************\n" \
                            "'+' Push string\n'-' Pop string\n'*' Print the queue\n'/' Exit from the program\n'm' See this menu\n" \
                            "********************************************************\n";

void print_queue(void)
{
    printf("\nQueue\n");
    printf("---------\n");
    if (queue.counter == 0) {
        printf("Empty queue!\n");
    }
    else {
        for (int i = 0, tail = queue.tail; i < queue.counter; ++i) {
            printf("%d: [%s]\n", i, queue.string[tail++]);
            if (tail == QUEUE_SIZE) {
                tail = 0;
            }
        }
    }
    printf("---------\n\n");
}

int main(void)
{
    char input[INPUT_SIZE] = { 0 };
    char ch = 0;

    printf("%s", menu_string);

    do {
        printf("\nMenu command: ");
        gets_s(input, INPUT_SIZE);
        ch = input[0];
        switch (ch) {
            case'+': {
                printf("Enter string to push to queue: ");
                gets_s(input, INPUT_SIZE);
                push(input);
                break;
            }
            case'-': {
                char* str = pop();
                printf("Popping string: '%s'\n", str);
                free(str);
                break;
            }
            case'*': {
                print_queue();
                break;
            }
            case'/': {
                printf("\nGOOD BYE!..\n\n");
                break;
            }
            case'm': {
                printf("%s", menu_string);
                break;
            }
            default: {
                printf("Undefined input!\n");
                break;
            }
        }
    } while (ch != '/');

    return 0;
}
