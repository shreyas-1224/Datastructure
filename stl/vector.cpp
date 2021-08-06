
/*
Karen, a coffee aficionado, wants to know the optimal temperature for brewing the perfect cup of coffee. Indeed, she has spent some time reading several recipe books, including the universally acclaimed "The Art of the Covfefe".

She knows n coffee recipes. The i-th recipe suggests that coffee should be brewed between li and ri degrees, inclusive, to achieve the optimal taste.

Karen thinks that a temperature is admissible if at least k recipes recommend it.

Karen has a rather fickle mind, and so she asks q questions. In each question, given that she only wants to prepare coffee with a temperature between a and b, inclusive, can you tell her how many admissible integer temperatures fall within the range?

Input
The first line of input contains three integers, n, k (1 ≤ k ≤ n ≤ 200000), and q (1 ≤ q ≤ 200000), the number of recipes, the minimum number of recipes a certain temperature must be recommended by to be admissible, and the number of questions Karen has, respectively.

The next n lines describe the recipes. Specifically, the i-th line among these contains two integers li and ri (1 ≤ li ≤ ri ≤ 200000), describing that the i-th recipe suggests that the coffee be brewed between li and ri degrees, inclusive.

The next q lines describe the questions. Each of these lines contains a and b, (1 ≤ a ≤ b ≤ 200000), describing that she wants to know the number of admissible integer temperatures between a and b degrees, inclusive.

Output
For each question, output a single integer on a line by itself, the number of admissible integer temperatures between a and b degrees, inclusive.


#include<bits/stdc++.h>

using namespace std ;

int main(){
	int n , k , q , count = 0 ;
	cin >>n >> k >> q ;
	int l , r ;
	vector<int>arr(200002,0) ;
	
	while(n--){
		
		cin >> l >> r ;
		arr[l]++ ;
		if(r+1 < n)arr[r+1]--;
	}
	for(int i = 1 ; i < arr.size() ;i++){
		arr[i]=arr[i] + arr[i-1];
	}
	
	while(q--){
		
		cin >> l >> r;
		for(int i = l ; i< r ; i++){
			if(arr[i] >= k)	count ++;
		}
		
		cout << count ;
		count = 0 ;
	}
	
		

}




#include<bits/stdc++.h>

bool f(int x , int y){
	return x > y ;
}

using namespace std ;


int  main(){
	
	vector<int>arr= {12, 4,2,43,89,234,2,34} ;
	
	sort(arr.begin() , arr.end()) ; // sorting in increasing order (nlog(n)); 	
	
	bool present = binary_search(arr.begin() , arr.end() , 43 ); // searching 
	
	//cout << present ;		// return 1 
	
	vector<int> :: iterator it = upper_bound(arr.begin() , arr.end() , 34) ;	// on sorted vector ; returns strictly greater of 34
	vector<int> :: iterator it2 = lower_bound(arr.begin() , arr.end() ,34);       // returns 34 or first number lesser than 34 ;
	
	cout << it - it2 ; 	// differance or iterators is possible o(1) . this is also the count of that number in the vector ;
	arr.insert(arr.end() , 4 , 34);
	//sort(arr.begin() , arr.end());
	
	//vector<int> ::iterator it3 = lower_bound(arr.begin() , arr.end() , 34);
	//vector<int> ::iterator it4 = upper_bound(arr.begin() , arr.end() , 34);
	
	//cout << it4 - it3 ;
	
	// sort vector in descending order ;
	sort(arr.begin() , arr.end() , f );
	vector<int> :: iterator it5 ;
	for(it5 = arr.begin() ; it5 != arr.end() ; it5++){
		cout << *it5 << endl;
	}

	// instead of vector<int> :: iterator it = ....
	// just write auto it = .... 
	for(int it6 : arr){
		cout << it6 ;
	}	
	
	// erasing the numbers ; erase number at index 5 ;
	arr.erase(arr.begin() + 5);
	// erasing all numbers from index 5 to 10 ;

	arr.erase(arr.begin()+ 5, arr.begin()+10) ;

	// to find the index of number try lower bound and the lower_boud iterator - arr.begin();	
}



















































input , query . each query has l and r . find sum from l index to r index. 

#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n , q ;
	cin>> n>> q;
	vector<int>arr(n,0);
	vector<int>arr2(n,0);
	int l , r ;
	
	for(int i = 0; i < n ;i++){
		cin>>arr2[i];
	}
	
	while(q--){
		
		cin>>l>>r;
		l-- ; r-- ;
		arr[l]++ ;
		if(r+1 < n)arr[r+1]-- ;
		 
	}
	
	for(int i = 1; i<arr.size() ;i++){
		arr[i] = arr[i] + arr[i-1];
	}
	
	sort(arr.begin(),arr.end());
	sort(arr2.begin(),arr2.end());
	
	long long int ans = 0 ;
	for(int i = 0 ; i<n ;i++){
		ans = ans + arr[i]*arr2[i];
	}
	
	cout<<ans;
		
		
	
}

*/


































/*

 you have given an array of zeros . and some queries of [l,r] from . increase value by 1 from l to r ; 

using namespace std ;

int  main(){
	
	int n ;
	cin >> n ;
	
	vector<int>arr(n , 0); 	// structure of vector is : vector<type>name(size, initilizer)
	int q ;
	cin >> q;
	while(q--){
		int l , r ;
		cin>>l>>r ;
		arr[l]++;
		if(r != n-1)
			arr[r+1]--;
	}
	
	for(int i=1 ; i<n ;i++){
		arr[i] = arr[i-1] + arr[i];
	}
	for(int i=0; i<n ; i++){
		cout <<arr[i]<<"\t" ;
	}
}


// vector properties : vector<int>arr(10,1); 

1. size :  	  arr.size() 
2. append :	  arr.push_back(n)	, n will be added at the back.
3. pop : 	  arr.pop_back();


*/










