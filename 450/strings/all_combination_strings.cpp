#include<bits/stdc++.h>

#define loop(i , a , b)	for(int i = a ; i < b ; i++)
#define ll 			long long int

using namespace std ; 

void all_combination(string name , int index){
	
	if(index + 1 == name.size()){
		cout << name << endl;
		return ;
	}
	
	loop(i , index , name.size()){
		
	}
}


int main(){
	
	string name ; 
	cin >> name ;
	all_combination(name , 0) ;
	
}

