#include<bits/stdc++.h>

#define int  		long long int 
#define loop(i , a , b)	for(int i = a ; i < b ; i++)

using namespace std ;

//find a fibonacci of a number using dp ;

int32_t main(){
	int n ; 
	cin >> n ;
	vector<int> dp(n+1,0) ;
	
	dp[0] = 1 ;
	dp[1] = 1 ;
	dp[2] = 2 ;
	
	loop(i , 3 , n+1){
		dp[i] = dp[i-1] + dp[i-2] ;
		cout << dp[i] << " ";
	}
	
	
	
}
