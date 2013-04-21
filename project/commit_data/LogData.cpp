#include "LogData.hpp"


/* Defect constructor */
Defect::Defect(){
	// return 0;
}



// -------- Log data function ----------
string LogData::ZeroPadNumber(int num, int num_length)
{
	stringstream ss;
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
string LogData::generateIteration(string it_input)
{
	string output = it_input;
	if(current_iteration2.compare(it_input) == 0 )//same
	{
		iteration_counter2++;
		output =  output.append( LogData::ZeroPadNumber(iteration_counter2,2));
	}
	else
	{
		current_iteration2 = it_input;
		iteration_counter2 = 1;
		output =  output.append( LogData::ZeroPadNumber(iteration_counter2,2));
	}
	return output;
}

string LogData::getIteration()
{
	return this->_iteration_id;
}

//------- Phase ----------
string LogData::getPhase()
{
	return this->_phase;
}
//------- Working hour ----------
float LogData::getWorkingHour()
{
	return this->_working_hour;
}
//------- Worker -----------
Worker::Worker(string input_string)
{
	boost::split(_workers,input_string,boost::is_any_of(","),boost::token_compress_on);
	// _workers = split(input_string , ',');
}
int Worker::getTotalWorker()
{
	return _workers.size();
}

vector<string> Worker::getWorkerList()
{
	return _workers;
}

void Worker::printWorker()
{
	 for(int i =0 ; i < _workers.size(); i++)
	 	cout << "worker :" << _workers[i] <<endl;
}
//------- Defect -----------


//------- Comment -----------
string LogData::getComment()
{
	return this->_comment;
}

LogData::LogData(string iterationID, string phase ,string date, string workh, string worker_input , string defect_inject_input , string comment_input ): _worker_pair(worker_input)
{

	//_worker_pair = new Worker(worker_input);

	iteration_counter2 =0; //Count each iteration and then add them up
    current_iteration2 = ""; //track the current iteration.
    
	_iteration_id  = generateIteration(iterationID);
	_phase =  phase;
	
	// TIME --- _start_date
	const char* workh_buffer ;
	workh_buffer = workh.c_str();
	_working_hour = atof(workh_buffer);

	// cout << temp_worker.getTotalWorker << endl;

	_comment = comment_input;

}


// ---------- Common Declaration--------------

int main() 
{

	string iterationID_string =  "0408";
	string phase_string = "t";
	string date_string = "9/4/2013";
	string enddate_string = "Tue Apr 9 14:00:39 2013 +0700";
	string workinghour_string = "1";
	string worker_string = "job,faith";
	string defect_inject_string = "c";
	string defect_type_string = "20";
	string defect_input =  defect_type_string + defect_inject_string ; 
	string comment_string = "This code cannot be used for unit testing since there is no clear function (just only main) So, we choose to use minimal test for this testing. The error that we've found is in the pair list name. - The pair list name alwats begin with comma (',') - missing return 0;" ; //The comment_string , in reality there will be multiple lines.... we should handle this
	list<LogData> temp_list ;

	LogData logdata (iterationID_string, phase_string ,date_string , workinghour_string, worker_string , defect_input, comment_string );


	
	cout << logdata.getIteration() << endl;
	cout << logdata.getPhase() << endl;
	cout << logdata.getWorkingHour() << endl;
	cout << logdata.getComment() << endl;
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
