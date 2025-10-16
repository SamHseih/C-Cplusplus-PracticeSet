#include <stdio.h>

int main(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1)
                goto END; // 強制跳出所有層
            printf("i=%d j=%d\n", i, j);
        }
    }
END:
    printf("done\n");
    return 0;
}