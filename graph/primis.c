#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include "graph.h"


void prims(graph g , int u){

	int visited[g.n] ;
	int parent[g.n] ; parent[u] = -1 ;
	int mst_key[g.n] ;
	int psudo_parent = u ;
	
	for(int i = 0 ; i < g.n ; i++){
		
		visited[i] = 0 ;
		mst_key[i] = INT_MAX ;
	} 
	mst_key[u] = 0 ;
	visited[u] = 1 ;

	for(int m = 0; m < g.n - 1; m++){
		
	
	//-------------------------assign values to the respective array mst_key-------------------
	
		for(int l = 0; l < g.n ; l++){
		
			if(visited[l] != 1 && g.a[u][l] != 0){
				if(g.a[u][l] < mst_key[l]){
					mst_key[l] = g.a[u][l];
				
				}
			}
		}	
		
	//-------------------------finding minimum of that array ----------------------------------
	
		int min = INT_MAX , min_index = u ,j ; 
		for(j = 0 ; j < g.n ; j++){
			if(min > mst_key[j] && visited[j] != 1 ){
				min  = mst_key[j];
				min_index = j ;
			}
		
		}
		
		visited[min_index] = 1 ;
		
	//------------------------if min value is not changed..we need to check the correct parent.
		while(min != g.a[u][min_index]){
			
			if( (parent[u] != -1 ) && min == g.a[parent[u]][min_index]){
				psudo_parent = u ;
				u = parent[u] ;
				
			}
			
			else if (min == g.a[psudo_parent][min_index])	{
				psudo_parent = u ;
				u = psudo_parent ;
			}
			
			else
				u = parent[u];
			
		}	
		
		
		parent[min_index] = u ;
		//psudo_parent = u ;
		u = min_index ;
	} 
	
	// printing ;
	
	for(int i = 0 ; i < g.n ; i++){
		printf("%d--%d\n", parent[i],i);
	}		

}

