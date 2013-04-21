//#include "Team_report.hpp"
#include "../commit_data/LogData.hpp"
void Teamdata::Cal_Statistic(std::list<LogData> temp)
{
    std::map <std::string,float>::iterator mit;
    for (std::list<LogData>::iterator it = temp.begin(); it != temp.end(); it++)
    {
	// --------------hours per phase---------------
	cout << "it phrase = " <<it->getPhase() << "\n";
	mit = Total_hours_phase.find(it->getPhase().c_str());
	if (mit != Total_hours_phase.end())
	{
	    mit->second += it->getWorkingHour();
	}
	else
	{
	    Total_hours_phase.insert(St_f_pair (it->getPhase(),it->getWorkingHour()));
	}
	// --------------hours per iteration---------------

	std::string t_iterid = it->getIteration().substr(0,4);
	mit = Total_hours_iter.find(t_iterid.c_str());
	if (mit != Total_hours_iter.end())
	{
	    cout <<mit->first << "\n";
	    cout <<mit->second << "\n";
	    mit->second += it->getWorkingHour();
	}
	else
	{
	    Total_hours_iter.insert(St_f_pair (t_iterid,it->getWorkingHour()));
	}
    }
}
