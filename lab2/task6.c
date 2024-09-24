#include <stdio.h>
#include "stack.c"

int main(int argc, char* argv[]) {
    stack* qwe = init(0);
    
    for (int i = 0; i < 10; i++)
        push(&qwe, i);
    
    for (int i = 0; i < 10; i++)
        printf("%lf\n", pop(&qwe));
    
    dispose(&qwe);

    return 0;
}
