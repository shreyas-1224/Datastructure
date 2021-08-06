#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bst.h"

void init(bst *t){
	(*t) = NULL;
	return ;
}

void insert(bst *t,int data){

	bst p,q;
	
	bst newnode = (node *)malloc(sizeof(node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	
	if(newnode==NULL) return ;
	
	if((*t) ==  NULL){
		(*t) = newnode;
		return ;
	}
	p=(*t);
	
	while(p){
		
		q = p;
		
		if(p->data == data){
			free(newnode);
			return ;
		}
		else if(data < p->data){			//if given data is lesser than data of node - left.
			
			p = p->left;
		}
		else{						//if given data is greater than data of node - right.
		
			p = p->right;
		}
	}
	
	if(data < q->data){
		q->left = newnode;
		return ;
	}
	else{
		q->right = newnode;
		return ;
	}
}


void inorder_traverse(bst t){
	
	if(t == NULL){
		return ;
	}
	inorder_traverse(t->left);
	printf("%d\t",t->data);
	inorder_traverse(t->right);
	return ;		
	
}


void postorder_traverse(bst t){
	
	if(t== NULL){
		return ;
	}
	postorder_traverse(t->left);
	
	postorder_traverse(t->right);
	printf("%d\t",t->data);
	return ;		
	
}

void preorder_traverse(bst t){
	
	if(t== NULL){
		return ;
	}
	printf("%d\t",t->data);
	preorder_traverse(t->left);
	
	preorder_traverse(t->right);
	return ;		
	
}



int search(bst t,int data){
	
	bst p=t;
	while(p){
		if(p->data == data) return 1;
		else if(data < p->data) p=p->left;
		else p = p->right;
		
	}
	return 0;
}


int max_element(bst t){

	int max=INT_MIN , l,r,root=INT_MIN;
	if(t != NULL){
	
		root = t->data;
		l = max_element(t->left);
		r = max_element(t->right);
		
		if(l>r){
			if(l < root) max=root;
			else max=l;
		}
		else {
			if(r < root) max=root;
			else max=r;
			
		}
	}
	
	return max;
		
		
}


//height of a binary tree. returns integer. 

int height(bst t){
	
	if(t == NULL) return -1;
	int l = height(t->left);
	int r = height(t->right);
	
	if(l>r) return 1+l;
	else	return 1+r;
	
	
}




int total_elements(bst t){  // include node element and left nodes and right nodes..

	//base condition.
	if(t==NULL){
		return 0;
	}
	
	return 1 + total_elements(t->left) + total_elements(t->right);
	
}


int leaf_nodes(bst t){
	
	if(t== NULL) return 0;
	if(t->left== NULL && t->right==NULL) return 1;
	
	return leaf_nodes(t->left) + leaf_nodes(t->right); 
}


int min_element(bst t){

	int min=INT_MAX , l,r,root;
	if(t != NULL){
	
		root = t->data;
		l = min_element(t->left);
		r = min_element(t->right);
		
		if(l<r){
			if(l > root) min=root;
			else min=l;
		}
		else {
			if(r > root) min=root;
			else min=r;
			
		}
	}
	
	return min;
		
		
}


int isfull(bst t){

	if(t->left== NULL && t->right== NULL){
		return 1;
	}
	
	if((t->left== NULL && t->right!= NULL) || (t->left!=NULL && t->right==NULL)){
		return 0;
	}
	return(isfull(t->left) && isfull(t->right));
}


void level_order(bst t){
	
	if(t == NULL) return ;
	queue q; 
	q_init(&q,total_elements(t));
	enqueue(&q,t);
	bst l; init(&l);
	
	while(!(is_empty(q))){
		
		l = dequeue(&q);
		printf("%d ",l->data);
		if(l->left != NULL){enqueue(&q,l->left);}
		if(l->right != NULL){enqueue(&q,l->right);}	
		
	}
	return ;
	
}




/*inorder traversal using loops 

void inorder_traverse(bst t){
	p_stack s; p_init(&s,total_elements(t));
	bst curr ; init(&curr);
	curr = t ;
	
	while(1){
		
		if(curr != NULL){
			p_push(&s,curr);
			curr = curr->left;
		     
			}
			
		else{
			if( p_isempty(s) )	break;
			curr = p_pop(&s);
			printf("%d ",curr->data);
			curr = curr->right;
		}
		     
		     
		     
		
	}
	return ;
		
	
}




void preorder_traverse(bst t){

	p_stack s; p_init(&s,total_elements(t));
	bst curr ; init(&curr);
	curr = t ;
	
	while(1){
		
		if(curr != NULL){
			p_push(&s,curr);
			printf("%d ",curr->data);
			curr = curr->left;
		     
			}
			
		else{
			if( p_isempty(s) )	break;
			curr = p_pop(&s);
			
			curr = curr->right;
		}
		     
		     
		     
		
	}
	return ;
	

}

*/
int diameter(bst t){
	
	if (t==NULL)	return 0;
	
	int middle = height(t->left) + height(t->right) + 1;
	int left   = diameter(t->left);
	int right  = diameter(t->right);
	
	if(middle > right ){
		if(middle > left) return middle;      // time complexity is O(n^2).. not good ! How if we calculate height and diameter 
		else 		   return left ;      // in same time .. use a struct which contains height and diameter.
 	}
	else {
		if(right > left) return right;
		else 		   return left ;
	}
	
}

	

int isbalanced(bst t){
	
	if (t == NULL)	return 1;
	
	int left = isbalanced(t->left);
	int right = isbalanced(t->right);
	
	int diff = height(t->left)-height(t->right) < 2 ? 1 : 0;
	
	if(diff && left && right)	return 1;
	else	return 0;


}



void right_view(bst t){

	queue q; q_init(&q,total_elements(t));
	bst l,m ; 
	l = t; m = NULL;
	enqueue(&q,t);
	enqueue(&q,NULL);
	
	while(!(is_empty(q))){
		
		m = l;
		l = dequeue(&q);
		
		if(l != NULL){
			
			if( l->left != NULL ) enqueue(&q,l->left);
			if(  l->right != NULL) enqueue(&q,l->right);
		}
		
		else if(l == NULL){
			
			printf("%d ",m->data);
			if(!(is_empty(q))){ enqueue(&q , NULL); }
			else break;
		}
	
	}

}


void left_view(bst t){


	queue q; q_init(&q,total_elements(t));
	bst l,m ; 
	init(&l); m = t;
	
	enqueue(&q,NULL);
	enqueue(&q,t);
	
	while(!(is_empty(q))){
		
		
		l = dequeue(&q);
		if(m == NULL) printf("%d ",l->data);
		
		if(l != NULL){
			
			if( l->left != NULL ) enqueue(&q,l->left);
			if(  l->right != NULL) enqueue(&q,l->right);
		}
		
		else if(l == NULL){
			
			if(!(is_empty(q))){ enqueue(&q , NULL); }
			else break;
		}
		
		m = l;
	
	}

}



void remove_node(bst *t , int data){
	
	    if(t == NULL)	return;

	    node *p, *q;
	    // set the pointer p to the root and q = NULL
	    p = (*t);
	    q = NULL;

	    // searching for the node in the tree
	    int side;
	    while(p) {
		if(data == p->data) {
            		break;
		}
		q = p;
		if(data < p->data) {
		    p = p->left;
		    side = 0;
		}
		else {
		    p = p->right;
		    side = 1;
		}
	    }

		// if p is null that means node is not found so return p
		if(p == NULL)	return;

		// we come here means node is found so now check cases and free
		// p is not null
		// leaf node
		if(p->left == NULL && p->right == NULL) {
		    if(q == NULL ) {
		        (*t) = NULL;
		        free(p);
		        return;
		    }
		    
		    if(side) {
		        q->right = NULL;
		    }
		    else {
		        q->left = NULL;
		    }
		    free(p);
		    return;
		}

		// one chilren
		// suppose the P node have only one child and that is left child
		if(p->left && !p->right) {
		    // p can be a root node
		    if(q == NULL) {
		        (*t) = p->left;
		        free(p);
		        return;
		    }
		    //
		    if(side == 0) {
		        q->left = p->left;
		        free(p);
		        return;
		    }
		    else {
		        q->right = p->left;
		        free(p);
		        return;
		    }
		}

		// suppose the P node have only one child and that is right child
		if(!p->left && p->right) {
		    // p can be a root node
		    if(q == NULL) {
		        (*t) = p->right;
		        free(p);
		        return;
		    }
		    //
		    if(side == 0) {
		        q->left = p->right;
		        free(p);
		        return;
		    }
		    else {
		        q->right = p->right;
		        free(p);
		        return;
		    }
		}

		//two children

		if(p->left && p->right) { // p is the node with both children

		    node *r, *s = NULL;
		    r = p->left;

		    while(r->right) {
		        s = r;
		        r = r->right;
		    }

		    // if the S is null
		    // copy R to P
		    // make p-> left as null and free r

		    if(!s) {
		        p->data = r->data;
		        p->left = NULL;
		        free(r);
		        return;
		    }
		    // we are at the rightmost place of the left subtree
		    // if there is a node at the left of the R then
		    p->data = r->data;
		    if(r->left) {
		        s->right = r->left;
		    }
		    else
		        s->right = NULL;

		    // transfer the data from the R to P
		    
		    s->right = r->left;
		    free(r);
		}
	    return;
}


void longest_path(bst t){
	
	while(t != NULL){
		printf("%d",t->data);
		
		if(height(t->left) > height(t->right))	t = t->left;
		else 	
			t = t->right;
	
	}
	return;
}



int total_nonleaf(bst t){
	
	int count = 0 ;
	queue q ;
	q_init(&q , total_elements(t));
	bst temp = t ;
	enqueue(&q , t);
	
	while(!is_empty(q)){
		temp = dequeue(&q) ;
		//printf("%d",temp->data);
	
		if(temp->right != NULL  || temp->left != NULL){
			count++ ;
			if(temp->left != NULL)	enqueue(&q,temp->left);
			if(temp->right != NULL) enqueue(&q, temp->right);
		}
		
	}
	return count ;
}

















