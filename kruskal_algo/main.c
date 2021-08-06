#include<stdio.h>
#include "kruskal.h"


int main(){
	
	graph g ; 
	g_init(&g , "adj_matrix.txt");
	kruskal(g);

}
