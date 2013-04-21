#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include <ctime>



/*****************************************************************
  Reuse instructions                                          
    Purpose: Worker
    Limitations: -
    Return: A worker object
*****************************************************************/
class Worker{
	private:
		std::list<std::string> workers;
	public:
		
};

/*****************************************************************
  Reuse instructions                                          
    Phase->PHASE_CODE , Phase->PHASE_TEST    
    Purpose: Phase Defect type         
    Limitations: -
    Return: PHASE VARIABLE
*****************************************************************/
class Phase{
	private:
		static const std::string PHASE_CODE;
		static const std::string PHASE_TEST;
		std::string _phase;
	public:
		Phase(std::string );

		std::string getPhase(){
			return _phase;
		}

		void setPhase(){

		}
};
const std::string Phase::PHASE_CODE = "c";
const std::string Phase::PHASE_TEST = "t";


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
		std::string iteration_id;
		std::string phase;
		std::string start_date;
		float working_hour;
		Worker worker_pair;  /* Worker class */
		Defect defect;
		std::string comment; //the comment data type
	public:
		LogData(std::string , std::string  ,std::string , std::string , std::string  , std::string  , std::string );
};


int iteration_counter =0; //Count each iteration and then add them up
std::string current_iteration = ""; //track the current iteration.

