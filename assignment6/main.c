#include<stdio.h>
#include "graph.h"


int main(){
	graph g ;
	init_graph(&g , 8);
	add_edge(&g,'a','b',12);
	add_edge(&g,'a','c',12);
	add_edge(&g,'a','d',12);
	add_edge(&g,'b','c',12);
	add_edge(&g,'c','d',12);
	add_edge(&g,'d','h',12);
	add_edge(&g,'c','e',12);
	add_edge(&g,'e','f',12);
	add_edge(&g,'d','f',12);
	add_edge(&g,'e','g',12);
	add_edge(&g,'f','g',12);
	add_edge(&g,'e','i',12); 
	
	//display(g);
	dfs(g,'a');
	printf("\n");
	bfs(g,'a');
	//display(g);
	
	return 0;
}
