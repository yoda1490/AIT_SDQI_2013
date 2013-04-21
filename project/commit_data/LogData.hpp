#include <list>
#include <vector>

// #include <stdlib>

#include <string>
#include <sstream>
#include <iostream>
#include <ctime>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp> 


using namespace std;

/*****************************************************************
  Reuse instructions
  	Worker("nk , faith , job")                                          
    Purpose: Linked List of workers, this should automatically add to global variables worker_list
    Limitations: -
    Return: A worker object
*****************************************************************/
class Worker{
	private:
		vector<string> _workers;
	public:
		Worker(string); //constructor
		int getTotalWorker(); //return number of workers
		vector <string> getWorkerList();
		void printWorker();
};

/*****************************************************************
  Reuse instructions
  	new Defect(Defect::Defect->DEFECT_ENVIRONMENT ,Phase::Phase->PHASE_CODE );                                          
    Purpose: Store the Defect type           
    Limitations: - t
    Return: A defect object 
*****************************************************************/
class Defect{
	private:
		int defect_type;
		// Phase defect_phase;
	public:
		Defect(); //constructor

		static const int DEFECT_ENVIRONMENT = 10;
		static const int DEFECT_SYNTAX = 20;
		static const int DEFECT_SERVER = 30;
		
		void assignDefect(); /*Assign the DEFECT token to this Defect*/
		 // getTokenType(); /*returning this defect token errors*/
};

 // current date/time based on current system
 //   time_t now = time(0);

 //   cout << "Number of sec since January 1,1970:" << now << endl;

 //   tm *ltm = localtime(&now);

 //   // print various components of tm structure.
 //   cout << "Year: "<< 1900 + ltm->tm_year << endl;
 //   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
 //   cout << "Day: "<<  ltm->tm_mday << endl;
 //   cout << "Time: "<< 1 + ltm->tm_hour << ":";
 //   cout << 1 + ltm->tm_min << ":";
 //   cout << 1 + ltm->tm_sec << endl;

/*****************************************************************
  Reuse instructions                                          
    Phase->PHASE_CODE , Phase->PHASE_TEST    
    Purpose: Phase Defect type         
    Limitations: -
    Return: PHASE VARIABLE
*****************************************************************/
class LogData{
	protected:
		string _iteration_id;
		string _phase;
		string _start_date;
		float _working_hour;
		Worker  _worker_pair;  /* Worker class */
		Defect _defect;
		string _comment; //the comment data type
	public:

        static int iteration_counter2 ; //Count each iteration and then add them up
        static string current_iteration2 ; //track the current iteration.
        

		LogData(string iterationID, string phase ,string date, string workh, string worker_input , string defect_inject_input , string comment_input );

		//---- Iteration ------
		string generateIteration(string );
		string getIteration();
		string ZeroPadNumber(int ,int);
		//---- Phase String ----
		string getPhase();
		//---- Date ----
		string getdate();
		//---- Working hour -----
		float getWorkingHour();
		//---- worker -----

		//---- Defect -----

		//---- Comment -----
		string getComment();
};



