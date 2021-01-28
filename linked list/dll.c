#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "dll.h"

void init(list *l){
    (*l)=NULL;
    return ;
}

void append(list* l,list * np,int x){
    list newnode,temp,temp2;
    temp2=(*np);
    newnode=(list)malloc(sizeof(int));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=x;
    if((*l)==NULL){
        (*l)=newnode;
        (*l)->length=0;
        (*l)->length++;
        temp2=(*l);
        return ;
    }
    else{
        temp=(*l);
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        (*l)->length++;
        (*np)=newnode;
        return ;
    }
}



void _traverse(list a){
    list temp;
    temp=a;
    temp->data= -(temp->data);
    printf("%d",temp->data);
    temp=temp->next;
    printf("\t%d",temp->data);
}












