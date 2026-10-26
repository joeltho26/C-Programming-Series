#include <stdio.h>

int main() {
    // while loop
    int val = 0;
    while (val < 5) {
        printf("%d\n", val);
        val++;
    };
    printf("\n");
    // do-while loop
    int num = 10;
    do {
        printf("%d\n", num);
        num--;
    } while (num > 5);

    return 0;
}