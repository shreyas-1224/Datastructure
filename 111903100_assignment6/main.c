#include<stdio.h>
#include "graph.h"


int main(){
	graph g ;
	init_graph(&g , 6);
	add_edge(&g ,0 , 1 , 2);
	add_edge(&g ,0 , 5 , 4);
	add_edge(&g ,5 , 4 , 6);
	add_edge(&g ,1 , 5 , 5);
	add_edge(&g ,2 , 3 , 1);
	add_edge(&g ,3 , 4 , 2);
	add_edge(&g ,1 , 2 , 7);
	
	
	dfs(g,0);
	printf("\n");
	//display(g);
	
	return 0;
}
