// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:   
       int maxi(int a , int b , int c) {
           if(a>b){
               if(a>c)
                    return a ;
                else
                    return c ;
           }
           else{
               if(b>c)
                    return b ;
                else
                    return c ;
           }
       }
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int>common ;
            int i = 0 ;
            int j = 0 ;
            int k = 0 ;
            int m = INT_MIN ;
            int p ;
            while(i < n1 and j < n2 and k < n3){
               
                p = maxi(A[i] , B[j] , C[k]) ;
                if(m == p){
                    i++ ;
                    j++ ;
                    k++ ;
                }
                
                while(i < n1 and A[i] < p){
                    i++ ;
                }
                
                while(j < n2 and B[j] < p){
                    j++ ;
                }
                while(k < n3 and C[k] < p){
                    k++ ;
                }
                
                if(A[i] == B[j] and B[j] == C[k]){
                    
                    if(m != p)
                        common.push_back(A[i]) ;
                    m = p ;
                    i++ ; j++ ; k++ ;	
                }
            }
            
            return common ;
            
        }

};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends
