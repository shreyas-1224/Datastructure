#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "graph.h"

/* 

Basically Dijkstras algo gives the minimum distance of every node from the source. We will need a visited array and then mst array. 
We will keep record of the minimum distance and also that index.

weight at source is zero and others is infinity (INT_MAX).

relaxation : updata distance of every node as : 
	     minimum of (value already present at that index in mst, summation of weight from source to current node and value at the source node.)

*/


void Dijkstras_algo(graph g , int source){

	int visited[g.n];
	int mst[g.n];
	
	
	for(int i = 0 ; i < g.n ; i++){
		mst[i] = INT_MAX;
		visited[i] = 0 ;	
	}
	
	mst[source] = 0; 
	
	int min ,edge_weight ; 
	int min_index = source ;
	
	
	//first loop will run n-1 times ;
	for(int i = 0 ; i < g.n - 1; i++) {
		
		source = min_index ;
		visited[source] = 1;
		min = INT_MAX;

		for(int j = 0 ; j < g.n ; j++){
			
			if(visited[j] != 1 && g.a[source][j] != 0){
				
				edge_weight = mst[source] + g.a[source][j];	// relaxation step.
				if(edge_weight < mst[j])
					mst[j] = edge_weight ;
				
				if(mst[j] < min){
					min = mst[j];
					min_index = j;
				}
				
			}	
			
		}
	
		
	}
	
	for(int i = 0 ; i < g.n ; i++){
		printf("%d--%d , weight : %d\n",source , i , mst[i] );
	}
	
	
}














