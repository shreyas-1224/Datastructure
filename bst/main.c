#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bst.h"

int main(){
	bst t;
	init(&t);

	insert(&t,100);
	inorder_traverse(t);
	remove_node(&t,100);
	printf("\n");
	inorder_traverse(t);
	
	
	/*printf("max element : %d\n",max_element(t));
	printf("min element : %d\n",min_element(t));
	printf("total elements : %d\n",total_elements(t));	
	printf("total leaf nodes : %d\n",leaf_nodes(t));
	printf("is tree full ? :%d\n ",isfull(t) );
	printf("level order traversal : ");
	level_order(t);
	//right_view(t);
	//printf("\n");
	left_view(t);*/
	
	
	return 0;
}
