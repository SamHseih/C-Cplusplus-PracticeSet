#include <stdio.h>
#include<stdlib.h>
#include "stdlib.h"
void inputAry(int n, int *P){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&P[i]);  //記得加& 才會寫入 
	}
	
}
void printAry(int n, int *P){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",P[i]);
	}
	puts("");
}
double Avg(int n, int *P){
	int i;
	double sum=0,Avg=0;
	for(i=0;i<n;i++){
		sum+=P[i];
	}
	Avg=sum/n;
	return Avg;
}
int MaxScore(int n, int *P){
	int max=0,i;
	for(i=0;i<n;i++){
		if(P[i]>max)max=P[i];
	}
	return max;
}
