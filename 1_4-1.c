#include <stdio.h>
#include <stdbool.h>

int x = 7;

int main() {
    int isEqual;

    isEqual = ++x;
    printf("now %d\n", isEqual);

    isEqual = ++x;
    printf("now %d\n", isEqual);

    isEqual = ++x;
    printf("now %d\n", isEqual);

    return 0;
}
