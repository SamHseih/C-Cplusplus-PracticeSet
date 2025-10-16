#include <stdio.h>

int main(void) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            if (i + j == 3) break;
            count++;
        }
    }
    printf("count=%d\n", count);
}