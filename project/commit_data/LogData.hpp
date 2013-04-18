#include <list>
#include <string>
#include <iostream>
#include <ctime>

using namespace std;

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
		LogData(std::string iterationID, std::string phase ,std::string date, std::string workh, std::string worker_input , std::string defect_inject_input , std::string comment_input   );
};
LogData(std::string iterationID, std::string phase ,std::string date, std::string workh, std::string worker_input , std::string defect_inject_input , std::string comment_input   );


/*****************************************************************
  Reuse instructions                                          
    Phase->PHASE_CODE , Phase->PHASE_TEST    
    Purpose: Phase Defect type         
    Limitations: -
    Return: PHASE VARIABLE
*****************************************************************/
class Phase{
	private:
		std::string PHASE_CODE = "C";
		std::string PHASE_TEST = "T";
		std::string _phase;
	public:
		Phase(std::string input_phase)
		{
			_phase =  input_phase;
		}

		getPhase()
		{
			return _phase;
		}
};


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
  	new Defect(Defect::Defect->DEFECT_ENVIRONMENT ,Phase::Phase->PHASE_CODE );                                          
    Purpose: Store the Defect type           
    Limitations: - t
    Return: A defect object 
*****************************************************************/
class Defect{
	private:
		int defect_type;
		Phase defect_phase;
	public:
		static const int DEFECT_ENVIRONMENT = 10;
		static const int DEFECT_SYNTAX = 20;
		static const int DEFECT_SERVER = 30;
		Defect(); //constructor
		assignDefect(); /*Assign the DEFECT token to this Defect*/
		getTokenType(); /*returning this defect token errors*/
};

/* Defect constructor */
Defect::Defect (int defect_type, std::string defect_phase){
	
}