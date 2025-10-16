#include <stdio.h>

int main(void) {
    for (int i = 0; i < 5; i++) {
        if (i == 2)
            continue;   // 跳過 i==2
        if (i == 4)
            break;      // 跳出整個 for
        printf("i=%d\n", i);
    }
    return 0;
}
