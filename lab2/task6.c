#include <stdio.h>
#include "stack.c"


int main(int argc, char* argv[]) {
    stack* qwe = NULL;

    char c = '\0';
    double tmp = 0;
    printf("1 - check if stack empty\n2 - push 5 elements to stack\n3 - pop 5 elements from stack\n4 - peek last element\n5 - get stack size\n6 - push to stack\n7 - pop from stack\n8 - print stack\n9 - dispose stack\n0 - exit\nEnter number 0-9: ");
    scanf(" %c", &c);
    while (c != '0')
    {
        system("clear");
        switch (c)
        {
            case '1':
                printf("Is stack empty: %d\n", empty(qwe));
                break;
            case '2':
                for (int i = 0; i < 5;) {
                    printf("Enter %d element: ", ++i);
                    scanf("%lf", &tmp);
                    push(&qwe, tmp);
                }
                break;
            case '3':
                for (int i = 0; i < 5; i++)
                    pop(&qwe);
                printf("pop 5 elements\n");
                break;
            case '4':
                printf("Top element on stack: %lf\n", peek(qwe));
                break;
            case '5':
                printf("Stack size: %d\n", size(qwe));
                break;
            case '6':
                printf("Enter element to push: \n");
                scanf("%lf", &tmp);
                push(&qwe, tmp);
                break;
            case '7':
                pop(&qwe);
                printf("pop 1 element\n");
                break;
            case '8':
                print_stack(qwe);
                break;
            case '9':
                dispose(&qwe);
                printf("Stack disposed\n");
                break;
            default:
                break;
        }

        printf("\n1 - check if stack empty\n2 - push 5 elements to stack\n3 - pop 5 elements from stack\n4 - peek last element\n5 - get stack size\n6 - push to stack\n7 - pop from stack\n8 - print stack\n9 - dispose stack\n0 - exit\nEnter number 0-9: ");
        scanf(" %c", &c);
    }
    
    return 0;
}
