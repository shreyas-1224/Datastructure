#include<stdio.h>
#include<limits.h>
#include "stack.h"

int main(){
	queue s;
	q_init(&s,10);
	int n;
	while(!(isfull(s))){
		scanf("%d",&n);
		q_push(&s,n);
	}
	while(peek(s)!=INT_MIN){
		printf("%d\n",q_pop(&s));
	}
	
}
