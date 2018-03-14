#include <stdio.h>

int isBi(int V);

int main() {
    int a = 2012;
    if (isBi(a)) {
        printf("Is BI");
    }else {
        printf("Isn't Bi");
    }
    return 0;
}

int isBi(int V) {
    if (V % 400 == 0) {
        return 1;
    }else if ( V % 4 == 0 && V % 100 != 0 ){
        return 1;
    }
    return 0;
}