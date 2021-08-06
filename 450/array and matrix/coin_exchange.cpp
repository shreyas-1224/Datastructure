#include<bits/stdc++.h>

#define loop(i ,  a, b)	for(int i = a ; i < b ; i++)

using namespace std ;

int coin_exchange(vector<int>coins , int value){

	if(value == 0)
		return 0 ;
	if(value < 0)
		return INT_MAX ;
	
	int minimum = INT_MAX ;
	
	loop(i , 0 , coins.size()){
	
		int k = coin_exchange(coins , value - coins[i]);
		minimum = min(minimum , k);
	}
	return 1 + minimum ;
	
}


int main(){

	vector<int>coins{ 1 , 2 , 3, 5} ;
	
	int value ;
	cin >> value ;
	
	int k = coin_exchange(coins ,value);
	if(k < INT_MAX)
	
		cout << k ;
	else
		
		cout << "NOT POSSIBLE"	
}
