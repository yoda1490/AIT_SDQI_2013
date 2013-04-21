#include "LogData.hpp"

using namespace std;

/* Defect constructor */
Defect::Defect(){
	// return 0;
}



// -------- Log data function ----------
std::string LogData::ZeroPadNumber(int num, int num_length)
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
std::string LogData::generateIteration(std::string it_input)
{
	string output = it_input;
	if(current_iteration.compare(it_input) == 0 )//same
	{
		iteration_counter++;
		output =  output.append( LogData::ZeroPadNumber(iteration_counter,2));
	}
	else
	{
		current_iteration = it_input;
		iteration_counter = 1;
		output =  output.append( LogData::ZeroPadNumber(iteration_counter,2));
	}
	return output;
}

std::string LogData::getIteration()
{
	return this->_iteration_id;
}

//------- Phase ----------
std::string LogData::getPhase()
{
	return this->_phase;
}
//------- Working hour ----------
float LogData::getWorkingHour()
{
	return this->_working_hour;
}
//------- Worker -----------

//------- Defect -----------


//------- Comment -----------
std::string LogData::getComment()
{
	return this->_comment;
}

LogData::LogData(std::string iterationID, std::string phase ,std::string date, std::string workh, std::string worker_input , std::string defect_inject_input , std::string comment_input )
{
	_iteration_id  = generateIteration(iterationID);
	_phase =  phase;
	// TIME --- _start_date
	const char* workh_buffer ;
	workh_buffer = workh.c_str();
	_working_hour = atof(workh_buffer);

	_comment = comment_input;

	cout << " Construct!!! "<< endl ;
	cout << " :"<<_iteration_id <<endl;
}


// ---------- Common Declaration--------------

int main() 
{

	std::string iterationID_string =  "0408";
	std::string phase_string = "t";
	std::string date_string = "9/4/2013";
	std::string enddate_string = "Tue Apr 9 14:00:39 2013 +0700";
	std::string workinghour_string = "1";
	std::string worker_string = "job,faith";
	std::string defect_inject_string = "c";
	std::string defect_type_string = "20";
	std::string defect_input =  defect_type_string + defect_inject_string ; 
	std::string comment_string = "This code cannot be used for unit testing since there is no clear function (just only main) So, we choose to use minimal test for this testing. The error that we've found is in the pair list name. - The pair list name alwats begin with comma (',') - missing return 0;" ; //The comment_string , in reality there will be multiple lines.... we should handle this
	list<LogData> temp_list ;

	LogData logdata (iterationID_string, phase_string ,date_string , workinghour_string, worker_string , defect_input, comment_string );


	cout << logdata.getWorkingHour() << endl;
	return 0;
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