#include<stdio.h>
#include<stdlib.h>
#include "list.h"


void init(list * l){
	(*l)=NULL;
	return ;
}

void append(list *l,int coff,int power){
	list newnode,temp;
	newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL){printf("not created");return ;}
	newnode->next=NULL;
	newnode->coff=coff;
	newnode->power=power;
	
	if((*l)==NULL){
		(*l)=newnode;
		return ;
	}
	temp=(*l);
	while(temp->next){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=NULL;
	return ;
	
}

void traverse(list l){

	list temp=l;
	while(temp->next){
		printf("%d %d ,",temp->coff,temp->power);
		temp=temp->next;
	}
	printf("%d %d ,",temp->coff,temp->power);
	return ;
}
