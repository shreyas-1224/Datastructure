#include <bits/stdc++.h>
using namespace std;


int main() {
    	int n ;
	cin >> n ;
	
	vector<int>noneg(n);
	for(int i = 0 ; i < n ; i++){
	    cin >> noneg[i] ;
	}
	int i = 0 ;
	while(noneg[i] < 0 and i < n )
	    i++ ;
	    
	//12 3 -5 9 -8
	if(i != n-1){
		for(int j = i+1 ; j < n ; j++){
			if(noneg[j] < 0){
			int temp = noneg[i] ;
			noneg[i] = noneg[j] ;
			noneg[j] = temp ;
			i++ ;
			}
		}
	}
	for(int ii = 0 ; ii < n ; ii++){
	    
	    cout << noneg[ii] << " "; 
	}
	return 0;
}
