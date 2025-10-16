#include "gcd.h"
int gcd(int a,int b){
    int GCD,r;
	if(b==0)return a;
	r=a%b;
	GCD=gcd(b,r);
    return GCD;
}
