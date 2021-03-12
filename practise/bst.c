#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bst.h"

void init(bst *t ){
	
	(*t) = NULL;
	return ;
}

void insert(bst *t , int data){

	bst newnode =(struct node*)malloc(sizeof(struct node));
	
	if(newnode == NULL){
		printf("unable to allocate memory !");
		return ;
	}
	
	newnode->left = newnode->right = NULL;
	newnode->data = data;
	
	if(*t == NULL){
		*t = newnode;
		return ;
	}
	
	bst p = (*t) , q = NULL;
	int side ; 
	
	while(p){
	
		if(p->data == data)	return ;
		
		q = p ;
		
		if(p->data > data){
			p = p->left ;
			side = 0;
		}
		else {
			p = p->right;
			side = 1;
		}
	}
	
	if( side )  q->right = newnode ;
	else 	     q->left = newnode ;
	
	return ; 
	
	
}

int total_elements(bst t){

	if(t == NULL) return 0 ;	
	return 1 + total_elements(t->left) + total_elements(t->right);
}



/*

void inorder_traverse(bst t){
	
	if(t == NULL)	return ;
	
	inorder_traverse(t->left);
	printf("%d ",t->data);
	inorder_traverse(t->right);
	return;
}

void postorder_traverse(bst t){
	
	if(t == NULL)	return ;
	
	postorder_traverse(t->left);
	postorder_traverse(t->right);
	printf("%d ",t->data);
	return;
}

void preorder_traverse(bst t){
	
	if(t == NULL)	return ;
	
	printf("%d ",t->data);
	preorder_traverse(t->left);
	preorder_traverse(t->right);
	return;
}

traversing without recursion : */


void inorder_traverse(bst t){
	
	if(t == NULL)	return ;
	p_stack s ;
	p_init(&s , total_elements(t));
	
	bst l = t;
	
	while(1){
		if(l != NULL){
			push(&s , l);
			l = l->left;
		}
		
		else{
			if(p_isempty(s))	break;
			l = pop(&s);
			printf("%d ",l->data);
			l = l->right ;
		}
		
		
	}
}


void preorder_traverse(bst t){
	
	if(t == NULL)	return ;
	p_stack s ;
	p_init(&s , total_elements(t));
	
	bst l = t;
	
	while(1){
		if(l != NULL){
			push(&s , l);
			printf("%d ",l->data);
			l = l->left;
		}
		
		else{
			if(p_isempty(s))	break;
			l = pop(&s);
			l = l->right ;
		}
		
		
	}
}

void postorder_traverse(bst t){
	
	if(t == NULL)	return ;
	p_stack s ;
	p_init(&s , total_elements(t));
	bst l = t;	
	bst m = NULL;
	while(1){
	
		if( l != NULL){
			
			if(l->right != NULL && l->right != m)	push(&s , l->right);
			push(&s , l);
			l = l->left ;
		}
		
		else{
			if(p_isempty(s))	break;
			l = pop(&s);
			
			if(p_peek(s) == l->right){
				
				m = l ;
				l = pop(&s);
				push(&s , m);
			
			}
			else{
				printf("%d ",l->data);
				m = l;
				l = NULL;
			}
			
		}
	}
}

/* search using loop and recursion ;
int search(bst t , int data){
	
	bst p = t ; 
	while(p){
		if( p->data == data)	return 1;
		
		else if(p->data > data)	p = p->left;
		
		else 		p = p->right;
	}
	return 0;
}


*/

int search(bst t , int data){

	if(t == NULL)	return 0 ;
	if(t->data == data )	return 1;
	
	search(t->left , data);
	search(t->right, data);
	
}


int height(bst t){

	if(t == NULL)	return -1;
	
	int l = height(t->left);
	int r = height(t->right);
	
	if(l > r)	return 1 + l;
	else 		return 1 + r;
	
}

void longest_path(bst t){
	
	while(t){
	
		printf("%d ",t->data);
		if(height(t->left) > height(t->right))   t = t->left ;
		else 		t = t->right ;
	}	
	return;
}

int max_element(bst t){
	
	if(t == NULL){
		return INT_MIN ;
	}
	
	int middle = t->data ;
	int left = INT_MIN;
	int right = INT_MIN;
	
	left = max_element(t->left);
	right = max_element(t->right);
	
	if(left > right){
		if(left > middle)	return left;
		else 			return middle;
	}
	else {
		if(right > middle)	return right;
		else			return middle;
	}
	
}

int min_element(bst t){
	
	if(t == NULL){
		return INT_MAX ;
	}
	
	int middle = t->data ;
	int left = INT_MAX;
	int right = INT_MAX;
	
	left = min_element(t->left);
	right = min_element(t->right);
	
	if(left < right){
		if(left < middle)	return left;
		else 			return middle;
	}
	else {
		if(right < middle)	return right;
		else			return middle;
	}
	
}


int diameter(bst t){
	
	if (t == NULL)	return -1;
	
	int left = diameter(t->left);
	int right = diameter(t->right);
	int middle = height(t->left) + height(t->right) + 2;
	
	if(left > right){
		if(left > middle)	return left;
		else 			return middle;
	}
	else {
		if(right > middle)	return right;
		else			return middle;
	}
}


void mirror(bst *root){
	
	if((*root) == NULL)	return ;
	
	bst l = (*root)->left;
	bst r = (*root)->right;
	
	(*root)->left = r;
	(*root)->right = l;
	
	mirror(&r);
	mirror(&l);
	
	return ;
}

void copy_tree(bst root , bst *newtree){
	
	if(root == NULL){
		return ;
	}
	
	(*newtree) = root;
	
	(*newtree)->left = root->left ;
	(*newtree)->right = root->right ;
	
	copy_tree(root->left , &((*newtree)->left));
	copy_tree(root->right , &((*newtree)->right));
	
}

int isfull(bst root){
	
	if(root == NULL)	return 1 ;
	if((root ->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))	return 0;
	else return (1 && isfull(root->left) && isfull(root->right));

}


int width(bst root){
	if(root == NULL)	return 0;
	
	queue q ;
	q_init(&q , total_elements(root)+50) ;
	
	bst p = root ;
	enqueue(&q,p);
	enqueue(&q , NULL);
	int count = 0 , max = 1;
	
	while(!(is_empty(q))){
		
		if(max < count)	max = count ;
		
		p = dequeue(&q);
		
		if(p != NULL){
		
			if(p->left != NULL){
				enqueue(&q,p->left);
				count = count + 1;
			}
			if(p->right != NULL){
				enqueue(&q,p->right);
				count = count + 1;
			}
		}
		
		else{
			if(is_empty(q))	break ;
			
			enqueue(&q , NULL);
			count = 0 ;
			
		}
		
	}
		
	return max;

}





