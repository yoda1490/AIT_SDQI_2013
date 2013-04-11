//Created by Amaury BOLLER on 08 april 2013
//A little piece of code that ask you some information needed to execute
// git command with good parameter for this project

#include <boost/test/minimal.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <stdlib.h> // additional from sakares for 'atof' function

using namespace std;

template <typename T>
string Str( const T & t ) {
	ostringstream os;
	os << t;
	return os.str();
}

int test_main(int , char *[])
{
	string separator = " ";
	//todo --> detected iteration number
	int i_n = 1;
	cout << "Iteration Number: " << i_n << endl;
	

	string phase;

	while(phase != "c" && phase != "t"){
		if(phase.length() > 0)	cout << "Error: only 'c' or 't' is acceptable for this input" << endl;
		cout << "Enter Phase (c for codding or t for test): ";
		//cin >> phase;
		phase = "t";
	}

	
	
	cout << endl;

	string working_hour_string;
	float working_hour = -1;
	while(working_hour <= 0){
		if(phase.length() > 0)	cout << "Error: only number accepter for this input" << endl;
		cout << "Enter real working hour: ";
		//cin >> working_hour_string;
      		working_hour_string = "10";
		working_hour = atof(working_hour_string.c_str());
	}
	
	cout << endl;
	
	vector<string> listUser;
	string lastUser;
	int cpt=1;
	cout << "Enter all worker (Enter empty line to finish)" << endl;

	cin.clear();
	/*while (getline( cin, lastUser ) && (lastUser.length()>0  || listUser.size()<1)){
		cout << "Worker "<<cpt<<": ";
		istringstream ss( lastUser );
		listUser.push_back(lastUser);
		cpt++;
	}*/
	listUser.push_back("job");
	listUser.push_back("faith");
	


	if ( i_n != 1)
	{
		BOOST_ERROR("wrong i_n");
	}
	cout << endl;
	if (phase != "t")
	{
		BOOST_ERROR("wrong phrase");
	}
	cout << endl;
	if (working_hour != 10)
	{
		BOOST_ERROR("wrong hour");
	}
	cout << endl;	
	
	string test_pair_name = "";
	
	for(int i=0; i<listUser.size();i++){
		test_pair_name += listUser.at(i); 
		if(i<listUser.size()-1)
			test_pair_name += ",";
	}

        cout << "Expected Listuser size = " << listUser.size() << endl;	
	cout << "Expected test_pair_name = " << test_pair_name << endl;
	if(test_pair_name != ",job,faith")
	{
		BOOST_ERROR("wrong number of pair");
	}
		

	cout << endl;
	return 0;
	//system(git commit )

}
