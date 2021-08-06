#include<bits/stdc++.h>

#define loop(i , a , b) 		for(int i = a ; i < b ; i++)
#define ll 		long long int

using namespace std ;

int main(){
	
	int n ;
	cin >> n ;
	vector<ll>shares(n) ;
	
	loop(i , 0 , n){
	
		cin >> shares[i] ;
	}
	// share vector is ready .
	
	// keep track of min , max , local max and global max ... should be done within one traversal ie O(n) ;
	// like cadanes algo 
	
	int minimum = shares[0] ; 
	int maximum = shares[0] ;
	int profit = 0 ; 
	int local_profit = 0 ;
	
	loop(i , 1 , n){
		
		local_profit = shares[i] - minimum ;
		
		if(local_profit > profit)
			profit = local_profit ;
			
		if(shares[i] > maximum)
			maximum = shares[i];
		
		else if(shares[i] < minimum ){
		
			minimum = shares[i] ;
			maximum = shares[i] ;
			local_profit = 0 ;
 		}
	
	}
	
	if(profit == 0)
		cout << -1 ;
	else
		cout << profit ;
	
	
	
}
