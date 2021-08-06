#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<string.h>
#include "avl.h"

void init(avl *t){
	(*t) = NULL;
	return ;
}


void inorder_traverse(avl t){
	
	if(t == NULL)	return;
	inorder_traverse(t->left);
	printf("%s : %d \n",t->data , t->bf);
	inorder_traverse(t->right);	
	return;
}



void insert(avl *t , char* data){
	
	avl p , q = NULL ;
	p = (*t);
	int side , compare ;
	
	avl newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = (char*)malloc(sizeof(char)*strlen(data));
	strcpy(newnode->data , data) ;
	newnode->parent = q;
	newnode->left = NULL ;
	newnode->right = NULL ;
	newnode->bf = 0 ;
	
	if((*t) == NULL){
		(*t) = newnode ;
		(*t)->parent = q;
		return ;
	}
	
	while(p != NULL){
		
		if(strcmp(data , p->data) == 0 )	return ;
		q = p ;
		compare = strcmp(data , p->data);
		
		if(compare >= 1){
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
		
		compare = strcmp(p->data , q->data) ;
		
		if(compare >= 1)	
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
		
			RR_rotation(t,l);
		}
	}
	return ;
}

void LL_rotation(avl *t, avl i){

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

void delete_node(avl *root , char* data){

	avl p = (*root) ;
	avl q = NULL ;
	avl a = NULL , b = NULL ;
	int compare, side , original; 
	while(p != NULL){
		
		compare = strcmp(p->data , data) ;
//		printf("%s %s %d\n",p->data , data , compare); 
		if(compare == 0)	break ;
		
	        q = p ; 
	        
	        if(compare < 0)	p = p->right ;
	        else			p = p->left ;
	}
	
	// element not present ;
	if(p == NULL){
		printf("element not present\n");
		return ;
	}
	
	// leaf node ;
	
	if(p->left == NULL && p->right == NULL){
		if(q == NULL){
			free(p->data);
			free(p);
			return ;
		}
		if(strcmp(p->data , q->data ) < 0){
			side = 0 ;
			a = q ;
			q->left = NULL;
			free(p->data);
			free(p);
		}
		
		else if(strcmp(p->data,q->data) > 0){
			q->right = NULL;
			side = 1 ; 
			a = q  ;
			free(p->data);
			free(p);
		}
		
	}
	
	// only left node ;
	
	else if(p->left != NULL && p->right == NULL){
		if(q == NULL){
			a = p->left ;
			a->parent = q ;
			free(p->data);
			free(p);
			(*root) = a ; 
			return ;
		}
		
		else{
			a = q ;
			q->left = p->left ;
			side = 0 ;
			if(p->left != NULL)
				p->left->parent = q ;
			free(p->data);
			free(p);
		}
	}
	
	else if(p->left == NULL && p->right != NULL){
		
		if(q == NULL){
			a = p->right ;
			a->parent = q ;
			free(p->data);
			free(p);
			(*root) = a ; 
			return ;
		}
		
		else{
			a = q ;
			q->right = p->right ;
			side = 1 ;
			if(p->right != NULL)
				p->right->parent = q ;
			free(p->data);
			free(p);
		}
	}
	
	else{
		// node with both childs ;
		a = p ;
		b = p->left ;
		side = 0 ;
		while(b->right != NULL){
			side = 1 ;
			a = b;
			b = b->right ;
		}
		
		strcpy(p->data , b->data);
		free(b->data);
		free(b);
		if(side)	a->right = NULL ;
		else		a->left = NULL ;
		
	}


	while(a != NULL){
		
		original = a->bf ;
		
		if(side == 1){
			a->bf++ ;
			if(original == 0)	break ;
		}
		
		else {
			a->bf-- ;
			if(original == 0)	break ;
		}
		
		if(abs(a->bf) == 2){
		
			rotation(root,a);
			break ;
		}
		if(a->bf == 0)	break ; 
		a = a->parent ;
	}	
	
	return ;	
	
	
}

void destroy_all(avl t){    // we are destroying whole tree recursively. 

	if( t == NULL)	return;
	
	destroy_all(t->left);		// time complexity O(n);
	destroy_all(t->right);
	free(t->data);
	free(t);
	return ;

}

void destroy(avl *t){
	destroy_all(*t);
	*t = NULL ;
	return ;

}

