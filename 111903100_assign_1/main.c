#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "bst.h"

int main(){


	int i = 0;
	int mis; char* name;

	while(i != 7){
		printf("\nenter your choice\n0:initialze tree\t 1: insertNode()\t 2:removeNode()\n3 :search()\t 4:postorder()\t 5:Display_Level(t,i)\t 6:destroyTree()\n ");
		scanf("%d", &i);
		
		switch(i){
		
		case 0: printf("\n");
			bst t ; init(&t);
			break;
		
		case 1: printf("\n"); int j; 
			bst parent = NULL; int side=0;
			printf("first mis then name\n");
			printf("how many names you want add : ");
			scanf("%d ",&j);
			for(int n=0;n<j;n++){
					scanf("%d %s",&mis,name);
					insert(&t,&parent,side,mis,name);
			}
			break;
			
		case 2: printf("enter mis you want to delete\n");
			scanf("%d",&mis);
			remove_node(&t,mis);
			break;
			
		case 3: printf("enter mis you want to search\n");
			scanf("%d",&mis);
			printf("%s\n",search(t,mis));
			break;
			
		case 4: postorder_traverse(t);
			break;
		
		case 5: printf("enter the level\n");
			int k;
			scanf("%d",&k);
			level_i(t,k);
			break;
		
		case 6: destroy_all(&t);
		
		case 7: break;
		
		default: break;
			
	}
		
	
	}
	
}



