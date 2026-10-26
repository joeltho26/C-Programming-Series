#include <stdio.h>

int main() {
    int limit = 10;

    for (int i=1; i<=limit; i++) {
        printf("%d->", i);
    }
    printf("\n");
    for (int i=20; i>limit; i--) {
        printf("%d->", i);
    }
}