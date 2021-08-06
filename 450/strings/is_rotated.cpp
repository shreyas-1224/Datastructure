#include<bits/stdc++.h>

using namespace std ; 

int is_rotated(string a, string b){
	
	string c = a + a ;
	/*
	int start = 0 , i = 0;
	while(i < c.size()){
		if(c[i] == b[start]){
			while(i < c.size() and start < b.size()){
				if(c[i] == b[start]){
					i++ ; 
					start++ ; 
				}
				else
					break;
				   
			}
			if(start == b.size())
				return 1;
			else
				start = 0 ;
		}
		i++ ; 
	}
	return 0;
	*/
	
	// inbuild method to find substring : 
	
	int found = c.find(b);
	
	if(found != string::npos and a.size() == b.size())
		return 1;
	else
		return 0;
	
}


int main(){
	string a,b ; 
	cin >> a ; 
	cin >> b ;	
	if(is_rotated(a,b))
		cout << "yes ! they are same and rotated\n";
	else
		cout << "no! they are not same\n";
}
