// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int row, int column) 
    {
        // code here 
        vector<int>mat(row*column , 0) ; 
        int c = 0 , r = 0 ; 
        int count = 0 ; 
        while(count != row*column){
            
            while( c < column and matrix[r][c] != INT_MIN  ){
                mat[count] = matrix[r][c];
                matrix[r][c] = INT_MIN ;
                c++ ; count++ ;
            }
            
            c-- ; 
            r++ ; 
            while( r < row and matrix[r][c] != INT_MIN ){
                mat[count] = matrix[r][c];
                matrix[r][c] = INT_MIN ;
                r++ ; count++ ;
            }
            
            r-- ;
            c-- ; 
            
            while(c >= 0 and matrix[r][c] != INT_MIN ){
                mat[count] = matrix[r][c];
                matrix[r][c] = INT_MIN ;
                c-- ; count++ ;
            }
            
            c++ ;
            r-- ; 
            
            while(r >= 1 and matrix[r][c] != INT_MIN ){
                mat[count] = matrix[r][c];
                matrix[r][c] = INT_MIN ;
                r-- ; count++ ;
            }
            
            r++ ; 
            c++ ; 
            
            
        }
        return mat ;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
