#include <iostream>
#include "Countln.hpp"
#include <fstream>
#include <string>
using namespace std;

int main(){
	countln cln2;
	cout << " Pleast type the file name you want to count: \n";
	string a;
	getline(cin,a);
	ifstream r(a.c_str());
	string set;
	node *temp = NULL;
	node *n;
        while (getline(r,set)){
	//	cout << set << endl;
		if (set!=""){
			//cout << "set is : " << set << "\n";
			if (cln2.ccomment(set) == true){
			//	cout << "\tif (cln2.ccomment(set) == true)" << "\n";
			}
			else{
				cln2.cclass(set);

			}
		}
		//cout << cln2.getnumline();
	}
	//cout << "ok" << endl;
	n = cln2.getstart_ptr();
	cout << "\n\n\n";
	while (n){
		cout << "class : " << n->name  << endl;
		cout << "\t  number of line is " << n->num << endl;
		n=n->next;
	}
	cout << "\n\n\nTotal number of line is : " << cln2.getnumline();
	cout << "\n\n\n";
	return 0;
}
