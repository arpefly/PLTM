#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

#define STACK_UNDERFLOW -100
#define STACK_OVERFLOW -101
#define MAXSTACK 1000000


int stackcount = 0;
typedef double T;
typedef struct stack {
    T value;
    struct stack *next;
} stack;

stack* init(T n);
stack* push(stack** head, T n);
T pop(stack** head);
T peek(stack* head);
size_t size(stack* head);
int empty(stack* head);
void dispose(stack** head);

stack* init(T n) {
    stack* new_stack = (stack*)malloc(sizeof(stack));
    if (new_stack == NULL) {
        printf("Allocation memory error");
        return NULL;
    }

    new_stack->value = n;
    new_stack->next = NULL;

    return new_stack;
}

size_t size(stack *head) {
    size_t size = 0;
    while (head) {
        size++;
        head = head->next;
    }
    
    return size;
}

int empty(stack *head) {
    if (head == NULL)
        return 1;
    else
        return 0;
}

T peek(stack *head) {
    if (head != NULL)
        return head->value;
    else
        return -1;
}

stack* push(stack **head, T n) {
    if (stackcount == MAXSTACK) {
        printf("STACK_OVERFLOW\n");
        exit(STACK_OVERFLOW);
    }

    stack* new_stack = init(n);

    if (new_stack == NULL) {
        return *head;
    }

    new_stack->next = *head;
    *head = new_stack;

    stackcount++;
    return new_stack;
}

T pop(stack **head) {
    if (*head == NULL) exit(STACK_UNDERFLOW);

    stack *out = *head;
    T val;

    *head = (*head)->next;
    val = out->value;
    free(out);

    stackcount--;
    return val;
}

void dispose(stack **head) {
    stack* ant = *head, *tmp = NULL;
    while (ant) {
        tmp = ant;
        ant = ant -> next;
        free(tmp);
    }
    free(ant);
}
