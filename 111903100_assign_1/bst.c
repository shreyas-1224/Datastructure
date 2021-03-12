#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include "bst.h"

void init(bst *t){
	(*t) = NULL;
	return ;
}

void insert(bst *root, bst *q,int side,int mis,char* name){
	
	if((*root) == NULL){
	
		bst newnode =(node*)malloc(sizeof(node));
		newnode->mis = mis;
		newnode->name = (char*)malloc(strlen(name)+1);
		strcpy(newnode->name,name);
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->parent = (*q);
	
	
		if(*q == NULL){
			
			(*root) = newnode;
			(*q) = (*root);
			return ;
		}
		
		if(side){
			(*q)->right = newnode;
			return ;
		}
		else{
			(*q)->left = newnode;
			return;
		}
	}
	
	if(mis < (*root)->mis){
		side = 0;
		(*q) = (*root);
		insert(&((*root)->left),q, side,mis,name);
	}
	else if(mis > (*root)->mis){
		side = 1;
		(*q) = (*root);
		insert(&((*root)->right),q, side,mis,name);
	}
	return ;
}


char* search(bst t,int mis){		// returns name by mis.
	
	if(t == NULL) return NULL;
	if(t->mis == mis){
		return t->name;
	}
	else if(mis < t->mis){
		char * name = search(t->left,mis);
	}
	else if(mis > t->mis){
		char * name = search(t->right,mis);
	}
}




int height(bst t){
	
	if(t == NULL) return -1;
	int l = height(t->left);
	int r = height(t->right);
	
	if(l>r) return 1+l;
	else	return 1+r;
	
}


void copy(char** to, char*from){
	
	int i=0;
	while(from[i] != '\0'){
		
		(*to)[i] = from[i];
	
	}
	return ;
}


void inorder_traverse(bst t){
	
	if(t == NULL){
		return ;
	}
	inorder_traverse(t->left);
	printf("%d : %s\n",t->mis,t->name);
	inorder_traverse(t->right);
	return ;		
	
	
}

int total_elements(bst t){  // include node element and left nodes and right nodes..

	//base condition.
	if(t==NULL){
		return 0;
	}
		return 1 + total_elements(t->left) + total_elements(t->right);
	
}



void destroy(bst t){    // we are destroying whole tree recursively. 

	if( t == NULL)	return;
	
	destroy(t->left);		// time complexity O(n);
	destroy(t->right);
	free(t->name);
	free(t);
	return ;

}

void destroy_all(bst *t){
	destroy(*t);
	*t = NULL ;
	return ;

}


void level_i(bst t,int k){

	if (k > height(t) - 1 || k < 0){
		printf("no such level exist");
	}
	
	queue q; q_init(&q,total_elements(t)+10);
	
	enqueue(&q,t); enqueue(&q,NULL);
	
	bst l = NULL;
	int i = -1;
	
	while(i != k){
		if(l == NULL)	i++;
		l = dequeue(&q);
		if( i == k){
			
			while(l != NULL){
				printf( "%d : %s\n",l->mis,l->name);
				l = dequeue(&q);
			}
			break;
		}
		
		if(l == NULL)	enqueue(&q,NULL);
		else {
		
			if(l->left != NULL)	enqueue(&q,l->left);
			if(l->right!= NULL)	enqueue(&q,l->right);
			
		}
		
	}
	
	return ;
}




void postorder_traverse(bst t){

	if(t == NULL)	return ;

	bst root = t; bst m = NULL;
	p_stack s ; p_init(&s,total_elements(t));
	
	do{
	
		while(root != NULL ){
			
			if(root->right)	p_push(&s,root->right);
			p_push(&s,root);
			root = root->left;
			
		}
		
			
		root = p_pop(&s);
		if(root->right == p_peek(s)){
			m = p_pop(&s);
			p_push(&s,root);
			root = root->right;
		}
			
		else{	
			printf("%s : %d  ",root -> name ,root->mis);
			root = NULL;
		}
	
	
	
	} while(!(p_isempty(s)));

}




void remove_node(bst *t , int mis){

	if(t == NULL)	return ;
	
	bst p = (*t);
	bst q = NULL;
	int side ;
	
	while(p){
		
		if(p->mis == mis)	break;
		q = p;
		if(p->mis > mis){
			side = 0;
			p = p->left;
			
		}
		else {
			side = 1;
			p = p->right;
		}
		
	}
	
	if(p == NULL)	return;
	
	if(p->left == NULL && p->right == NULL){
	
		if(q == NULL){
			(*t) = NULL;
			free(p);
			return ;
		}
		
		if(side = 0){
			free(p);
			q->left = NULL;
			return ;	
		}
		else{
			free(q);
			q->right = NULL;
			return ;
		}
		
	}
	
	else if(p->left != NULL && p->right == NULL ){
		
		if( q == NULL){
			free(p);
			(*t) = p->left;
			return ;
		}
		
		if(side == 0){
			
			(p->left)->parent = q;
			q->left = p->left;
			free(p);
			return ;
		}
		
		else{
			(p->left)->parent = q;
			q->right = p->left;
			free(p);
			return;
		
		}
					
	}
		
	else if(p->left == NULL && p->right != NULL ){
		
		if( q == NULL){
			free(p);
			(*t) = p->right;
			return ;
		}
		
		if(side == 0){
			
			(p->right)->parent = q;
			q->left = p->right;
			free(p);
			return ;
		}
		
		else{
			(p->right)->parent = q;
			q->right = p->right;
			free(p);
			return;
		
		}
	
		
	}
	
	else{
		bst r = p->left;
		bst s = NULL;
		
		while(r->right){
		
			s = r;
			r = r->right;
		}
		
		if(s == NULL){
			
			if(r->left){
				(r->left)->parent = r->parent;   // appearantly p; 
			}
			 p->mis = r->mis;
			 p->name = r->name;
			 p->left = r->left;
			 free(p) ; return ;
		}
		
		else{
			
			if(r->left){
				s->right = r->left;
				(r->left)->parent = r->parent;
			}
			else	{s->right = NULL;}
			p->mis = r->mis;
			p->name = r->name;
			free(r);
			return ;
		}
	
	}
	
}











