#include <bits/stdc++.h>
using namespace std;

class Rectangle{
	
	private:
		
		int length;
		int breadth;
		
	public:
		
		Rectangle(){			// constructor 
			length = 0;
			breadth = 0;
			cout << "Rectangle of lenght : " << length << "cm, breadth : " << breadth <<" cm is created." <<endl; 
		}
		
		Rectangle(int l, int b){	// constructor if both parameters are given by user.
			length = l;
			breadth = b;
		}
		
		int area(){
			return length*breadth;
		}
		
		int perimeter(){
			return 2*(length+breadth);
		}
		
		void show_dimensions(){
			cout<<"Length : "<<length << endl;
			cout<<"Breadth : "<<breadth<< endl;
		}
		
		void change_dimensions(int l,int b){
			length = l;
			breadth = b;
		}
};

int main(){
	int a , b ;
	cout << "enter length and the breadth " << endl;
	cin >> a >> b ;
	
	Rectangle r(a , b);
	cout<<"Menu : "<<endl;
	cout<<"1. Area of rectangle "<<endl;
	cout<<"2. Perimeter of rectangle "<<endl;
	cout<<"3. Change dimensions of rectangle "<<endl;
	cout<<"4. Display dimensions of rectangle "<<endl;
	cout<<"5. Exit "<<endl;
	
	int option;
	float length,breadth;
	cout<<"Enter a option : "<<endl;
	cin>>option;


	while(option != 5){
		
		switch (option){
			
			case 1:
				
				cout<<"Area of rectangle : "<<r.area()<<endl;
				break;
			
			case 2:
				
				cout<<"Perimeter of rectangle : "<<r.perimeter()<<endl;
				break;
				
			case 3:
				
				cout<<"Enter the new dimensions"<<endl;
				cout<<"Enter length : "<<endl;
				cin>>length;
				cout<<"Enter breadth : "<<endl;
				cin>>breadth;
				r.change_dimensions(length,breadth);
				break;
				
			case 4:
				
				cout<<"Dimensions of rectangle are : "<<endl;
				r.show_dimensions();
				
			case 5:
				
				break;
				
			default :
				
				cout<<"Enter a valid option !! "<<endl;
		}
		cout<<"\n";
		cout<<"Enter a option : "<<endl;
		cin>>option;
	}
	
	return 0;
}
