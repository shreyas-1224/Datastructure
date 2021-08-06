#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

class polygon{
	
	protected :
		
		int cm;
		
	public :
		
		polygon(){
			cm = 4;
			cout<<"A polygon of cm "<<cm<<" is created."<<endl;
		}
		
		polygon(int data){
			this->cm = data;
		}
		
		void get_number_of_dimensions(){
			cout<<"The polygon has "<<cm<<" cm."<<endl;
		}
		
		void set_dimensions(int data){
			cm = data;
		}
};

class Rectangle : public polygon{			// subchild of class polygon.
	
	private :
		
		int length;
		int breadth;
		
	public :
		
		Rectangle(int lenght, int breadth) : polygon(2) {
			
			this->length = length;
			this->breadth = breadth;
			
		}
		
		Rectangle(){
			
			length = 2;	
			breadth = 3;
			cout<<"A rectangle of length "<<length<<" and breadth "<<breadth<<" is created."<<endl;			

		}
		
		int area(){
			
			return length*breadth;
			
		}
	
		int perimeter(){
			
			return 2*(length+breadth);
			
		}
		
		void change_dimensions(int l,int b){
			length = l;
			breadth = b;
		}
		
		void report_dimensions(){
			
			cout<<"Length of rectangle : "<<length<<endl;
			cout<<"Breadth of rectangle : "<<breadth<<endl;
			cout<<"Dimensions of rectangle : "<<cm<<endl;
			
		}
};

class Square : public polygon{
	
	private : 
	 
		int side;
		
	public :
		
		Square(int side)  {
			
			this->side = side;
			
		}
		
		Square()  {
			side = cm;
			cout<<"A square of side "<<side<<" is created."<<endl;
		}
		
		int area(){
			
			return side*side;
			
		}
	
		int perimeter(){
			
			return 4*side;
			
		}
		
		void change_dimensions(int s){
			side = s;
		}
		
		void report_dimensions(){
			
			cout<<"Side of square : "<<side<<endl;
			cout<<"Dimensions of square : "<<cm<<endl;
			
		}	
};

int main(){
	
	polygon P;
	Square S;
	Rectangle R;
	
	cout<<"\n Menu : "<<endl;
	cout<<"1. Modifyning cm of polygon."<<endl;
	cout<<"2. Display number cm of polygon."<<endl;
	cout<<"3. Change side of square."<<endl;
	cout<<"4. Change cm of rectangle."<<endl;
	cout<<"5. Report cm of square."<<endl;
	cout<<"6. Report cm of rectangle."<<endl;
	cout<<"7. Get area of square."<<endl;
	cout<<"8. Get area of rectangle."<<endl;
	cout<<"9. Get perimeter of square."<<endl;
	cout<<"10. Get perimeter of rectangle."<<endl;
	cout<<"11. Break"<<endl;
	
	int choice, l, b, d, s;
	cout<<"Enter a choice : ";
	cin>>choice;
	
	while(choice != 11){
		
		switch(choice){
			
			case 1:
				
				cout<<"Enter the number of cm of polygon : ";
				cin>>d;
				break;
				
			case 2:
				
				P.get_number_of_dimensions();
				break;
				
			case 3:
				
				cout<<"Enter side of square : ";
				cin>>s;
				S.change_dimensions(s);
				break;
				
			case 4:
			
				cout<<"Enter length of rectangle : ";
				cin>>l;
				cout<<"Enter breadth of rectangle : ";
				cin>>b;
				R.change_dimensions(l,b);
				break;
				
			case 5:
			
				S.report_dimensions();
				break;
				
			case 6:
				
				R.report_dimensions();
				break;
				
			case 7:
				
				cout<<"Area of square is "<<S.area()<<" square units."<<endl;
				break;
				
			case 8:
				
				cout<<"Area of rectangle is "<<R.area()<<" square units."<<endl;
				break;
				
			case 9:
				
				cout<<"Perimeter of square is "<<S.perimeter()<<" units."<<endl;
				break;
				
			case 10:
				
				cout<<"Perimeter of rectangle is "<<R.perimeter()<<" units."<<endl;
				break;
				
			case 11:
			
				return 0;
				
			default :
			
				cout<<"Enter a valid !!"<<endl;			
				
		}
		cout<<"\nEnter a choice : ";
		cin>>choice;		
		
	}
	
	return 0;
}
