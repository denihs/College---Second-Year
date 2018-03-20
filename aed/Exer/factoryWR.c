#include <stdio.h>

int fac(int x);

int main() {
    int x = fac(-1);
    if (x) {
        printf("\n\n%d\n\n", x);
    }
    return 0;
}

int fac(int x) {
    if ( x == 0 ) { return 1; }
    else if( x < 0 ) { printf("\n\nVocê é zueiro mesmo em\n\n"); return 0; }
    int facValue = x;
    for (int i=x; i > 1; i--){
        facValue = facValue * (i-1);
    }
    return  facValue;

}