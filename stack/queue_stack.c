#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include "stack.h"

stack p;

void q_init(queue *s,int length){
	init(&p,length);
	init(s,length);
}

void q_push(queue *s,int n){
	if(isfull(*s)){
		return;
	}
	if(isempty(*s)){
		push(s,n);
		return ;
	}
	while(!(isempty(*s))){
		int k=pop(s);
		push(&p,k);
	}
	push(s,n);
	while(!(isempty(p))){
		int k=pop(&p);
		push(s,k);
	}
	return ;
}

int q_pop(queue *s){
	return (pop(s));
}
