#include<bits/stdc++.h>

#define loop(i , a, b)		for(int i = a ; i < b ; i++)


using namespace std ;

/*

int main(){
	int n ; 
	cin >> n ;
	vector<vector<int>>intervals(n , vector<int>(2 , 0));
	
	loop(i , 0 , n){
		
		loop(j , 0 , 2){
			cin >> intervals[i][j];
		}
		
	}
	
	int k = intervals[n-1][1];
	
	vector<int>merge(k+1 , 0);
	
	loop(i , 0 , n){
		
		merge[intervals[i][0]] += 1 ;
		//if(merge[intervals[i][1]] != k )
		merge[intervals[i][1] ] -= 1;
	}
	
	
	
	
	loop(i , 1 , k+1)
		merge[i]  += merge[i-1] ;
		
	
	// now create our answers ; 
	vector<vector<int>>new_merge ;
	
	
	int i = 0 ;
	while(i <= k){
		
		if(merge[i] >= 1){
			vector<int>temp(2,0);
			temp[0] = i ;
			i++ ;
			while(merge[i] != 0){
				i++ ;	
			}
				
			temp[1] = i ;
			new_merge.push_back(temp);		
		}
		i++ ;
	}
	
	
	
	loop(j , 0 , new_merge.size()){
	
		loop(k , 0 , 2){
			cout << new_merge[j][k] <<" " ;
		}
	}	cout << endl ;	
}
*/

int main(){

	int n ; 
	cin >> n ;
	vector<vector<int>>intervals(n , vector<int>(2 , 0));
	
	loop(i , 0 , n){
		
		loop(j , 0 , 2){
			cin >> intervals[i][j];
		}
		
	}
	
	sort(intervals.begin() , intervals.end());
	
	vector<vector<int>>new_intervals ;
	vector<int>temp = intervals[0];
	
	int i = 1;
	while(i < n - 1){
		
		if( temp[1] < intervals[i][0]){
			intervals.push_back(temp);
			temp = intervals[i] ;
			//i++ ;
		}
		
		else if(temp[1] >= intervals[i][0]){
			if(temp[1] < intervals[i][1])
				temp[1] = intervals[i][1] ;
			//i++ ;
		}
			
		i++ ;			
	}
	
	if(temp[1] < intervals[n-1][0]){
		new_intervals.push_back(temp);
		new_intervals.push_back(intervals[n-1]);
	}
	
	if(temp[1] >= intervals[n-1][0]){
			if(temp[1] < intervals[n-1][1])
				temp[1] = intervals[n-1][1] ;
			
			new_intervals.push_back(temp);
	}
	
	loop(j , 0 , new_intervals.size()){
	
		loop(k , 0 , 2){
			cout << new_intervals[j][k] <<" " ;
		}
	}	cout <<"\n" ;	
}

