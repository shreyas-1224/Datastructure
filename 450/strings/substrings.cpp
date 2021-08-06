#include <bits/stdc++.h>
using namespace std;



void subseq(string s , string name , int i , int n,int *count ){
    
    if(i == n){
        (*count)++;
        cout << s << endl;
        return ;
    }
    else{
        subseq(s , name , i+1 , n,count);
        s = s + name[i];
        subseq(s , name , i+1 , n,count);
    }
}

int main() {
    string n ;
	cin >> n;
    int count = 0;
    subseq("",n,0,n.size(),&count);
    cout << count ; 
	return 0;
}
