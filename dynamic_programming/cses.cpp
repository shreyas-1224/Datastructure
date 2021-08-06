#include<bits/stdc++.h>

#define loop(i , a, b)		for(int i = a ; i < b ; i++) 


using namespace std ;

/* you have given a set of numbers and a number. find in how many way you can arrage that set numbers to get their sum as given number..repeatation allowed .

input is number and sum.

ans : suppose set is {2 , 3 , 5 } and n = 9 ;

f(n) = (2 , f(7)) + (3 , f(6)) + (5 , f(4)) ;







int main(){
	
	int n , x;
	
	cin>> n >> x;
	vector<int> array(n  , 0) ;
	vector<int> states(x + 1, 0) ;
	int  i ,j ;
	
	loop(i , 0 , n ){
		cin>>array[i] ;
	}
	
	// array contains the set ; 
	
	states[0] = 1 ;	
	loop( i , 1 , x+1){
		loop( j , 0 , n){
			
			if(array[j] > i)	break ;
			states[i] += states[i - array[j]];
		}
	}
	
	cout <<states[x];
	

}


 ques : 2 . same problem as previous , but here use combination... for example , combination 2 2 5 can be used only once .

answer : reverse the process... first we used to traverse from n to 0 now , go from zero to n and for each element in the set




int main(){
	
	int n , x;
	
	cin>> n >> x;
	vector<int> array(n  , 0) ;
	vector<int> states(x + 1, 0) ;
	states[0] = 1 ;
	int  i ,j ;
	
	loop(i , 0 , n ){
		cin>>array[i] ;
	}
	
	// array contains the set ; 
	
	loop(i ,0 , n){
		int j ;
		loop(j , 1 , x+1){
			int k = j ;
			do{
				states[j]+= states[k] ;
				k = k % array[2] ;
			}while(states[k] != 0) ;5
		
		}	
			
	}	
	cout <<states[x];
	

}


q3 : you have given a number n and you can subtract any one digit number from it . how many steps are needed to turn the given number into zero ?  



*/
























