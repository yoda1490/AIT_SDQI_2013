#include "LogData.hpp"

using namespace std;

/* Phase Constructor */
Phase::Phase(std::string input_phase){
			// _phase =  input_phase;
}


/* Defect constructor */
Defect::Defect(){
	// return 0;
}


LogData::LogData(std::string iterationID, std::string phase ,std::string date, std::string workh, std::string worker_input , std::string defect_inject_input , std::string comment_input )
{

	cout << " Construct!!!"<< endl;
}

std::string getIteration(std::string it_input); //decalration
std::string ZeroPadNumber(int num);

int main() 
{

	std::string iterationID_string =  "0408";
	std::string phase_string = "t";
	std::string date_string = "9/4/2013";
	std::string enddate_string = "";
	std::string workinghour_string = "1";
	std::string worker_string = "job,faith";
	std::string defect_inject_string = "c";
	std::string defect_type_string = "20";
	std::string defect_input =  defect_type_string + defect_inject_string ; 
	std::string comment_string = "This code cannot be used for unit testing since there is no clear function (just only main) So, we choose to use minimal test for this testing. The error that we've found is in the pair list name. - The pair list name alwats begin with comma (',') - missing return 0;" ; //The comment_string , in reality there will be multiple lines.... we should handle this


	LogData logdata (iterationID_string, phase_string ,date_string , workinghour_string, worker_string , defect_input, comment_string );

	cout << ZeroPadNumber(2,2) <<endl; 
	return 0;
}

// -------- Iteration function ----------
string getIteration(string it_input)
{
	if(current_iteration.compare(it_input) == 0 )//same
	{
		iteration_counter++;
		return ZeroPadNumber(iteration_counter);
	}
}

string ZeroPadNumber(int num, int num_length)
{
	std::stringstream ss;
	// the number is converted to string with the help of stringstream
	ss << num; 
	string ret;
	ss >> ret;
	// Append zero chars
	int str_length = ret.length();
	for (int i = 0; i < num_length - str_length; i++)
		ret = "0" + ret;
	return ret;
}
/*
commit 4e70f9d551781496b81f8155dce09864ded97995
Merge: 3cc225b ecb61a5
Author: sakares <sakares@sakares-VirtualBox.(none)>
Date:   Thu Apr 11 17:55:17 2013 +0700

    Merge branch 'testing'

commit ecb61a5f87174cc5ca98b2e85c3c5f9a97667ec5
Author: sakares <sakares@sakares-VirtualBox.(none)>
Date:   Tue Apr 9 14:00:39 2013 +0700

    Perform minimal testing instead of unit testing
    @iterationID = 0408
    @phase = t
    @startdate = 9/4/2013
    @workinghour = 1
    @worker = job,faith
    @defect_inject = c
    @defect_type = 20 (Syntax)
    @comment = This code cannot be used for unit testing since there is no clear function (just only main)
    	   So, we choose to use minimal test for this testing. The error that we've found is in the pair list name.
               - The pair list name alwats begin with comma (",")
    	   - missing return 0;
*/