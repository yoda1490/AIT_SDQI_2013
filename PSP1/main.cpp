#include "find.hpp"
#include <iostream>
using namespace std;

int main(){
	finds fs;
	cout << "Please enter the amount of number to be input: " << endl;
	int m;
	cin >> m;
	fs.setmax(m);
	fs.createnode();
	fs.calculate();
	cout << "B0: " << fs.getB0() << "      B1: " << fs.getB1() << "      yk: " << fs.getyk() <<endl;
}
