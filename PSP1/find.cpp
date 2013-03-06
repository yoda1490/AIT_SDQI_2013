/******************************************************************/

/* Program Assignment:  PSP1                                        */

/* Name:                SDQI 2003 CLASS                             */

/* Date:                18 February 2013          */

/* Description:         Find Correlation and calculate LOC efficient*/

/******************************************************************/

#include "find.hpp"

#include <iostream>

#include <cmath>

using namespace std;



/******************************************************************/

/*   This section make a calculation on the value of the node                                                                            */

/******************************************************************/



/******************************************************************/

/*    Reuse instructions                                          */

/*          void finds::createnode()                         */

/*          Purpose: create the node structure for "finds" class            */

/*          Limitations: - the program values must be from global variables            */

/*          Return: node class with the input value                   */

/******************************************************************/

void finds::createnode()
{
	double x,y;

	for (int i=0;i<max;i++){//);

		cout << i+1<<".    x:";
		cin >> x;
		cout <<"      y:";
		cin >> y;
		temp_list.push_back( pair<double,double>(x, y)) ;
	}
}


/******************************************************************/

/*    Reuse instructions                                          */

/*          void finds::calculate()                         */

/*          Purpose: make a calculation to find the correlation          */

/*          Limitations: The global object , start_prt, must be set    */

/*          Return yk (the correlation problems)                                         */

/******************************************************************/
void finds::calculate()
{
	std::list < pair<double,double> >::iterator  i;

	//Calculate each node and put them into global variables 
	for (i = temp_list.begin() ; i!=temp_list.end() ; i++){ 
		sumx += i->first;
		sumy += i->second;
		xty +=  (i->first* i->second);
		xp2 += pow(i->first,2);
		yp2 += pow(i->second,2);
	}
	
	meanx = sumx/max;
	meany = sumy/max;
	B1 = (xty - (max * meanx * meany)) / (xp2 - max *pow(meanx,2) );
	B0 = meany - (B1*meanx);
	yk =  B0 + (B1*386); //Assign the final value to global variable

	cout << sumx  << endl;
	cout << sumy  << endl;
	cout << xty  << endl;
	cout << xp2  << endl;
	cout << yp2  << endl;

}
