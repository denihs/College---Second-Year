#include <stdio.h>

void yearOld(int * V);
void allowVote(int a);
void allowDrive(int a);

int main() {
    int a[]={6, 4, 2003};
    yearOld(a);
    return 0;
}

void yearOld(int * V) {
    int year = 2018, month = 03, day = 13;
    if (year - V[2] > 18) {
        if (V[1] - month > 0) {
            printf("You're %d", year - V[2] - 1);
        }else if (V[1] - month == 0) {
            V[0] <= day ? printf("You're %d", year - V[2]) : printf("You're %d", year - V[2] - 1);
        } else {
            printf("You're %d", year - V[2]);
        }
        allowVote(1);
        allowDrive(1);
    }else {
        printf("You're %d", 2018 - V[2] - 1);
        if ( 2018 - V[2] >= 16 ) {
            allowVote(1);
        } else {
          allowVote(0);
        }
        allowDrive(0);
    }
}

void allowVote(int a) {
    a == 1? printf("\nYou can vote") : printf("You can't vote");
}
void allowDrive(int a) {
    a == 1? printf("\nYou can drive") : printf("You can't drive");
}