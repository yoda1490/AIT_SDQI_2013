/******************************************************************/

/* Program Assignment:  Project                                      */

/* Name:                SDQI 2003 CLASS                             */

/* Date:                20 April 2013          */

/* Description:         Test output from team report*/

/******************************************************************/
#include "Team_report.hpp"
#define BOOST_TEST_MODULE floatingTest
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
using namespace std;
BOOST_AUTO_TEST_SUITE ( test ) 

BOOST_AUTO_TEST_CASE( test )
{
	list<LogData> temp;
	LogData log_data ("0408", "T" ,"04/05/00" , "5", "faith,NK", "15", "working");
	temp.push_back(log_data);
	LogData log_data2  ("0408", "C" ,"04/05/00" , "5", "faith,NK", "15", "working");
	temp.push_back(log_data);

	Teamdata team;
	team.Cal_Statistic(temp);
	BOOST_CHECK_EQUAL(team.get_Total_hours_phase()["T"],5);
	BOOST_CHECK_EQUAL(team.get_Total_hours_phase()["C"],5);
	BOOST_CHECK_EQUAL(team.get_Total_hours_iter()["10"],5);

}

BOOST_AUTO_TEST_SUITE_END( )
