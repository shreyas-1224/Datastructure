#include<bits/stdc++.h>


#define ll long long int
using namespace std ; 

class covid_patient {

	private : 
		string name ;
		string symptoms ;
		string hospital_name ;
		string date_of_birth ;
		string blood_group ;
		string address ;
		ll number ;
		ll adhar_card_no ;
		
		
	
	public :
		int appointment_no ;
		static int count ;
	
	
	//default constructor
	covid_patient(){
		
		fflush(stdin) ;
		this->name = "\0";				
		this->symptoms = "\0";			
		this->hospital_name = "\0";
		this->date_of_birth = "\0";
		this->blood_group = "\0";		
		this->address = "";
		this->number = 0;
		this->adhar_card_no = 0;
		this->appointment_no = 0 ;
		count++ ;
	}
	
	
	// user defined constructor
	covid_patient(string n_name , int a_appointment_no){
		
		this->name = n_name ;
		this->appointment_no = a_appointment_no ;
	}
	
	// copy costructor .. used to construct a object by copying other object.
	
	covid_patient(const covid_patient &obj){
		
		this->name = obj.name ;
		this->symptoms = obj.symptoms ;
		this->hospital_name = obj.hospital_name ;
		this->date_of_birth = obj.date_of_birth ;
		this->blood_group = obj.blood_group ;
		this->address = obj.address ;
		this->number = obj.number ;
		this->adhar_card_no = obj.adhar_card_no ;
		this->appointment_no = obj.appointment_no ;
	}
	void get_data(){
		
		string anything ;
		cout << "\n" ;
		getline(cin , anything) ; 
		fflush(stdin);
		cout << "enter your name :- ";
		getline(cin , this->name);
		cout << "enter your symptoms :-"; 
		getline(cin , this->symptoms) ;
		cout << "enter your hospital_name :-"; 
		getline(cin , this->hospital_name) ;
		cout << "enter your date_of_birth :-"; 
		getline(cin , this->date_of_birth) ;
		cout << "enter your blood_group :-"; 
		getline(cin , this->blood_group) ;
		cout << "enter your address :-"; 
		getline(cin , this->address) ;
		cout << "enter your number :-"; 
		cin >> this->number ;
		cout << "enter your adhar_card_no :-"; 
		cin >> this->adhar_card_no ;
		cout << "enter your appointment_no :-"; 
		cin >> this->appointment_no ;
		cout << endl;
		
	}

	
	void display(){
	
		cout << "patient name :- " ;
		cout << this->name << endl ;
		cout << "patient symptoms :- " ;
		cout << this->symptoms << endl ;
		cout << "Hospital name :- " ;
		cout << this->hospital_name << endl ;
		cout << "patient's date of birth:- " ;
		cout << this->date_of_birth << endl ;
		cout << "patient's blood group :- " ;
		cout << this->blood_group << endl ;
		cout << "patient's address :- " ;
		cout << this->address << endl ;
		cout << "patient's contact number :- " ;
		cout << this->number << endl ;
		cout << "patient's adhar card no :- " ;
		cout << this->adhar_card_no << endl ;
		cout << "patient's appointment_no :- " ;
		cout << this->appointment_no << endl ;
		
	}
	
	static void condition(){
		
		if(count < 1000)
			cout << "Not a critical condition "<< endl ;
		else
			cout << " Yes ! It is a critical condition " << endl; 
	}
	
	friend class covid_patient_2 ;
	
};

class covid_patient_2{
	
	public :
	inline void patient_count(){
		
		cout << "total no of patient is :- " << covid_patient :: count << endl ;
	}
};



int covid_patient :: count = 0 ;


int main(){
	
	list <covid_patient> db ;
	
	cout << "Menu for the database : "<<endl;
	cout << "1. To enter the patient record" <<endl;
	cout << "2. To delete patient record" <<endl;
	cout << "3. To display entire database" << endl;
	cout << "4. To modify a particular record" << endl;
	cout << "5. To list the total number of record entries count" << endl;
	cout << "6. To search for a patient" << endl;
	cout << "7. To know the condition of covid" << endl;
	int choice, appno;
	while(1){
		cout << "\nEnter a choice : ";
		cin >> choice;
		fflush(stdin);
		covid_patient *p ;
		p = new covid_patient() ;
		
		switch (choice){
			
			case 1:
				(*p).get_data();
				db.push_back(*p);
				break;
				
			case 2:
				cout<<"Enter the appointment number to be deleted : ";
				cin >> appno;
				for(auto i : db){
					if(i.appointment_no == appno){
						i.~covid_patient();
					}
					
		
										
					
				}
				break ;
				
			case 3:
				cout << "The record is as follows : " << endl;
				for(auto i : db){
					i.display();
					cout << endl;
				}
			
				break;
			case 4:
				cout << "Enter the appointment number of the record to be modified : "<<endl;
				cin >>appno;
				for(auto i : db){
					
					if(i.appointment_no == appno)	{	// using copy constructor here .
						//cout << "reached" ;
						covid_patient *q ;
						q = new covid_patient() ;
						(*q).get_data() ;
						covid_patient i = *q ;
					}
				}
				
				break;
			case 5:
				covid_patient_2 b ;
				b.patient_count();
				break;	
				
			case 6: 
				int No; 
				cin >> No ;
				for(auto i : db){
					
					if(i.appointment_no == No){
						
						i.display();
					}
					
				}		
				break ;
				
			case 7:
				covid_patient::condition();
				break; 
		}
	
	
	}
	
	return 0;
}






























































/*
class covid_patient {

	private :
		string name ;
		string symptoms;
		string hospital_name;
		string date_of_birth;
		string blood_group;
		string address ;
		ll number ;
		ll adhar_card_no ;
		
	public : 
		static int count ;			// static variable in a class are shared by all the objects . there can not be multip-
							// copies of it. so static variable can not be initiated with constrctor.
		int appointment_number;
		
		//default constructor : 
		covid_patient(){
			count ++ ;
			
			this->name = "";			// this is a pointer to the given instance.
			this->symptoms = "";
			this->hospital_name = "";
			this->date_of_birth = "";
			this->blood_group = "";		// you can do this without using this ...but name = name will give you garbage value !
			this->address = "";
			this->number = 0;
			this->adhar_card_no = 0;
			this->appointment_number = 0 ;
		}
		
		
		// defined constructor ;
		covid_patient(string name , int appointment_number){
			count ++ ;
			this->name = name;
			this->appointment_number = appointment_number;
		}
		
		//copy constructor : uses other object to initiate the current object with that object value. just copying the object.
		covid_patient(const covid_patient &obj){
		
			this->name = obj.name;
			this->appointment_number = obj.appointment_number;
		}	
		
		//destructor .. ~class name()
		~covid_patient(){
		
			cout<<"object destroyed\n";
		}	
		
		// member function to set and display data ;
		
		void set_data(){
			fflush(stdin);
			cout << "enter the name\n";
			getline(cin , this->name);
			fflush(stdin);
			cout << "enter the symptomes\n";
			getline(cin , this->symptoms);
			fflush(stdin);
			cout << "enter the hospital name\n";
			getline(cin , hospital_name);
			fflush(stdin);
			cout << "enter the data of birth in format dd-mm-yyyy\n";
			getline(cin , date_of_birth);
			fflush(stdin);
			cout << "enter the blood group\n";
			getline(cin , blood_group);
			fflush(stdin);
			cout << "enter the address\n";
			getline(cin , address);
			fflush(stdin);
			cout << "enter the phone number\n";
			cin >> number ;
			fflush(stdin);
			cout << "enter the adhar_card_no\n";
			cin >> adhar_card_no ;
			
		} 
		
		void get_data(){
			cout << "Name of the patient :- ";
			cout << this->name << endl;
			cout << "Appointment number :- ";
			cout << this->appointment_number;
			cout << "Symptoms :- " << endl;
			cout << symptoms << endl;
			cout << "Hospital name :- ";
			cout << hospital_name << endl;
			cout << "Date of birth :- ";
			cout << date_of_birth << endl;
			cout << "blood group :- ";
			cout <<blood_group << endl;
			cout << "Contact address :- ";
			cout << address << endl;
			cout << "Mobile number :- ";
			cout << number << endl;
			cout << "\nAadhar card number :- ";
			cout << adhar_card_no << endl;		
			
			
		}
		
		
		A static member function can be called even if no objects of the class exist and the static functions are accessed using 			only the class name and the scope resolution operator ::. 
		A static member function can only access static data member, other static member functions and any other functions from 			outside the class. 
		
		static void condition(){
			
			if(count < 100)
				cout << "critical condition" <<endl;
			
			else 
				cout << "not so critical condtition" <<endl;
		}
		
		friend class covid_patient2 ;
		// friend class can access private and protectes members of the class in which it is declared as the friend;


};


class covid_patient2 {

	// create an inline function .
	/*for small, commonly-used functions, the time needed to make the function call is often a lot more than the time needed to 	   actually execute the function’s code. This overhead occurs for small functions because execution time of small function is less 	  than the switching time.
	  Inline function is a function that is expanded in line when it is called. When the inline function is called whole code of the 		  inline function gets inserted or substituted at the point of inline function call. This substitution is performed by the C++ 		  compiler at compile time. Inline function may increase efficiency if it is small.
	
	public :
		inline void patient_count(){
			
			cout << "current number of patiens is : " << covid_patient :: count << endl;
		}
};


int covid_patient :: count = 0 ;		// dont need to put static keyword while defining ;

int main(){
	
	list <covid_patient> db ;
	covid_patient c("shreyas" , 200);
	cout << "Menu for the database : "<<endl;
	cout << "1. To insert patient record" <<endl;
	cout << "2. To delete patient record" <<endl;
	cout << "3. To view entire database" << endl;
	cout << "4. To modify a particular record" << endl;
	cout << "5. To list the total number of record entries count" << endl;
	cout << "6. To know the condition of covid" << endl;
	int choice, appno;
	while(1){
		cout << "\nEnter a choice : ";
		cin >> choice;
		switch (choice){
			case 1:
				
				c.set_data();
				db.push_back(c);
				break;
			case 2:
				cout<<"Enter the appointment number to be deleted : ";
				cin >> appno;
				delete_patient(&L,appno);
				break;
			case 3:
				cout << "The record is as follows : " << endl;
				for(auto i : db){
					i.get_data();
				}
			
			/*	break;
			case 4:
				cout << "Enter the appointment number of the record to be modified : "<<endl;
				cin >>appno;
				reach_list(L,appno);
				break;
			case 5:
				b.display_count();
				break;			
			case 6:
				covid_patient::condition();
				break;
		}
	
	
	}
	
	return 0;
}





*/







