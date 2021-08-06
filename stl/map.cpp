#include<bits/stdc++.h>

using namespace std ;



int main(){
	
	map<char , int  > cnt ;
	string s = "shreyas pradeep patil";
	
	for(char c : s)
		cnt[c] ++ ;
		
	cnt.insert(make_pair('z',3));	// insert pair ;
	cnt.erase('a');		// remove the pair , use key
	
	cout << cnt['a'] ;	// will easily gives the count of given data ;
	cout << cnt['z'] ;
	
	for(auto &it : cnt){
		cout << it.first <<" " << it.second << endl;		// loop in map. key and values are accessed by first and second;
	}
	
	// by default is ascending order for keys . to make is descending , use map<char, int , greater<>>;
	
	cout << endl;
	
	auto it4 = cnt.find('a');
	if(it4 == cnt.end())
		cout << "not present";
		
	
	
}


	map is key value pair.. in cpp there is ordered map(sorted based on key) and unordered map .
	map<key,float>name ; 
*/
