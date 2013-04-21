#include "Team_report.hpp"
void Teamdata::Cal_Statistic(std::list<LogData> temp)
{
    std::map <std::string,float>::iterator mit;
    for (std::list<LogData>::iterator it = temp.begin(); it != temp.end(); it++)
    {
	// --------------hours per phase---------------
	mit = Total_hours_phase.find(it->getPhase());
	if (mit != Total_hours_phase.end())
	{
	    mit->second += it->getWorkingHour();
	}
	else
	{
	    Total_hours_phase.insert(St_f_pair (it->getPhase(),it->getWorkingHour()));
	}
	// --------------hours per iteration---------------
	mit = Total_hours_iter.find(it->getIteration());
	if (mit != Total_hours_iter.end())
	{
	    mit->second += it->getWorkingHour();
	}
	else
	{
	    Total_hours_iter.insert(St_f_pair (it->getIteration(),it->getWorkingHour()));
	}
	
    }
}
