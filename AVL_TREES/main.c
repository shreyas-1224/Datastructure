#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "avl.h"

int main(){
	avl t;
	init(&t);

	insert(&t,5);//inorder_traverse(t); printf("\n\n");
	insert(&t,2);//inorder_traverse(t); printf("\n\n");
	insert(&t,7);//inorder_traverse(t); printf("\n\n");
	insert(&t,1);//inorder_traverse(t); printf("\n\n");
	insert(&t,4);//inorder_traverse(t); printf("\n\n");
	insert(&t,3);//inorder_traverse(t); printf("\n\n");
	insert(&t,6);insert(&t,15);insert(&t,9);insert(&t,16);
	inorder_traverse(t); printf("\n\n");
	
	printf("%d",t->data);
	
	


	return 0;
}
