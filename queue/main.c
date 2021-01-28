#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

int main(){
	queue q;
	init(&q,7);
	if(isempty(q)){
		printf("empty");
	}
	while(!(isfull(q))){
		int n;
		scanf("%d",&n);
		enque(&q,n);
		
	}
	
}
