// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int a[], int n, int X)
    {
        //Your Code Here
        sort(a+0 , a+n);
        int left , right , temp;
        for(int i = 0 ; i < n-1 ; i++){
            temp = X - a[i] ; 
            left = i+1 ; 
            right = n-1 ;
            
            while(left < right ){
                
                if((a[left] + a[right]) == temp)
                    return true ;
                
                if((a[left] + a[right]) < temp)
                    left++ ;
                
                else
                    right-- ;
            }
            
            
        }
        return false ;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends
