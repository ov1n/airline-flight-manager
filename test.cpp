#include<iostream>
#include <fstream>
#include <string.h>
#define n 100

using namespace std;

void get_flightdata();
void get_pointer();										//get data by iterating struct pointer

class flight{
	
	private:
		
		int index;										//to keep of track of flights
		struct flights{									//struct containing the flight data
			
			char flightno[6];
			char dep_date_time[17];
			char dep_airport[21];
			char arr_airport[21];
			char row_no[60][n];						//sub 2d array with seat data
			
		}flight_details[n];
	
	public:
		flight();
		//setters
		void new_flight();									//create new flight
		void display_available();							//option 1
		void view_flight();									//option 2
		void seat_availability();							//option 3
		void seat_booking();								//option 4
		
		//utilities
		string get_class(string s,string checker);			//To check whether economy class or business
		string get_row(string s,string checker);
		string del_seat(string s,string checker,string seat);
		void exitp();										//exit
};

int main(){
	
	
	cout<<"1 Display available flights"<<endl<<"2 View flight"<<endl<<"3 Seat availability"<<endl<<"4 Seat booking"<<endl<<"5 Exit"<<endl;
	
	int choice;
	cin>>choice;					//get user's choice
	
	flight a ;
	//a.display_available();
	
	 switch(choice){
		
		case 1:
			a.display_available();
			break;
		
		case 2:
			a.view_flight();
			break;
			
		case 3:
			a.seat_availability();
			break;
			
		case 4:
			a.seat_booking();
			break;
		/*	
		case 5:
			exit();
			*/
		default:
			cout<<"lkkh"<<endl;
	} 
	
	return 0;
}

void get_flightdata(){
	
	// Create string, which is used to output the text file
	string query;

	// Read from the text file
	ifstream flight_data("Flights.txt");

	// Use a while loop together with the getline() function to read the file line by line
	while (getline (flight_data, query)) {
  	// Output the text from the file
  		int j=0;
  		if(query.compare("VA")){
  			cout <<j<< query<<"x "<< endl;
		  }
  		
  		j++;
  		
	}

	// Close the file
	flight_data.close();
	
}

flight::flight(){
	
	index=0;	
	//insert data into struct array
	//set 1
	strcpy(flight_details[index].flightno, "VA301");
	strcpy(flight_details[index].dep_date_time, "20/02/2020 10:20");
	strcpy(flight_details[index].dep_airport, "COLOMBO");
	strcpy(flight_details[index].arr_airport, "SINGAPORE");			//IMPORTANT
	strcpy(flight_details[index].row_no[0], "10 E AB");				//change to i
	strcpy(flight_details[index].row_no[1], "15 E CDE");
	strcpy(flight_details[index].row_no[2], "22 E ADF");
	strcpy(flight_details[index].row_no[3], "35 E CDE");
	strcpy(flight_details[index].row_no[4], "45 B CDE");
	
	//set 2 
	strcpy(flight_details[1].flightno, "VA305");
	strcpy(flight_details[1].dep_date_time, "15/02/2020 12:55");
	strcpy(flight_details[1].dep_airport, "COLOMBO");
	strcpy(flight_details[1].arr_airport, "GALLE");			//IMPORTANT
	strcpy(flight_details[1].row_no[0], "10 E AB"); 				//change to i
	/*strcpy(flight_details[index].row_no[1], "15 E CDE");
	strcpy(flight_details[index].row_no[2], "22 E ADF");
	strcpy(flight_details[index].row_no[3], "15 E CDE");
	strcpy(flight_details[index].row_no[4], "15 B CDE");*/
	
	//f2.row_no=""//
}

void flight::new_flight(){
	
	//flights *p=new flights;

	
}

string flight::get_class(string s,string checker){				//checker to know if Economy or Business
	
	string token;
	int pos = 0;
	int count=0;
	string delimiter = " ";
	if((pos=s.find(checker))!= string::npos){					//process to find whether economy class or business
		//cout<<"pos "<<pos<<endl;
		token = s.substr(0, pos);
		//cout<<"s first "<<s<<endl;
		//cout<<"token 1 "<<token<<endl;							//repeating for 3 times to get to 3rd line
		s.erase(0, pos + delimiter.length());
		//cout<<"s after 1 "<<s<<endl;
		token = s.substr(0, pos);
		//cout<<"token 2 "<<token<<endl;
		s.erase(0, pos );
		//cout<<"s after 2 "<<s<<endl;
		token = s;//.substr(0, pos);
		//cout<<"token 3 "<<token<<endl;
		
		//cout<<"token size "<<token.size()<<endl;
    }
	return token;

}

string flight::del_seat(string s,string checker,string seat){				//checker to know if Economy or Business
	
	string token;
	int pos = 0;
	int count=0;
	string delimiter = " ";
	string token_1;
	string token_2;
	string token_3;
	string new_token;
	if((pos=s.find(checker))!= string::npos){					//process to find whether economy class or business
		
		//The array data is split into 3 tokens for easy referencing
		token_1= s.substr(0, pos);
		//cout<<"s first "<<s<<endl;							//debugging
		s.erase(0, pos + delimiter.length());
		//cout<<"s after 1 "<<s<<endl;
		token_2= s.substr(0, pos);
		s.erase(0, pos );
		//cout<<"s after del" <<s<<endl;
		token_3= s.substr(0, pos);
		//cout<<"s after 2 "<<s<<endl;
		token = s;//.substr(0, pos);
		
		
		//cout<<"token size "<<token.size()<<endl;
    }
	int index=token.find(seat);
	token.erase(index,1);
	new_token=token_1+delimiter+token_2+token;
	
	return new_token;

}

string flight::get_row(string s,string checker){
	
	string token;
	int pos = 0;
	int count=0;
	string delimiter = " ";										//delimeter used to split
	if((pos=s.find(checker))!= string::npos){					//process to find whether economy class or business
		//cout<<"pos "<<pos<<endl;
		token = s.substr(0, pos);
	}
	
	return token;
	
}

void flight::display_available(){
	
	int available_flag=0;							//Flag to indicate if there are any flights available
	for(int i=0;i<100;i++){							//iterate through flight details ,100 is the maximum flight capacity
		
		if(strlen(flight_details[i].row_no[0])!= 0){	//the ones who dont have their character array empty will be printed
		
			cout<<endl<<"Flight number:\t"<<flight_details[i].flightno<<endl;					//have to format beautifully
			cout<<"Departure date and time:\t"<<flight_details[i].dep_date_time<<endl;
			cout<<"Departure airport:\t"<<flight_details[i].dep_airport<<endl;
			cout<<"Arriving airport:\t"<<flight_details[i].arr_airport<<endl;
			
			//getting the number of seats,number of economy and business respectively
			int j=0;
			int seats=0;
			int e=0;
			int b=0;
			int seat_info[3]={seats,e,b};
			int *info;
			while(strlen(flight_details[i].row_no[j])!= 0){
				
				string s=(flight_details[i].row_no[j]);					//convert each row to a string for string operations
				int temp_sum=0;											//temp variable to get value by function										
				
				//Get economy class
				string seat_name=get_class(s," E ");
				temp_sum=seat_name.size();
				seats+=temp_sum;
				e+=temp_sum;
				
				temp_sum=0;												//reset sum
				//Get business class
				seat_name=get_class(s," B ");
				temp_sum=seat_name.size();
				seats+=temp_sum;
				b+=temp_sum;
				 
				j++;	
			}
			cout<<"No of available Seats:\t"<<seats<<endl; 	//have to find a way to classify between classes
			cout<<"Business class=\t"<<b<<endl;
			cout<<"Economy class=\t"<<e<<endl;
		}else{
			break;			//if break isnt here program would run 100 times
		}
		
	}
}

void flight::view_flight(){
	
	string numb;
	cout<<"Enter flight number: "<<endl;
	cin>>numb;
	int i=0;
	int available=0	;										//flag to denote if its actually there,if available 1
	while(strlen(flight_details[i].flightno)!= 0){
		
		if(flight_details[i].flightno==numb){
			
			available=1;
			cout<<endl<<"Flight number:\t"<<flight_details[i].flightno<<endl;					//have to format beautifully
			cout<<"Departure date and time:\t"<<flight_details[i].dep_date_time<<endl;
			cout<<"Departure airport:\t"<<flight_details[i].dep_airport<<endl;
			cout<<"Arriving airport:\t"<<flight_details[i].arr_airport<<endl;
			cout<<"Available seats:"<<endl;
			
			int j=0;
			while(strlen(flight_details[i].row_no[j])!= 0){							//IMPROVE
				
				cout<<flight_details[i].row_no[j]<<endl;
				j++;
			}
			break;
		}
		i++;
	}
	
	if(available==0){
			
		cerr << "ERROR" << endl<<"Invalid flight number"<<endl;
	}
	
	
}

void flight::seat_availability(){
	
	string numb;
	cout<<"Enter flight number: "<<endl;
	cin>>numb;
	cout<<"Enter number of seats needed"<<endl;
	int no_seats;
	cin>>no_seats;
	
	int i=0;
	while(strlen(flight_details[i].flightno)!= 0){
		
		if(flight_details[i].flightno==numb){
			int seats;													//variable to hold number of seats
			int j=0;
			while(strlen(flight_details[i].row_no[j])!= 0 ){							//IMPROVE
				
				int temp_sum=0;
				string seat_name=get_class(flight_details[i].row_no[j]," E ");
				temp_sum=seat_name.size();				//use get class func to get no of seats
				seats+=temp_sum;
				
				temp_sum=0;												//reset sum
				//Get business class
				seat_name=get_class(flight_details[i].row_no[j]," B ");
				temp_sum=seat_name.size();
				seats+=temp_sum;
				j++;
			}
			if(no_seats>seats){
				
				cerr<<"Sorry...That much seats are unavailble"<<endl;
			}else{
				cout<<"Yes seats are available,following are the available seats for respective rows: "<<endl<<"|  Row no. |  Class  |  Seat nos.  |"<<endl;
				
				j=0;
				while(strlen(flight_details[i].row_no[j])!= 0 ){
					
					cout<<flight_details[i].row_no[j]<<endl;
					j++;
				}
				
			}
			
		}
		
		i++;
	}
	
}

void flight::seat_booking(){
	
	string numb;
	cout<<"Enter flight number: "<<endl;
	cin>>numb;
	
	string seat_class;
	cout<<"Enter class: (e for economy and b for business)"<<endl;
	cin>>seat_class;
	
	string row_numb;
	cout<<"Enter row number: "<<endl;
	cin>>row_numb;
	
	string seat_no;
	cout<<"Enter seat number: "<<endl;
	cin>>seat_no;
	
	int i=0;
	while(strlen(flight_details[i].flightno)!= 0){			//Iterator
		
		int flight_flag=0;
		if(flight_details[i].flightno==numb){				//Flight number check
			
			flight_flag=1;
			int j=0;
			while(strlen(flight_details[i].row_no[j])!= 0){
				
				cout<<"seat in full "<<flight_details[i].row_no[j]<<endl;
				int row_flag=0;								//flag to check if row is available
				
				string s;									//string used to store row number from object
				string checker;
				
				//classifying seperately for Economy class or Business
				if(seat_class=="e"){
					checker=" E ";
					s=get_row(flight_details[i].row_no[j],checker);
				}else if(seat_class=="b"){
					checker=" B ";
					s=get_row(flight_details[i].row_no[j],checker);
				}
				
				if(s==row_numb){
					row_flag=1;								//set row flag to 1 since row is available
					//cout<<"s in function"<<s<<endl;
					string new_order=del_seat(flight_details[i].row_no[j],checker,seat_no);
					
					char cstr[100]; //convert into char array
					strcpy(cstr, new_order.c_str());
					strcpy(flight_details[i].row_no[j],cstr);
					
					cout<<"Array data :"<<flight_details[i].row_no[j]<<endl;
					break;
				}
				j++;
			}
		}
		i++;
	}
	
	
}
