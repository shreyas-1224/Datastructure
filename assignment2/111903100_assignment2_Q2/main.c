#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bst.h"


int main(){
	bst root;
	
	int i,NoOfElements;
	int *arr;
	
	printf("enter the no of elements :  ");
	scanf("%d",&NoOfElements);
	arr=(int*)malloc(NoOfElements*sizeof(int));

	for (i=0; i<NoOfElements; ++i){
		scanf("%d",&arr[i]);
	}




	
	root = (struct node*)malloc(sizeof(struct node));
	
	if(root == NULL) return 1;
	
	postorder_to_tree(&root , i-1 , 0 , arr); 	// i = end , 0 is start ; 
	printf("inorder traverse is :\n ");
	inorder_traverse(root);
	printf("\npreoder traverse is :\n ");
	preorder_traverse(root);
	printf("\npostorder traverse is :\n ");
	postorder_traverse(root);
	
	
}
