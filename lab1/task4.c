#include <stdio.h>

int main()
{
    double a, b, c;
    
    printf("a=");
    scanf("%lf", &a);
    printf("b=");
    scanf("%lf", &b);
    printf("c=");
    scanf("%lf", &c);
    printf("\n");
    
    if (a != 0)
        printf("x=%lf\n", (c-b)/a);
    else
        printf("ERROR: Divide by zero\n");

	return 0;
}