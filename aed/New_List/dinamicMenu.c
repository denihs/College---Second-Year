#include <stdio.h>

void menu(char v[][100]);

int main () {
    char v[5][100] = {"field 1", "field 2", "field 3", "field 4", "field 5"};
    menu(v);
    return 0;
}

void menu(char v[][100]) {
    printf("-=-=-=-=Menu=-=-=-=-\n");
    for(int i = 0; i < 5; i++) {
        printf("%s\n", v[i]);
    }
    printf("--> ");
}