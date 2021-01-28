#include<stdio.h>
#include<limits.h>
#include "cqueue.h"



int main(){
	que q;
	int n;
	printf("enter the size of queue\n");
	scanf("%d",&n);
	init(&q,n);
	int k;
	while(scanf("%d",&k)!=-1){
		enque(&q,k);
		if(isfull(q)){break;}
	}
	display(q);
	deque(&q);
	deque(&q);
	display(q);
}
