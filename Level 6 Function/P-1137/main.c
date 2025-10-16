#include <stdio.h>
#include <stdlib.h>
#include "gcd.h"
 
int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    int ans=gcd(a,b);
    printf("%d\n",ans);
    return 0;
}
