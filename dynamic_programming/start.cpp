#include<bits/stdc++.h>
#include<math.h>

#define loop(i , a , b)	for(int i = a ; i < b ; i++)

/* n friends going to party , one guy or a girl can go alone or in pair... total number of ways ? 

*/

#define ll long long 



using namespace std ;

int fibonacci(int n , vector<int> states){
	
	if(n == 1 or n == 0)
		return n ;
	if(states[n] != -1)
		return states[n] ;
	int ans = fibonacci(n-1 , states) + fibonacci(n-2 , states)  ;
	states[n] = ans ;
	return ans ;
	
}

ll int party( ll int n){
	

	if(n == 1 )
		return 1 ;
	else if(n == 2)
		return 2 ;
		
	
	return party(n-1) + (n-1) * party(n-2)  ;
	// lets see nth friend wants to go alone... then there is only one way for him and problems reduces to n - 1 . friend . 
	// now suppose he wants to in pair... so problems reduces to n-2 people.. and number of ways he can chooses his pair is n- 1
	
}


// the number of parameters on your problem is dependent gives you hint of size of dp ;
// recursive logic + storage -> memoization or top down dp 

// bottom up -> tabulation . 
//if you know the order in which states are computed , use this .
// use the smaller problem first . for example ..

int party_friend(int n){
	
	vector<int>states(n+1 , 0);
	states[1] = 1 ;
	states[2] = 2 ;
	int i ;
	for(int i = 3; i < n+1 ; i++){
		
		states[i] = states[i-1] + (i-1) * states[ i-2] ;
	}
	
	return states[n];
}



// ques : Your tast is to ocunt the number of ways to construct sum by throwing a dize one or more times . outcome between 1 and 6 ;
// recurance relation is f(n) = f(n-1) + f(n-2) + .. f(0) ;
int sum_dice(int n ){
	
	vector<int> states(n+1, 0 );
	states[0] = 1 ;
	states[1] = 1 ;
	states[2] = 2 ;
	
	for(int i = 3 ; i < n+1 ; i++ ){
		
		for(int j = 1 ; j <= 6 ; j++){
			if(j > i)	break ;
			states[i] += states[i-j] ;
		}	
	
	}
	return states[n] ;
	
		

}

// ques : there are n stones . 1 , 2, 3 ,... ,N . he is at stone 1 and want to go at stone N . he can do i+1 or i+2 . 
//and cost is | h(i)-(j)| . j is stone he landed.find the minimum cost.
// start from the last..you are at stone n and possible cases that you have come from is n-1 or n-1...for n-1..its n-2 or n-3...so on..
// for stone 2...you have come from stone 1 only..

/*

recurance : 
	f(n) = min( f(n-1) + (an - an-1) or f(n-2) + (an - an-2) ) ;
	f(2) = f(2)-f(1) ;
	f(3) = min( f(2) + a3 - a2 ,  f(1) + a3 - a1 );
	
	we need to use top down approach...store the data and move ;


*/



void stone_frog(int n , vector<int>array ){
	
	vector<int>states(n+1 );
	
	states[1] = 0 ;
	states[2] = abs(array[1] - array[2]);
	//states[3] = min(abs(array[1] - array[3]) , abs(array[3] - array[2] ) + states[2] ) ;
	int i ;
	loop(i , 3,  n+1)
		states[i] = min(states[i-1] + abs(array[i] - array[i-1]) , states[i-2] + abs(array[i] - array[i-2]));

	cout << states[n] ;
	
}

int main(){
	int n ;
	cin >> n;	 
	vector<int> array(n+ 1 ) ;
	for(int i = 1 ; i < n+1 ; i++){
		cin >>array[i];
	}
	
	stone_frog(n , array);
}


// when to use dp ? 

//1) overlapping problem.
//2) optimal substrcture. 

