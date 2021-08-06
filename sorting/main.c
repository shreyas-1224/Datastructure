#include<stdio.h>
#include<stdlib.h>
#include "kruskal_algo.h"


int main(){
	
	graph g ;	
	g_init(&g , "adj_matrix.txt") ;
	//print(g);
	
	
	
	kruskal_algo(g );
	return 0 ;
} 

