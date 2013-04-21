#include "Team_report.hpp"
#include <stdlib.h>
#include <iostream>
//#include "../extractor/extractor.hpp"
using namespace std;
void Teamdata::Cal_Statistic(std::list<extractor> temp)
{
    std::map <std::string,float>::iterator mit;
    for (std::list<extractor>::iterator it = temp.begin(); it != temp.end(); it++)
    {
	// --------------hours per phase---------------
	//std::cout << "it phrase = " <<it->getPhase() << "\n";
	mit = Total_hours_phase.find(it->getPhase().c_str());
	if (mit != Total_hours_phase.end())
	{
	    mit->second += atof(it->getWorkinghour().c_str());
	}
	else
	{
	    Total_hours_phase.insert(pair <std::string,float>(it->getPhase(),atof(it->getWorkinghour().c_str())));
	}
	// --------------hours per iteration---------------

	std::string t_iterid = it->getIterationID().substr(0,4);
	mit = Total_hours_iter.find(t_iterid.c_str());
	if (mit != Total_hours_iter.end())
	{
	   // cout <<mit->first << "\n";
	    //cout <<mit->second << "\n";
	    mit->second += atof(it->getWorkinghour().c_str());
	}
	else
	{
	    Total_hours_iter.insert(pair <std::string,int>(t_iterid,atof(it->getWorkinghour().c_str())));
	}
    }
}
