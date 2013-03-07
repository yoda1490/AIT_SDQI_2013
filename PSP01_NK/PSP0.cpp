//============================================================================
// Name        : PSP0.cpp
// Author      : Nuttapon Kongkitimanon
// Version     :
// Copyright   : Your copyright notice
// Description : PSP0 Mean-STD-calculation
//============================================================================
#include <stdlib.h>
#include <iostream>
#include <list> //Spend a lot of time study and use the STL link-list
#include <sstream> //read file
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

float calculate_mean (list<float> inp);
float calculate_std(list<float> inp , float mean);

int main(int argc, char *argv[]) {

	char temp[255];
	char fname[255] = "input1.txt";

	getcwd(temp, 255) ;
	//cout <<temp <<endl;
	//cout <<fname <<endl;
	strcat (temp, "/" );
	strcat (temp , fname);

	//cout <<temp <<endl;
	std::ifstream infile;
	infile.open(temp);
	if (infile.fail())
	{
		cout << "Error opening file input.\n";
		return 1;
	}

	std::string line;
	std::list<float> listOffloats;

	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		float temp;
		if (!(iss >> temp)) {  break; } // error

		listOffloats.push_back(temp);
		// process pair (a,b)
	}
	float mean_calc = calculate_mean(listOffloats);
	cout << "mean : " << mean_calc <<endl;
	cout << "standard derivation :" << calculate_std(listOffloats,mean_calc) << endl;
/*
	list<float>::iterator i;
	for(i=listOffloats.begin(); i != listOffloats.end() ; ++i)
	{
		cout << *i << endl;
	}*/


	char *pFilename = argv[1];
	cout << pFilename;

	return 0;
}

float calculate_mean(list<float> inp){
	float temp_mean;

	list<float>::iterator i;
	for(i=inp.begin(); i != inp.end() ; ++i)
	{
		temp_mean += *i;
	}
	return temp_mean/inp.size();
}
float calculate_std(list<float> inp,float input_mean){

	list<float>::iterator i;
	float total_mean = 0;

	for(i=inp.begin(); i != inp.end() ; ++i)
	{
		total_mean += pow( (*i - input_mean ) ,2);
	}
	return sqrt(total_mean/(inp.size()-1));
}
