#include<stdio.h>
#include<limits.h>
#include "bst.h"

int main(){
	
	bst root ;
	init(&root);
	insert(&root,100000);insert(&root,8000);insert(&root,2000);insert(&root,500);
	insert(&root,463);insert(&root,34);insert(&root,1234);insert(&root,250);
	printf("%d ",max_element(root));
	

}



