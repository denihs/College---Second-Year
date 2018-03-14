#include <stdio.h>

int fac(int V);

int main() {
    printf("%d", fac(0));
    return 0;
}

int fac(int V) {
    if (V < 1) {
        return 1;
    }
    return  V * fac(V - 1);

}