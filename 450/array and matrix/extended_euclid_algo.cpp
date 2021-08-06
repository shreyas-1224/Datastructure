#include<bits/stdc++.h>

#define loop(i , a, b)		for(int i =a ; i < b ; i++)
#define ll 			long long int ;

using namespace std ;

class euclid {
	
	public:
		ll x ;
		ll y ;
		ll gcd;
};


euclid extend_euclid_algo(ll a , ll b){
	
	if(b == 0){
		euclid base ;
		base.x = 1 ;
		base.y = 0 ;
		base.gcd = a ;
		return base ; ;	
	}
	
	euclid temp = extend_euclid_algo(b , a%b);
	euclid myans ;
	myans.gcd = temp.gcd ;
	myans.x = temp.y ;
	myans.y = (temp.x - temp.y *(a/b));
	return myans ;
	
}
