#include <stdio.h>
#include "stack.c"

int main(int argc, char* argv[]) {
    stack* qwe = NULL;
    
    printf("Is stack empty: %d\n", empty(qwe));

    for (int i = 0; i < 1000000; i++)
        push(&qwe, i);
    
    printf("Stack with 1 000 000 elements created\n");
    printf("Is stack empty %d\n", empty(qwe));

    printf("Pop 10 last elements:\n");
    
    for (int i = 0; i < 10; i++)
        printf("%lf\n", pop(&qwe));
    
    printf("Enter double to push it 10 times to the stack: ");

    double tmp = 0;
    scanf("%lf", &tmp);

    for (int i = 0; i < 10; i++)
        push(&qwe, tmp);

    printf("Last value in stack: %lf\n", peek(qwe));
    printf("Number of stack elements: %d\n", stackcount);

    printf("Enter 1 000 001 double to push to stack to get STACK OVERFLOW: ");
    scanf("%lf", &tmp);
    push(&qwe, tmp);

    printf("num of stack elements: %d\n", stackcount);
    
    dispose(&qwe);

    return 0;
}
