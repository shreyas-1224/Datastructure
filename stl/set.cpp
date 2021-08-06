#include<bits/stdc++.h>

using namespace std ;
	
// q queries and each queries has a pair , then at the end a number n , and output is the pair in which that number lies .

int main(){
	
	int q , a , b , n;
	
	set<pair<int , int>> m ;
	
	m.insert({2,10});
	m.insert({10,20});
	m.insert({21,30});
	m.insert({31,400});
	m.insert({401,450});
	
	cin >> n;
	
	auto it = m.upper_bound({ n , INT_MAX});
	if(it == m.begin() || it == m.end()){
		cout << "not present";
		return 1;
	}
	it-- ;
	cout << (*it).first << " " << (*it).second;
	return 0; 
	pair<int , int > p = *it ;
	
	if(p.first <= n && n <= p.second)
		cout << "its present " << p.first <<" " << n << " " << p.second;
}

/*
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
*/
