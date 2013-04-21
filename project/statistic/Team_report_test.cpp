/******************************************************************/

/* Program Assignment:  Project                                      */

/* Name:                SDQI 2003 CLASS                             */

/* Date:                20 April 2013          */

/* Description:         Test output from team report*/

/******************************************************************/
//#include "Team_report.hpp"
#include "../commit_data/LogData.hpp"
#define BOOST_TEST_MODULE floatingTest
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
using namespace std;
BOOST_AUTO_TEST_SUITE ( test ) 

BOOST_AUTO_TEST_CASE( test )
{
	list<LogData> temp;
	LogData log_data ("040801", "t" ,"04/05/00" , "5", "faith,NK", "15", "working");
	temp.push_back(log_data);
	LogData log_data2 ("040802", "c" ,"04/05/00" , "5", "faith,NK", "15", "working");
	temp.push_back(log_data2);

	Teamdata team;
	team.Cal_Statistic(temp);
	BOOST_CHECK_EQUAL(team.get_Total_hours_phase("t"),5);
	BOOST_CHECK_EQUAL(team.get_Total_hours_phase("c"),5);
	BOOST_CHECK_EQUAL(team.get_Total_hours_iter("0408"),10);

}

BOOST_AUTO_TEST_SUITE_END( )
