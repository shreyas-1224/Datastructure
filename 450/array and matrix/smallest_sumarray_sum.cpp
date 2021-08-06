// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:

    int sb(int arr[], int n, int x)
    {
        // Your code goes here   
        int sum = 0 ; 
        int left = 0 , right = 0 ; 
        int mini = 0 ;
        int minimum ;
        while(right < n){
            
            while(sum < x){
                sum = sum + arr[right];
                right++ ;
            }
            right-- ; 
            mini = right-left+1 ;
           // cout << "first mini is" << mini ; 
            minimum = mini ;
            sum = sum - arr[left] ; 
           // cout << "sum is " << sum << endl ;
            left++ ; 
            mini-- ;
            
            while(right < n){
               
                if(sum > x){
                   // cout << sum << endl ;
                    minimum = min(minimum , mini);
                    //cout << "mini is" << mini ;
                    mini-- ;
                    sum = sum - arr[left];
                    left++ ; 
                    
                }
                else{
                    right++ ;
                    sum = sum + arr[right] ;
                    mini++ ;
                    
                }
            }
            
            
            
            
        }
       // minimum = min(mini , minimum);
        return minimum ;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends
