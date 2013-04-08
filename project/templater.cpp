//Created by Amaury BOLLER on 08 april 2013
//A little piece of code that ask you some information needed to execute
// git command with good parameter for this project


#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char ** argv)
{
	string separator = " ";
	//todo --> detected iteration number
	int i_n = 0;
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
		if(phase.length() > 0)	cout << "Error: only number accepter for this input" << endl;
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


	cout << "@iterationID#" << i_n << separator << "@phase=" << phase << separator << "@workingHour=" << working_hour << separator << "@worker=";
	for(int i=0; i<listUser.size();i++){
		cout << listUser.at(i); 
		if(i<listUser.size()-1)
			cout << ",";
	}

	cout << separator << endl;
	//system(git commit )

}
