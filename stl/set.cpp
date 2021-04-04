#include<bits/stdc++.h>

using namespace std ;

int main(){
	
	set<int> s ;
	s.insert(1);
	s.insert(2); 
	s.insert({1,2,12,3,4,5});  //insert another set elements too ;
	
	
	for(int x : s){
		cout << x << endl; 		// 1 2 3 4 5 12 
	}
	
	// find an element in set ;
	set<int> :: iterator it = s.find(12); 
	
	if(it == s.end()){
		printf("not present");
	}
	
	auto it2 = s.upper_bound( 4);          // 5
	auto it3 = s.lower_bound(10); 	// doest exit so it will point at s.end
	
	cout << *it2 << *it3;
	
	// to erase a number .. 
	s.erase(1) ; 
	for(int x : s){
		cout << x << endl; 		// 1 2 3 4 5 12 
	}
}
