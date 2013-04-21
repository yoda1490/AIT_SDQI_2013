#include "Team_report.hpp"
void Teamdata::Cal_Statistic(std::list<LogData> temp)
{
    for (std::list<LogData>::iterator it = temp.begin(); it != temp.end(); it++)
    {
	if (Total_hours_iter.size() == 0)
	{
	    Total_hours_phase[it->getPhase()] = it->getWorkingHour();		
	    Total_hours_iter[it->getIteration()]= it->getWorkingHour();
	}
	else
	{
	    Total_hours_phase[it->getPhase()] += it->getWorkingHour();		
	    Total_hours_iter[it->getIteration()] += it->getWorkingHour();
	}
	
    }
}
