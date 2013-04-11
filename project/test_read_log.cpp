/******************************************************************/

/* Program Assignment:  PSP1                                        */

/* Name:                SDQI 2003 CLASS                             */

/* Date:                18 February 2013          */

/* Description:         Test PSP1*/

/******************************************************************/

#include "read_log.hpp"
#define BOOST_TEST_MODULE floatingTest
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <string>
#include <iostream>

BOOST_AUTO_TEST_SUITE ( test ) 

BOOST_AUTO_TEST_CASE( test )
{
	logdata log_c;
	std::string datas = readlog::logdata();
	cout << endln;
	if (datas.length() != "")
		BOOST_ERROR("the number of log does not match");
	cout << endln;
}

BOOST_AUTO_TEST_SUITE_END( )
