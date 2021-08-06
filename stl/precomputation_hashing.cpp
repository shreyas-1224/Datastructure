#include<bits/stdc++.h> 

#define loop(i , a , b)	for(int i = a ; i < b ; i++)

using namespace std ;

/* ques is .. given limits of indices , find sum of elements between those indices ; 
// 2 , 3 , 6 , 8 , 9   2 5 11 19 28 

int main(){

	int q , a , b , n ;
	cin >> n ;
	int v[n] ;
	cin >> q ;
	loop(i , 0 , n){
		
		cin >> v[i] ;
	}
	
	loop(i , 1 , n){
		
		v[i] = v[i] + v[i-1] ;
	}
	
	while(q--){
		
		cin >> a >> b ; 
		if(a != 0)
			cout << v[b] - v[a-1] ;
		else
			cout << v[b] ;	
	}
	
	
}

*/

// precomputation in 2-d array. given a 2-d array. and two co-ordinates . Find the sum of all the squares assuming first co-ordinate is top-leftmost and second coordinate in bottom right most . 

int main(){
	int n ;
	cin >> n ;
	int ar[n + 1][n + 1] ;
	loop(i , 1 , n + 1){
		loop(j , 1 , n + 1){
			cin >> ar[i][j];
		}
	}
	
	loop(i , 1 , n+1){
		loop(j , 1 , n+1){
			ar[i][j] = ar[i][j] + ar[i-1][j] + ar[i][j-1] - ar[i-1][j-1] ;
		}
	}
	
	int a , b , c , d , q;
	cin >> q ;
	
	while(q--){
		cin >> a >> b >> c >> d;
		
		cout << ar[c][d] - ar[a-1][d] - ar[c][b-1] + ar[a-1][b-1] ;
		
	}
	
		
}

























