#include <stdio.h>
#include <stdlib.h>
#include "prime.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 
int main(int argc, char *argv[]) {
    int n;
    scanf("%d",&n);
    if(IsPrime(n))
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);
    return 0;
}
