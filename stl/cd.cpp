#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n , q1 , q2 , q3 , i;
    cin >> n ;
    vector<int>arr(n,0);
    while(n--){
        cin >> i ;
        arr[arr.size()-n-1] = i ; 
    }
    
  
    cin>>q1 ;
    arr.erase(arr.begin() + q1 );
    cin >> q2;
    cin >> q3; 
    arr.erase(arr.begin()+ q2 , arr.begin() + q3);
    cout << arr.size()<<endl; 
    for(int j : arr){
        
        cout << j << " ";
    }
      return 0;
    

}
