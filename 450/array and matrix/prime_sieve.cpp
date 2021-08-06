#include<bits/stdc++.h>

#define ll 	long long int
#define loop(i , a, b)		for(int i = a ; i < b ; i++)


using namespace std ;

// print all prime numbers below n ;

int main(){
	ll n ;
	cin >> n ;
	
	vector<bool>prime(n+1,true);
	
	prime[0] = false ;
	prime[1] = false ;
	prime[2] = true ;
	
	loop(i , 2 , n+1){
		if(prime[i] )
			cout << i << " ";
		for(int j = i*i ; j < n+1 ; j= j+i){
			prime[j] = false ;
		}
	}
	
	
	
	
}
