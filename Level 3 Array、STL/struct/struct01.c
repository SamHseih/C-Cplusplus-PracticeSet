#include<stdio.h>

#define N 5

//Same 
/*
struct struct01
{
    int math;
    int english;
    int computer;
};
typedef struct struct01 student;
*/   

typedef struct {
    int math;
    int english;
    int computer;
} student;


int main(){
    int i ;
    student st[N],sum={0};
    for(i=0;i<N;i++){
        scanf("%d",&st[i].math);
        scanf("%d",&st[i].english);
        scanf("%d",&st[i].computer);
    }

    for(i=0;i<N;i++){
        sum.math += st[i].math;
        sum.english += st[i].english;
        sum.computer += st[i].computer;
    }
    printf("Math avg = %.2f\n", (double)sum.math/N );
    printf("English avg = %.2f\n", (double)sum.english/N );
    printf("Computer avg = %.2f\n", (double)sum.computer/N );
    return 0;

}