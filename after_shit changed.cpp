#include<iostream>
#include <fstream>
#include <string.h>
#define n 100

using namespace std;

void get_flightdata();

class flight{
	
	private:
			
		char flightno[6];
		char dep_date_time[17];
		char dep_airport[21];
		char arr_airport[21];
		char row_no[60][n];						
	
	public:
		flight();
		void display_available();							//option 1
		void view_flight();									//option 2
		void seat_availability();							//option 3
		void seat_booking();								//option 4
		void write_data();									//option 5
		
		//utilities
		string get_class(string s,string checker);			//To check whether economy class or business
		string get_row(string s,string checker);
		string del_seat(string s,string checker,string seat);
		void exitp();										//exit
};

int main(){
	
	
	cout<<endl<<"1 Display available flights"<<endl<<"2 View flight"<<endl<<"3 Seat availability"<<endl<<"4 Seat booking"<<endl<<"5 Exit"<<endl<<endl;
	
	int choice;
	cin>>choice;					//get user's choice
	
	flight a ;
	while(choice!=5){		
		//a.display_available();
		switch(choice){
			
			case 1:
				display_available();
				break;
			
			case 2:
				view_flight();
				break;
				
			case 3:
				seat_availability();
				break;
				
			case 4:
				seat_booking();
				//cout<<"Array data after:"<<a.flight_details[0].row_no[0]<<endl;
				break;
			/*	
			case 5:
				exit();
				*/
			default:
				cout<<"Wrong output"<<endl;
				break;
		} 
		cout<<endl<<"1 Display available flights"<<endl<<"2 View flight"<<endl<<"3 Seat availability"<<endl<<"4 Seat booking"<<endl<<"5 Exit"<<endl<<endl;
		cin>>choice;
	}
	
	
	return 0;
}

void get_flightdata(){
	index=0;	
	//insert data into struct array
	//set 1
	strcpy(flight_details[index].flightno, "VA301");
	strcpy(flight_details[index].dep_date_time, "20/02/2020 10:20");
	strcpy(flight_details[index].dep_airport, "COLOMBO");
	strcpy(flight_details[index].arr_airport, "SINGAPORE");			//IMPORTANT
	strcpy(flight_details[index].row_no[0], "10 E A");				//change to i
	strcpy(flight_details[index].row_no[1], "16 E CDE");
	strcpy(flight_details[index].row_no[2], "22 E ADF");
	strcpy(flight_details[index].row_no[3], "35 E CDE");
	strcpy(flight_details[index].row_no[4], "45 B CDE");
	
	//set 2 
	strcpy(flight_details[1].flightno, "VA305");
	strcpy(flight_details[1].dep_date_time, "15/02/2020 12:55");
	strcpy(flight_details[1].dep_airport, "COLOMBO");
	strcpy(flight_details[1].arr_airport, "GALLE");			//IMPORTANT
	strcpy(flight_details[1].row_no[0], "10 E AB"); 				//change to i
	strcpy(flight_details[1].row_no[1], "15 E CDE");
	strcpy(flight_details[1].row_no[2], "22 E ADF");
	strcpy(flight_details[1].row_no[3], "15 E CDE");
	strcpy(flight_details[1].row_no[4], "15 B CDE");/* */
	
}
