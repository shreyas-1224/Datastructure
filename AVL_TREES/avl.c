#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include "avl.h"

void init(avl *t){
	(*t) = NULL;
	return ;
}
/*
void LL_rotate(avl* t , avl i){
	
	avl a = (*t)->left;
	avl b = a->right;
	
	a->parent = i->parent ; 
	if(i->parent != NULL){
		
		if(i->parent->data > i->data){
			i->parent->left = a;
			i->parent->bf--;
		}
		else{
			i->parent->right = a;
			i->parent->bf++;
		}
	
	}
	else{
		(*t) = a;
	}
	
	a->right = i;
	i->parent = a;
	i->left = b;
	if(b != NULL){
		b->parent = i;
		i->bf = b->bf + 1;
	}
	else
		i->bf = 0;
	
	
	
	
	
	return;
}

void RR_rotation(avl* t, avl i){
	
	avl a = i->right;
	avl b = a->left;
	
	a->parent = i->parent;
	if(i->parent){
		
		if(i->parent->data > i->data){
			i->parent->left = a;
			i->parent->bf--;
		}
		else{
			i->parent->right = a;
			i->parent->bf++;
		}
	
	}
	else{
		(*t) = a;
	}
	
	a->left = i;
	i->parent = a;
	i->right = a->left ; 
	
	return;
}


void insert(avl *t,int data){

	avl p,q;
	int side ;
	avl newnode = (node *)malloc(sizeof(node));
	if(newnode == NULL) return;
	
	newnode->data = data;
	newnode->bf = 0;
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->parent = NULL;  	// newnode data has been created
	
	if((*t) == NULL){
		(*t) = newnode;
		return;
	}
	
	p = (*t);
	while(p){
		q = p;
		if(p->data == data ) {
			free(newnode);
			return ;
		}			
		else if(p->data < data ){
			side = 1;
			p = p->right;		
		}
		else{
			side = 0;
			p = p->left;
		}
	}
	
	
	if(side)   q->right = newnode ;
	else 	   q->left = newnode;
	
	newnode->parent = q;	
	p = newnode ;
	
	
	while(p->parent){
		
		if(q->data < p->data){
			q->bf--; 
		}
		else{	
			q->bf++ ;
		}
		
		if(q->bf == 0) 	break;
		p = q;
		if(abs(p->bf) >= 2){
			printf("rotation required");
		}
		q = q->parent;	
	}	
	return;

}

*/
void inorder_traverse(avl t){
	
	if(t == NULL)	return;
	inorder_traverse(t->left);
	printf("%d : %d\n",t->data , t->bf);
	inorder_traverse(t->right);	
	return;
}



void insert(avl *t , int data){
	
	avl p , q = NULL ;
	p = (*t);
	int side ;
	
	avl newnode = (struct node*)malloc(sizeof(struct node));
	newnode->parent = q;
	newnode->left = NULL ;
	newnode->right = NULL ;
	newnode->data = data ;
	newnode->bf = 0 ;
	
	if((*t) == NULL){
		(*t) = newnode ;
		(*t)->parent = q;
		return ;
	}
	
	while(p != NULL){
		
		if(p->data == data )	return ;
		q = p ;
		if(p->data < data){
		
			p = p->right ;
			side = 1;
		}
			
		else {
		
			p = p->left ;
			side = 0;
		}
	}
	
	if(side){
		
		q->right = newnode ;
		newnode->parent = q;
	}
	else {
		
		q->left = newnode ;
		newnode->parent = q;
	}					// basic insertion in completed. p points to the node added and now adjust the bf .
	
	p = newnode ;
	
	while(p->parent!= NULL){
		

		if(p->data > q->data)	
			q->bf-- ;
		
		else    q->bf++ ;
		
		if(abs(q->bf) == 2){
			rotation(t,q);
			break ;
		}
		if(q->bf == 0)	break ;
		p = q ; 
		q = q->parent ;
	}
	return ;
}


void rotation(avl *t, avl l){
	
	if(l->bf == 2){
		if(l->left->bf >= 1){
			LL_rotation(t,l);
		}
		else if(l->left->bf <= 0){
			LR_rotation(t,l);
		}
	}
	else if(l->bf == -2){
		
		if(l->right->bf >= 1){
			RL_rotation(t,l);
		}
		else if(l->right->bf <= 0){
			//printf("reached");
			RR_rotation(t,l);
		}
	}
	return ;
}

void LL_rotation(avl *t, avl i){
	
       // printf("%d",i->data);
	//return ;
	avl a = i->left ;
	avl b = a->right ;
	
	a->parent = i->parent ;
	if(i->parent != NULL)	i->parent->left = a ;
	a->right = i ;
	i->parent = a ;
	i->left = b ;
	
	if(b != NULL)	b->parent = i ;
	if((*t) == i)	(*t) = a ; 

	i->bf = (i->bf) - (a->bf) - 1 ;
	if(a->bf == -2 )	a->bf = a->bf - 2 ;
	else 			a->bf-- ; 
	
	return ;
}

void LR_rotation(avl *t , avl l){
	
	avl i = l->left ;
	avl a = i->right ;
	avl b = a->left ; 
	
	a->parent = i->parent ;
	l->left = a ;
	a->left = i ; 
	i->parent = a ;
	i->right = b ;

	if(b != NULL)	b->parent = i ; 
	
	i->bf = height(i->left) - height(i->right) ;
	a->bf = height(a->left) - height(a->right) ;
	
	LL_rotation(t,l);
	return ;
}


void RR_rotation(avl* t, avl i){
	
	avl a = i->right ;
	avl b = a->left ;
	
	a->parent = i->parent ;
	if(i->parent != NULL )	   i->parent->right = a ;
	a->left = i ;
	i->parent = a ;
	i->right = b ;
	
	if(b != NULL)	b->parent = i ;
	if((*t) == i)	(*t) = a ; 
	
	i->bf = (i->bf) - (a->bf) + 1 ;

	if(a->bf == -2 )	a->bf = a->bf + 2 ;
	else 			a->bf++ ; 

	return ;

}

void RL_rotation(avl* t, avl l){
	
	avl i = l->right ;
	avl a = i->left ;
	avl b = a->right ; 
	
	a->parent = i->parent ;
	l->right = a ;
	a->right = i ; 
	i->parent = a ;
	i->left = b ;

	if(b != NULL)	b->parent = i ; 
	
	i->bf = height(i->left) - height(i->right) ;
	a->bf = height(a->left) - height(a->right) ;
	
	RR_rotation(t,l);
	return ;
}


int height(avl root){
	
	if(root == NULL)	return -1 ;
	
	int l = height(root->left) ;
	int r = height(root->right) ;
	
	if(l > r)	return 1 + l ;
	else 		return 1 + r ;

}



