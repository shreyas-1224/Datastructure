#include<bits/stdc++.h>

using namespace std ;

class edge{
	public : 
	  int source ;
          int dest ;
          int weight ;
};

bool order(edge e1 , edge e2){
	return e2.weight > e1.weight ; 
}

int find_parent(int son , int* parent){
	
	if(parent[son] == son){
		return son ;
	}
	
	return find_parent(parent[son] , parent);
}


void kruskal(edge* input, int n , int e){
	
	sort(input , input + e , order);
	
	edge* output = new edge[n-1];
	int * parent = new int[n];
	
	for(int i = 0 ; i < n ; i++){
		parent[i] = i ;
	}
	
	int count = 0 , i = 0 ;
	
	while( count != n-1){
		
		if(find_parent(input[i].source , parent) != find_parent(input[i].dest , parent)){
			output[count] = input[i] ;
			count ++ ;
			parent[input[i].dest] = input[i].source ;
		}
		
		i++ ;
	}
	
	
	
}


void BFS_cpp(graph g , int u){

	vector<int>visited(g.n , 0) ;
	stack<int>s ;
	s.push(u);
	visited[u] = 1 ;
	
	while(!s.empty()){
		
		u = s.pop ;
		visited[u] = 1 ;
		for(int i = 0 ; i < g.n ; i++){
			if(visited[i] != 1 and g.a[u][i]){
				s.push(i);
				visited[u] = 1 ;
			}
		}
		
		cout << u << " " ;
	}
}


int main(){
	
	int n , e;
	cin >> n ;
	cin >> e ;
	edge* input = new edge[e];
	
	
	for(int i = 0 ; i < e ; i++){
		
		cin >> input[i].source ;
		cin >> input[i].dest ;
		cin >> input[i].weight ;	
	}
	
	kruskal( input , n, e);

	
}
