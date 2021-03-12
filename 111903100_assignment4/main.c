#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#include "avl.h"


int main(){
	
	int i = 0;
	avl root ;
	char* name ;
	
	while(i <= 5){
		printf("\nenter your choice\n0:initialze tree\t 1: insertNode()\t 2:removeNode()\n3:inorder traverse\t 4:destroyTree()\t 5: quit\n ");
		scanf("%d", &i);
		
		switch(i){
			
			case 0 : init(&root);
				 break ;
			
			case 1 : printf("how many nodes you want to add ?\n");
				 int d ; 
				 scanf("%d",&d);
				 printf("Enter the data\n");
				 
				 for(int j = 0 ; j < d ; j++){
				 	
				 	scanf("%s",name);
				 	insert(&root , name);
				 }
				 break;
				 
		        case 2 : printf("Enter the data you want to delete\n");
		        	  scanf("%s",name);
		        	  delete_node(&root,name);
		        	  break ;
		        	  
			case 3 : printf("\n");
				 inorder_traverse(root);
				 break ;
			
			case 4 : destroy(&root);
				 break ;
			
			case 5 : break ;
			
			default : break ;
		}		
		
		
		
	
		
	
	}
	
	

	return 0;
}
