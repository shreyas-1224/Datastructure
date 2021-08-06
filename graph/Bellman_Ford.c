#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "graph.h"

/*
 
Just like Dijkstras algo , Bellman_Ford algo gives the shorted path from a single source .It is a slower approach but its useful even for the negative edge weight while Dijkstras algo may or may not give the correct answer for the negative edge weight.

Bellman_Ford algo : go on relaxing all the edges n - 1 times.. n is number of the vertex.

Drawback : time complexity is O(E * n).	if its a complete graph , time complexity may go to O(n^3);
	   IF there is any cycle whose total weight is -ve. Bellman_Ford algo will not work there.
	   
Basic approach : create an array of structures of all the edges and relaxify them n-1 times.

*/

void Bellman_Ford(graph g , int source){

	node* array ;
	array = (struct node*)malloc(sizeof(struct node)*g.e);
	int count = 0 ;
	for(int i = 0 ; i < g.n ; i++){				// array of structures of edges.
		
		for(int j = 0 ; j < g.n ; j++){
		
			if(g.a[i][j] != 0){
				
				array[count].source = i;
				array[count].dest = j;
				array[count].weight = g.a[i][j];
				count++;		
			}	
		}
		
	}
	
	int mst[g.n] ;
	int edge_weight , round = g.n - 1;
	for(int i = 0 ; i < g.n ; i++)	
		mst[i] = INT_MAX;
		
	mst[source] = 0 ;
	
	while(round--){
		
		for(int i = 0 ; i < g.e ; i++){
			
			edge_weight = mst[array[i].source] + array[i].weight ;
			
			if(edge_weight < mst[array[i].dest]) {
				mst[array[i].dest] = edge_weight ;
				//printf("%d\t", edge_weight);
			}
		}
	}
	
	for(int i = 0 ; i < g.n ; i++){
		printf("%d---%d, weight : %d\n", source , i , mst[i] );
	}
	return ;
	
	
	

}










