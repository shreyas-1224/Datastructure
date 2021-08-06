#include<stdio.h>

typedef struct bnode{
	
	int min ;
	int max ;
}bnode ;


int main(){
	
	int arr[] = {1,0,93,-4,23,8} ;
	bnode node ;
	node.min = arr[0] ;
	node.max = arr[0] ;
	
	for(int i = 1 ; i < 6 ; i++){
		
		if(node.min > arr[i])
			node.min = arr[i] ;
		if(node.max < arr[i] )
			node.max = arr[i] ;
	}
	
	printf("%d-%d",node.min , node.max);
}
