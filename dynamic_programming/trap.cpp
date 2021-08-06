#include<bits/stdc++.h>

#define 					ll long long
#define loop(i , a , b)			for(int i = a ; i < b ; i++) ;
#define reverse_loop(i , a , b )		for(int i = a ; i >= b ; i--);
using namespace std ;


/*
given an 2-d array like a maze. find the number of ways we can reach to the source ;
lets try general recursion approach . can travel in left and down only; 

int count ;

int main(){
	

	//  a is that array.
	create_path(a , x , y , fx , fy );
	return 0 ;
}

void create_path(a , x , y , fx , fy){
	// check for invalid paths ;
	
	if(x > fx or y > fy or a[x][y] == 1)
		return ;

	else if (x == fx - 1 and y == fy - 1){
		count++ ;
		return ; 
	}

	create_path(a , x+1 , y , fx, fy);
	create_path(a , y+1 , y , fx, fy);
	
	return ;                                                      		
}



 now lets use dp in this problem . but why to use dp ? ...... go from the last place. and then traverse to the source , filling up the number of successful count.. like , if we are at the destination , then there is 0 ways...if we are one left to the destination , there are 1 chances ... now lets create the recurance relation. just like counting problem.

f(x , y) = f(x , y+1) + f( x + 1 , y) ;  we will need 1 2-D dp.

input : line 1 in n , size of the grid.
then each line has characters . and * , * means trap.

output : no of paths .

*/


int main(){
	 
	int n ;
	cin >> n ;
	vector<vector<int> > dp(n , vector<int>(n , 0));
	int i ;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char c ;
			cin >> c ;
			dp[i][j] = (c == '.') ? 1 : 0 ;
		}
	}
	
	if(dp[n-1][n-1] == 0 ){
		cout << 0 ;
		return 0 ;
	}
	
	vector<vector<int>>states(n , vector<int>(n , 0));
	states[0][0] = 1;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if ( dp[i][j] == 0 )
				states[i][j] = 0 ;
				
			else if(i == 0 and j != 0)
				states[i][j] = dp[i][j-1] ;
			
			else if(j == 0 and i != 0)
				states[i][j] = dp[i-1][j] ;
			else if(i != 0 and j != 0){
				
				states[i][j] = states[i-1][j] + states[i][j-1] ;	
			}
			
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			cout<<states[i][j] <<" ";
			
		}
		cout<<"\n";
	}
	
	cout << states[n-1][n-1];

} 



















