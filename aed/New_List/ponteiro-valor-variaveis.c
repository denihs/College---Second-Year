#include <stdio.h>

int main() {
    int  x, y, *p;
    y  =  0;
    p  =  &y;
    x  =  *p;
    x  =  4;
    (*p)++;
    --x;
    (*p)  +=  x;

    printf("\nX = %d\nY = %d\nP = %p\n\n", x, y, p);
    return 0;
}