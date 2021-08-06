#include<bits/stdc++.h>

#define ll	long long int 
#define loop(i ,a , b)		for(int i = a ; i < b ; i++)


using namespace std ;

vector<int> fact(int n ){
	
	vector<int>sieve(n+1 , true);
	vector<int>boolean ;
	
	sieve[0] = false ;
	sieve[1] = false ;
	sieve[2] = true ;
	
	loop(i , 2 , n+1){
		
		if(sieve[i])
			boolean.push_back(i);
		
		for(int j = i*i ; j < n+1 ; j+=i){
			
			sieve[j] = false ;
		}
	}
	return boolean ;
}


int greatest_power(int a , int b){
	
	int k = b ;
	int i = 1;
	int count = 0 ;
	while(k ){
		
		k = (b/pow(a,i));
		count = count + k ;
		i++ ;
	
	}
	
	return count;
}


int main(){

	int n ; 
	cin >> n;
	vector<int>facts = fact(n);
	
	ll ans = 1 ;
	
	
	loop(i , 0 , facts.size()){
		//int k = ;
		//cout << k << endl;
		ans = ans * (greatest_power(facts[i] , n ) + 1) ;
		
	}
	
	cout << ans ;
	
	
		
}	
		


