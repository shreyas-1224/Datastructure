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

	 if( t == NULL ){
                return INT_MIN ;
          }

         int middle = t->data ;
         int left = INT_MIN;                                  // compare root data with child data recursively.
         int right = INT_MIN;

         left = max_element(t->left);
         right = max_element(t->right);

         if(left > right){
                    if(left > middle)    return left;
                    else                       return middle;
        }

        else {
                    if(right > middle)    return right;
                    else                         return middle;
	}
		
		
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


/*

void greater(bst a , bst b){

	if(total_elements(tree1) >= total_elements(t2)){

	     bst a = tree 1 ;

	   bst b = tree 2 ;

	}

	else {

	  bst a = tree 2;

	  bst b = tree 2;

	}

}

void compare(bst a , bst b){

       if(root == NULL ) return 1 ;

      if(search(a , b->data)){

           compare(a->left , b );

          compare(a->right , b);

     }

      else return 0 ;

}
*/


// bst is a structure pointer consist of left and right pointer and int data ;

void convert(bst root , bst_arr *t ,int i ){

      if(root == NULL ){
      	     
             t->arr[i] = INT_MAX;  
             return  ;       // empty spaces get filled up by 0 .. so filling with INT_MAX
       }

      t->arr[i] = root->data ;
     
      convert(root->left , t , 2*i + 1) ;    
      convert(root->right , t , 2*i + 2) ;

}


void ar_init(bst_arr *t , int length){
		
	t->arr =(int *)malloc(sizeof(int )*length);
	if(!(t->arr)) printf("failed");
	t->size = length ;
	return ;
}
 

/* 

recursively travelling all the left then right with corresponding index number */











