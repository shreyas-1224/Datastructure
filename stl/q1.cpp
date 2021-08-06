#include<bits/stdc++.h>

using namespace std ;


bool f(string a , string b){
	
	
	if(a+b > b+a)
		return true ;

	return false ;
	
}

int main(){

	int  n , m ;
	cin >> n ;
	vector<string>value ;
	
	for(int i = 0 ; i < n ; i++){
		
		cin >> m ;
		string str = to_string(m) ;
		value.push_back(str) ;
	}
	
	sort(value.begin() , value.end() , f) ;
	
	int p = n ;
	string answer = "" ;
	while(p--){
		
		cout<<value[n-p-1] ;
		
	}
	
	
	
}


/* question is we have given an array and we have to find the maximum sum of array but we cant take two consecutive numbers . 
   approach is to construct a mapping of each array member with index and sort in decreasing order . 



int main(){
	
	int q ;
	
	cin >> q ;
	while(q--){
		
		int n ,m ;
		cin >> n ;
		map<int , int , greater<>>steal ;
		vector<int>dp(n , 0);
		
		int ans = 0 ;
		for( int i=0 ; i < n ; i++){
			
			cin >> m ;
			steal.insert(make_pair(m , i)) ;
		}		
		
		for(auto i : steal){
			
			if(dp[i.second] != -1){
			
				ans += i.first ;
				if(i.second != n-1)
					dp[i.second + 1] = -1 ;
				if(i.second != 0)
					dp[i.second - 1] = -1 ;
			}
		
		}
		cout << ans << endl ;
	}
}

*/


















