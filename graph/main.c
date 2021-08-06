#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

int main(){
	
	graph g ;
	g_init(&g , "adj_matrix.txt");
	//print(g);
	//printf("\n");
	DFS(g,0);
	//printf("\n");
	//prims(g , 0);
	//Dijkstras_algo(g,0);
	if(is_bipartite(g))
		printf("shreyas roxx");
	else
		printf("shreyas no roxx");
	return 0 ;
}
