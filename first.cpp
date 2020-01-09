#include<iostream>
#include <fstream>
#include <string.h>
#define n 100

using namespace std;

void get_flightdata();
void get_pointer();				//get data by iterating struct pointer

class flight{
	
	private:
	struct flights{				//struct containing the flight data
		
		char flightno[6];
		char dep_date_time[17];
		char dep_airport[21];
		char arr_airport[21];
		char row_no[60][100];	//sub 2d array with seat data
		
	}f1;
	
	public:
		flight();
		//setters
		void new_flight();		//create new flight
		
};

int main(){
	
	
	cout<<"1 Display available flights"<<endl<<"2 View flight"<<endl<<"3 Seat availability"<<endl<<"4 Seat booking"<<endl<<"5 Exit"<<endl;
	
	int choice;
	cin>>choice;					//get user's choice
	
	flight a ;
	
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
	get_flightdata();				//function call to get input file data about the flights
	
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
	
	flights* f2=new flights();
	flights *p=f2;
	
	strcpy(p->flightno, "VA301");
	strcpy(f2->dep_date_time, "20/02/2020 10:20");
	strcpy(f2->dep_airport, "COLOMBO");
	strcpy(f2->arr_airport, "SINGAPORE");
	strcpy(f2->row_no[2], "15 E CDE");
	
	cout<<f2->row_no[2]<<endl;
	//f2.row_no=""//
}
