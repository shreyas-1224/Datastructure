#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

void postorder_to_tree(bst (*root) , int end , int start , int* arr){
	
	if(start == end ){
		(*root)->data = arr[end];
		(*root)->right = NULL;
		(*root)->left = NULL;
		return ;
	}
	
	int k = end;
	(*root)->data = arr[k];
	
	bst nn1 = NULL;
	bst nn2 = NULL;
	
	if(arr[k] < arr[k-1] && (k-1 >= start)){
		
		nn1 = (struct node*)malloc(sizeof(struct node));
			
	}
	
	(*root)->right = nn1;
	
	while(k >= start){
		if(arr[k] < arr[end]){
			nn2 = (struct node*)malloc(sizeof(struct node));
			break;
		}
		
		k--;
	}
	
	(*root)->left = nn2;

	if(nn1 != NULL)	postorder_to_tree(&nn1 , end - 1, k+1 , arr);
	if(nn2 != NULL)	postorder_to_tree(&nn2 , k , start , arr);
	
	return ;
	
	
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


void preorder_traverse(bst t){
	
	if(t == NULL){
		return ;
	}
	printf("%d\t",t->data);
	inorder_traverse(t->left);
	inorder_traverse(t->right);
	return ;		
	
}

void postorder_traverse(bst t){
	
	if(t == NULL){
		return ;
	}
	
	inorder_traverse(t->left);
	inorder_traverse(t->right);
	printf("%d\t",t->data);
	return ;		
	
}
