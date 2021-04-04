#include<bits/stdc++.h>

using namespace std ;

int main(){
	map<int , float>mp ;
	mp[0] = 2.0;
	mp[1] = 23.2;
	mp[4] = 12.19;
	
	unordered_map<int , int>ump;
	mp[0] = 2;
	mp[1] = 23;
	mp[4] = 12;
	
	if(ump.find(1) == ump.end())
		cout<<"not found";
	else
		cout << "found ";
	
}

/* 
	map is key value pair.. in cpp there is ordered map(sorted based on key) and unordered map .
	map<key,float>name ; 
*/
