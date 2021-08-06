#include<stdio.h>
#include<limits.h>
#include <stdlib.h>
#include "stack.h"

void init(stack *s,int length){
	s->a=(int*)malloc(sizeof(int)*length);
	s->top=-1;
	s->size=length;
	return ;
}

void push(stack* s,int n){

	if(isfull(*s)){
		printf("stack is full");
		return ;
	}
	
	s->top=s->top+1;
	s->a[s->top]=n;
	return ;
}

int pop(stack *s){
	if(isempty(*s)){
		printf("stack is empty");
		return INT_MIN;
	}
	return s->a[s->top--];
}

int isempty(stack s){
	return(s.top== -1? 1:0);
}


int peek(stack s){
	return (isempty(s)?INT_MIN:s.a[s.top]);
}


int isfull(stack s){
	return(s.top==s.size-1 ? 1:0);
}
