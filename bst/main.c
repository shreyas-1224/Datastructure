#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bst.h"

int main(){
	bst t;
	init(&t);

	insert(&t,100);
	insert(&t,200);insert(&t,50);insert(&t,25);
	insert(&t,150);insert(&t,300);insert(&t,160);
	insert(&t,90);//insert(&t,99);insert(&t,170);
	//insert(&t,100);insert(&t,22);insert(&t,180);
	
	inorder_traverse(t);
	printf("\n");
	//longest_path(t);
	printf("%d",total_nonleaf(t));
	
	
	
	
	return 0;
}
