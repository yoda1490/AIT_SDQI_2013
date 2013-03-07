#include <boost/tokenizer.hpp>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using namespace boost;
int main()
{
cout << " Pleast type the file name you want to count: \n";
	string a;
	getline(cin,a);
	ifstream r(a.c_str());
	string set;
while (getline(r,set)){

boost::char_separator<char> sep(" \t", "::");
tokenizer< char_separator<char> > tok(set, sep);
for ( tokenizer< char_separator<char> >::iterator beg = tok.begin();
beg != tok.end();
		++beg){	
	cout << *beg << endl;
}
}
}
