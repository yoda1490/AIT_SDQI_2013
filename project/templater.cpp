//Created by Amaury BOLLER on 08 april 2013
//A little piece of code that ask you some information needed to execute
// git command with good parameter for this project


#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h> // additional from sakares for 'atof' function
#include <stdio.h>

using namespace std;


int getIterationNumberMax();
int to_int(char const *s);
string perform(const char * command);

int main(int argc, char ** argv)
{




	string separator = " ";
	int i_n = getIterationNumberMax();
	cout << "Iteration Number: " << i_n << endl;
	

	string phase;
	while(phase != "c" && phase != "t"){
		if(phase.length() > 0)	cout << "Error: only 'c' or 't' is acceptable for this input" << endl;
		cout << "Enter Phase (c for codding or t for test): ";
		cin >> phase;
	}
	cout << endl;

	string working_hour_string;
	float working_hour = -1;
	while(working_hour <= 0){
		if(working_hour_string.length() > 0)	cout << "Error: only number accepter for this input" << endl;
		cout << "Enter real working hour: ";
		cin >> working_hour_string;
		working_hour = atof(working_hour_string.c_str());
	}
	cout << endl;

	vector<string> listUser;
	string lastUser;
	int cpt=1;
	cout << "Enter all worker (Enter empty line to finish)" << endl;

	cin.clear();
	while (getline( cin, lastUser ) && (lastUser.length()>0  || listUser.size()<1)){
		cout << "Worker "<<cpt<<": ";
		istringstream ss( lastUser );
		listUser.push_back(lastUser);
		cpt++;
	}

	cout << "Start date" << endl;

	cin.clear();
	string startDayString;
	int startDay = -1;
	while(startDay < 0){
		if(startDayString.length() > 0)	cout << "Error: only number accepter for this input" << endl;
		cout << "Day: ";
		cin >> startDayString;
		startDay = to_int(startDayString.c_str());
	}
	cin.clear();
	string startMonthString;
	int startMonth = -1;
	while(startMonth < 0){
		if(startMonthString.length() > 0)	cout << "Error: only number accepter for this input" << endl;
		cout << "Month: ";
		cin >> startMonthString;
		startMonth = to_int(startMonthString.c_str());
	}
	cin.clear();
	string startYearString;
	int startYear = -1;
	while(startYear < 0){
		if(startYearString.length() > 0)	cout << "Error: only number accepter for this input" << endl;
		cout << "Year: ";
		cin >> startYearString;
		startYear = to_int(startYearString.c_str());
	}
	cin.clear();
	string defInj;
	while(defInj != "c" && defInj != "t"){
		if(defInj.length() > 0)	cout << "Error: only 'c' or 't' is acceptable for this input" << endl;
		cout << "Enter defect phase injected (c for codding or t for test): ";
		cin >> defInj;
	}
	cout << endl;
	
	cin.clear();
	string defTypeString;
	float defType = -1;
	while(defType < 0){
		if(defTypeString.length() > 0)	cout << "Error: only number accepter for this input" << endl;
		cout << "Enter defect type: ";
		cin >> defTypeString;
		defType = atof(defTypeString.c_str());
	}
	cout << endl;

    cin.clear();
	string comment;
	cout << "Enter a comment: ";
	while(comment.length() < 1)
        getline(cin, comment);


	cout << endl;


	std::ostringstream oss;

	oss << "@iterationID=" << i_n << "\n@phase=" << phase <<  "\n@workingHour=" << working_hour << "\n@worker=";
	for(int i=0; i<listUser.size();i++){
			oss << listUser.at(i); 
		if(i>0 && i<listUser.size()-1)
			oss << ",";
	}

	oss << "\n@startdate=" << startDay << "/" << startMonth << "/" << startYear;

	oss << "\n@defect_inject=" << defInj << "\n@defect_type=" << defType << "\n@comment=" << comment;

	cout << oss.str() << endl;


	cout << separator << endl;
	//system(git commit )

	cout << "commit ?" << endl;
	string commit;
	while(commit != "yes" && commit != "no"){
		if(phase.length() > 0)	cout << "Error: only 'yes' or 'no' is acceptable for this input" << endl;
		cin >> commit;
	}

	
	if(commit == "yes"){
		string output = "git commit -a -m \"" + oss.str() + "\"";
		const char * op = output.c_str();
		cout << perform(op) << endl;
	}


	cout << endl;

}

string perform(const char * command){

	cout << command << endl;
	FILE* pipe = popen(command, "r");
    if (!pipe){
    	return "Error while commiting";
    } 
    char buffer[128];
    std::string result = "";
    while(!feof(pipe)) {
    	if(fgets(buffer, 128, pipe) != NULL)
    		result += buffer;
    }
    pclose(pipe);
    
	return result;
}

int getIterationNumberMax(){
	FILE *pipe = popen("git pull && git log | grep @iterationID | sed -e 's_.*@iterationID *= *\\([^ \\n]*\\)_\\1_'", "r");
	if (!pipe){
    	cout << "Error while commiting";
    } 
    char buffer[128];
    std::string result = "";

    int i=0;
    while(!feof(pipe) && i==0) {
    	if(fgets(buffer, 128, pipe) != NULL){
    		result = buffer;
    		i = to_int(result.substr(0, result.size()-1).c_str());
    	}
    }
    pclose(pipe);

	return i+1;
}


int to_int(char const *s)
{
     if ( s == NULL || s[0] == '\0' )
     {
        return 0;
     }
     bool negate = (s[0] == '-');
     if ( *s == '+' || *s == '-' ) 
          ++s;
     int result = 0;
     while(*s)
     {
          if ( *s >= '0' && *s <= '9' )
          {
              result = result * 10  - (*s - '0');  //assume negative number
          }
          else
              return 0;
          ++s;
     }
     return negate ? result : -result; //-result is positive!
} 
