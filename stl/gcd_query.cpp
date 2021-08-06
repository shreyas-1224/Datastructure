#include<bits/stdc++.h>

#define loop(i , a, b)		for(int i = a ; i < b ; i++)
//#define int 			long long int
using namespace std ;

//given an integer and two queries , and two indices L and R . print gcd for 0 to L - 1 and R + 1 to n - 2 for each query ; 


int32_t main(){
	
	int t ; 
	cin >> t ;
	while(t--){
		int n , q ;
		cin >> n >> q;
		int a[n + 5] ;
		a[0] = 1 ;
		loop(i , 1 , n+1){
			//cout << "reaced";
			cin >> a[i] ;
		}
		
		loop(i , 1 , n){
			if(i != n)
				a[i] = __gcd(a[i] , a[i+1]);
		}
		
		
		int l , r ;
		//cout << "reace";
		while(q--){
			
			cin >> l >> r ;
			if(l == 1 and r != n)
				cout << __gcd(a[r+1] , a[n]);
			else if(l != 1 and r == n)
				cout << __gcd(a[l-1] , a[0]);
			else
				cout << __gcd(a[l-1] , a[n]);
			
		}
	}
	
	  

}

