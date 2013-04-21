#include "Team_report.hpp"
void Teamdata::Cal_Statistic(std::list<LogData> temp)
{
    for (std::list<LogData>::iterator it = temp.begin(); it != temp.end(); it++)
    {
	// assign value to the null value
	if (Total_hours_iter.size() == 0)
	{
	    // ------Working hour -----
	    Total_hours_phase[it->getPhase()] = it->getWorkingHour();		
	    Total_hours_iter[it->getIteration()]= it->getWorkingHour();
	}
	// add value for each loop
	else
	{
	    // ------Working hour -----
	    Total_hours_phase[it->getPhase()] += it->getWorkingHour();		
	    Total_hours_iter[it->getIteration()] += it->getWorkingHour();
	}
	
    }
}
