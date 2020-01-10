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
			char row_no[60][100];						//sub 2d array with seat data
			
		}flight_details[100];
	
	public:
		flight();
		//setters
		void new_flight();								//create new flight
		void display_available();						//option 1
		char view_flight(char numb);					//option 2
		char seat_availability(char numb);				//option 3
		char seat_booking(char fno,char seat);			//option 4
		void exitp();									//exit
};

int main(){
	
	
	cout<<"1 Display available flights"<<endl<<"2 View flight"<<endl<<"3 Seat availability"<<endl<<"4 Seat booking"<<endl<<"5 Exit"<<endl;
	
	int choice;
	cin>>choice;					//get user's choice
	
	flight a ;
	a.display_available();
	
	/* switch(choice){
		
		case 1:
			display_available();
		
		case 2:
			view_flight();
			
		case 3:
			seat_availability();
			
		case 4:
			seat_booking();
			
		case 5:
			exit();
	} */
	//get_flightdata();				//function call to get input file data about the flights
	
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
	flights* f2=new flights();
	flights *p=f2;
	
	//insert data into struct array
	//set 1
	strcpy(flight_details[index].flightno, "VA301");
	strcpy(flight_details[index].dep_date_time, "20/02/2020 10:20");
	strcpy(flight_details[index].dep_airport, "COLOMBO");
	strcpy(flight_details[index].arr_airport, "SINGAPORE");			//IMPORTANT
	strcpy(flight_details[index].row_no[0], "10 E AB");				//change to i
	strcpy(flight_details[index].row_no[1], "15 E CDE");
	strcpy(flight_details[index].row_no[2], "22 E ADF");
	strcpy(flight_details[index].row_no[3], "15 E CDE");
	strcpy(flight_details[index].row_no[4], "15 B CDE");
	
	//set 2
	strcpy(flight_details[1].flightno, "VA305");
	strcpy(flight_details[1].dep_date_time, "15/02/2020 12:55");
	strcpy(flight_details[1].dep_airport, "COLOMBO");
	strcpy(flight_details[1].arr_airport, "GALLE");			//IMPORTANT
	strcpy(flight_details[1].row_no[0], "10 E AB");				//change to i
	/*strcpy(flight_details[index].row_no[1], "15 E CDE");
	strcpy(flight_details[index].row_no[2], "22 E ADF");
	strcpy(flight_details[index].row_no[3], "15 E CDE");
	strcpy(flight_details[index].row_no[4], "15 B CDE");*/
	
	cout<<flight_details[index].row_no[1]<<endl;
	//f2.row_no=""//
}

void flight::new_flight(){
	
	//flights *p=new flights;

	
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
			while(strlen(flight_details[i].row_no[j])!= 0){
				
				std::string s=(flight_details[i].row_no[j]);		//convert each row to a string for string operations
				std::string delimiter = " ";
				size_t pos = 0;
				std::string token;										//declare token
				if((pos=s.find(" E "))!= string::npos){					//process to find whether economy class or business
				
    				token = s.substr(0, pos);							//repeating for 3 times to get to 3rd line
    				s.erase(0, pos + delimiter.length());
    				token = s.substr(0, pos);
    				s.erase(0, pos + delimiter.length());
    				token = s.substr(0, pos);
    				
    				for (int i = 0; i <= token.size(); i++){
    					e++;
    					seats++;
    					cout<<"e";
					}
    					
				}else
				if((pos=s.find(" B "))!= string::npos){
					token = s.substr(0, pos);							//repeating for 3 times to get to 3rd line
    				s.erase(0, pos + delimiter.length());
    				token = s.substr(0, pos);
    				s.erase(0, pos + delimiter.length());
    				token = s.substr(0, pos);
    				
    				for (int i = 0; i <= token.size(); i++){
    					b++;
    					seats++;
					}
				}
				cout<<"B=\t"<<b<<endl;
				j++;	
			}
			cout<<"No of available Seats:\t"<<seats<<endl; 	//have to find a way to classify between classes
			cout<<"Business class=\t"<<b<<endl;
			cout<<"Economy class=\t"<<e<<endl;
		}
		
	}
}
