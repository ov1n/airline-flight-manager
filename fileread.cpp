#include<iostream>
#include<fstream>
#include<vector>
#include <string.h>

#define n 100						//number of rows in airplane ASSUMING MAX ROWS ARE 100

using namespace std;

class flight{
	
	private:
		//necessary data	
		string flightno;
		string dep_date_time;
		string dep_airport;
		string arr_airport;
		string row_no[n];			//2d array to keep record of seats
		
		int row_index;			//the index of row which is available						
	
	public:
		flight();
		
		//getters
		string get_flightno(){return flightno;}
		string get_dep_date_time(){return dep_date_time;}
		string get_dep_airport(){return dep_airport;}
		string get_row(int index){return row_no[index];}
		string get_arr_airport(){return arr_airport;}	
		
		//setters						
		void set_flightno(string c){flightno=c;}				
		void set_dep_date_time(string c){dep_date_time=c;}								
		void set_dep_airport(string c){dep_airport=c;}									
		void set_arr_airport(string c){arr_airport=c;}
		void set_rows(string c);						//returns int of index									
		
		//utilities
		bool is_empty();										//checks whether any rows are there
		void display_count(flight*);
		string get_class(string s,string checker);			//To check whether economy class or business
		string del_seat(string s,string checker,string seat);
		void exitp();										//exit
};

//Dynamic array containing the flights
vector<flight> list;				
void get_flightdata();			//Functon to get flight data from file
void display_available();		//Function to display available flights

int main(){
	
	get_flightdata();
	
	//Driver program:
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
			/*
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
	
	flight *fptr;
	string myText;

	// Read from the text file
	ifstream MyReadFile("Flights.txt");
	//flags for loop
	int firstobjFlag=0;
	int flightnoFlag=0;
	int dep_date_timeFlag=0;
	int arr_airportFlag=0;
	int dep_airportFlag=0;
	int row_index=0;					//index of row to be inserted
	
	// Use a while loop together with the  getline() function to read the file line by line
	//fptr = new flight;
	while ((getline (MyReadFile, myText))){
	  	
	  	if(firstobjFlag==0){							//If its the 1st object
	  		fptr = new flight;
	  		cout<<"started"<<endl;
	  		firstobjFlag=1;
	  		
		}else if(myText==""){
			cout<<"space observed"<<endl;
			list.push_back(*fptr);
			flightnoFlag=0;
			dep_date_timeFlag=0;
			arr_airportFlag=0;
			dep_airportFlag=0;
			fptr = new flight;
			continue;
		}
		
	  	if(fptr->get_flightno().length()==0){		//if the flight number is not there		
	  		
	  		flightnoFlag=1;
	  		cout<<"Flight number is "<<myText<<endl;
	  		fptr->set_flightno(myText);
		}else
		if(fptr->get_dep_date_time().length()==0){		//Place dep date and time
	  		
	  		dep_date_timeFlag=1;
	  		cout<<"Date time is "<<myText<<endl;
	  		fptr->set_dep_date_time(myText);
	  	}else
		if(fptr->get_dep_airport().length()==0){		//place dep airport
	  		
	  		dep_airportFlag=1;
	  		cout<<"dep_ airport is "<<myText<<endl;
	  		fptr->set_dep_airport(myText);
	  	}else
		if(fptr->get_arr_airport().length()==0){		//place arr airport
	  		
	  		arr_airportFlag=1;
	  		cout<<"arar_ airport is "<<myText<<endl;
	  		fptr->set_arr_airport(myText);
	  	}else{
	  		int no_of_row;
	  		/*if(fptr->is_empty()){
	  			cout<<"blank"<<endl;					//???
			} */
			fptr->set_rows(myText);
			cout<<"row "<<myText<<endl;

	  	//cout<<myText<<endl;
	  	//list.push_back(*fptr);
	  	}
	  // Output the text from the file
	  //cout << myText<<endl;
	}
	// Close the file
	MyReadFile.close();
	
}

void display_available(){
	//flight fptr= list.begin();
	int available=0;				//counter to check no of flights that are available 
	
	for(int i=0;i<list.size();i++){
		if(list[i].is_empty()){
			
			continue;				//If the current flight has no seats goes to loop
		}else{
			
			available++;
			cout<<"Flight number: "<<list[i].get_flightno()<<endl;
			cout<<"Date and time: "<<list[i].get_dep_date_time()<<endl;
			cout<<"Departure airport: "<<list[i].get_dep_airport()<<endl;
			cout<<"Arrival airport: "<<list[i].get_arr_airport()<<endl;
		}
		cout<<endl;
	}
	
	if(available==0){
		cout<<"----Sorry no flights are available----"<<endl;
	}
}

flight::flight(){
	
	row_index=0;
	//cout<<"fdfdfd"<<endl;
}

void flight::set_rows(string c){
	row_no[row_index]=c;
	row_index++;
}

bool flight::is_empty(){  
	if(row_no[0].length()==0){
		return true;
	}
} 
