#include<bits/stdc++.h> 	// all the standerd cpp headers and stl .
#include<ext/pb_ds/assoc_container.hpp>



using namespace std ;
using namespace __gnu_pbds;

typedef tree<int , null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update > pbds ;

int main(){
	
	 pbds arr ;
	 
	 for(int i=0 ; i<10 ; i++){
	 	arr.insert(i);
	 }
	
	// find_by_order , gives pointer;
	cout <<*(arr.find_by_order(10-1));
	cout<<arr.order_of_key(6);

}

/*

// policy based datastructure

tree<type , null_type , comparater ,rb_tree_tag , tree_order_statistics_node_update  > name	// null type is because we are not mapping it to anything . 


special datastructure that can answer : 

1. find_by_order(k)   -----> return pointer to the k th largest element.

2. order_of_key()     -----> return how many elements are striclty lesser than this .
*/
