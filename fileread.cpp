#include<iostream>
#include<fstream>
#include<vector>
#include <string.h>

using namespace std;

class flight{
	
	private:
			
		string flightno;
		string dep_date_time;
		string dep_airport;
		string arr_airport;
		string row_no[60];						
	
	public:
		flight();
		
		//getters
		string get_flightno(){return flightno;}
		string get_dep_date_time(){return dep_date_time;}
		string get_dep_airport(){return dep_airport;}
		//string get_rows(){return *row_no;}
		string get_arr_airport(){return arr_airport;}	
		
		//setters						
		void set_flightno(string c){flightno=c;}				
		void set_dep_date_time(string c){dep_date_time=c;}								
		void set_dep_airport(string c){dep_airport=c;}									
		void set_arr_airport(string c){arr_airport=c;}
		int set_rows(string c);						//returns int of index									
		
		//utilities
		string get_class(string s,string checker);			//To check whether economy class or business
		string get_row(string s,string checker);
		string del_seat(string s,string checker,string seat);
		void exitp();										//exit
};

vector<flight> list;				//Dynamic array containing the flights

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
	  		
	  		cout<<"blank"<<endl;
		}

	  	//cout<<myText<<endl;
	  	//list.push_back(*fptr);
	  }
	  // Output the text from the file
	  cout << myText;
	
	// Close the file
	MyReadFile.close();
	
}

int main(){
	
	get_flightdata();
	
	return 0;
}

flight::flight(){
	
}

int flight::set_rows(string c){
	
}
