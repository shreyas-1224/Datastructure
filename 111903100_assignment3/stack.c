#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

void i_init(stack *s,int length){
	s->a=(char*)malloc(sizeof(char)*length);
	s->top=-1;
	s->size=length;
	return ;
}

void i_push(stack* s,char n){

	if(isfull(*s)){
		printf("stack is full");
		return ;
	}
	
	s->top = s->top+1;
	s->a[s->top] = n;
	return ;
}

char i_pop(stack *s){
	if(!(isempty(*s)))	return s->a[s->top--];
}

int isempty(stack s){
	return(s.top == -1? 1:0);
}



char i_peek(stack s){
	return (s.a[s.top]);
}

int isfull(stack s){
	if(s.top == s.size - 1) return 1 ;
	else 	return 0;
}

