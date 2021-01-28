#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void init(list * l){
	(*l)=NULL;
	return ;
}

void append(list *l,int data){
	list temp,newnode;
	newnode=(node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("could not allocate memory");
		return ;
	}
	newnode->data=data;
	newnode->next=NULL;
	if((*l)==NULL){
		(*l)=newnode;
		(*l)->next=NULL;    //appending at the head.
		return ;
	}
	temp=(*l);
	while(temp->next){
		temp=temp->next;     //traverse till last node the save address of newnode in it.
	}
	temp->next=newnode;
	newnode->next=NULL;        //making newnode as the last node;
	return;
}


void traverse(list l)
{
     list temp;

    				// Return if list is empty 
    if(l == NULL)
    {
        printf("List is empty.");
        return;
    }
    
    temp = l;
    printf("list data :\n");
    while(temp != NULL)
    {
        printf("%d\n", temp->data); // Print data of current node
        temp = temp->next;                 // Move to next node
    }

}
void reverse_even(list *l){
	list temp;
	temp=(*l);
	
	while(temp!=NULL){
		if((temp->data)%2==0) {  //if data is even;
			if(temp->next !=NULL && (temp->next->data)%2==0){      //its not last node and if data is even;
				int temp1=temp->data;
				temp->data=temp->next->data;                   //swapping the data;
				temp->next->data=temp1;
			}
		
		}
		temp=temp->next;                  
	}
	

}


