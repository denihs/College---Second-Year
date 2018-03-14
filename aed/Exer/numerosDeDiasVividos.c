#include <stdio.h>
int dateInDays(int * date);

int main() {
    int a[]={14, 10, 1999};
    printf("%d", dateInDays(a));
    return 0;
}

int dateInDays(int * date) {
    return date[0] + date[1] * 30 + ( ( 2018 - date[2]) * 360 );
}