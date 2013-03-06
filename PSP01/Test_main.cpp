#include <iostream>
#include "Countln.hpp"
#include <fstream>
#include <string>
#include <boost/test/minimal.hpp>
using namespace std;
countln cln2;
int test_main( int, char *[] )  
{	
	cout << " Pleast type the file name you want to count: \n";
	string a;
	getline(cin,a);
	ifstream r(a.c_str());
	string set;
	while (getline(r,set)){
		if (set!=""){
			if (cln2.ccomment(set) == true){
			}
			else{
				cln2.cclass(set);

			}
			//ostringstream Converter;
			//Coverter << cln2.getnumline();
			char temp[50];
			sprintf(temp,"%d",cln2.getnumline());
			string a ="\n\n\nLine number ";
			a += temp;
			a += " has more than 1 excutation.\n\n\n";
			if (cln2.getmaxsemi()<cln2.getcsemi()){
				BOOST_ERROR(a.c_str());
			}
		}
	}
	if( cln2.getnumline() != 9){
		BOOST_ERROR("\n\n      Answer is not correct        \n\n");
	}
	return 0;
}
