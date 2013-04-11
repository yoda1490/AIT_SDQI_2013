/******************************************************************/

/* Program Assignment:  PSP1                                        */

/* Name:                SDQI 2003 CLASS                             */

/* Date:                18 February 2013          */

/* Description:         Find Correlation and calculate LOC efficient*/

/******************************************************************/

#include "find.hpp"

#include <iostream>

#include <cmath>

#include <string>

using namespace std;



/******************************************************************/

/*   This section make a calculation on the value of the node                                                                            */

/******************************************************************/
/******************************************************************/

/*  	    Reuse instruction                                          */

/*          string readlog::logdata()                         */

/*          Purpose: read the log file name            */

/*          Limitations: - the program values must be from global variables            */

/*          Return: node class with the input value                   */

/******************************************************************/

string readlog::logdata( string file_name)
{
	string text;
	string temp;
	ifstream file;
	file.open(file_name);

	while (!file.eof())
	{
		getline(file,temp);
		text.append(temp);
	}

	file.close();
	return text;
}

