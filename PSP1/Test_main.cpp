/******************************************************************/

/* Program Assignment:  PSP1                                        */

/* Name:                SDQI 2003 CLASS                             */

/* Date:                18 February 2013          */

/* Description:         Test PSP1*/

/******************************************************************/

#include "find.hpp"
#define BOOST_TEST_MODULE floatingTest
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <cmath>


BOOST_AUTO_TEST_SUITE ( test ) 

BOOST_AUTO_TEST_CASE( test )
{
	finds fn;
	fn.temp_list.push_back( pair<double,double>(130, 186)) ;
	fn.temp_list.push_back( pair<double,double>(650, 699)) ;
	fn.temp_list.push_back( pair<double,double>(99, 132)) ;
	fn.temp_list.push_back( pair<double,double>(150, 272)) ;
	fn.temp_list.push_back( pair<double,double>(128, 291)) ;
	fn.temp_list.push_back( pair<double,double>(302, 331)) ;
	fn.temp_list.push_back( pair<double,double>(95, 199)) ;
	fn.temp_list.push_back( pair<double,double>(945, 1890)) ;
	fn.temp_list.push_back( pair<double,double>(368,788)) ;
	fn.temp_list.push_back( pair<double,double>(961, 1601)) ;
  	double B0 = -22.5525;
  	double B1 = 1.727932;
	double yk = 644.4294;
	fn.setmax(10);
	fn.calculate();
  	BOOST_CHECK_CLOSE_FRACTION (B0, fn.getB0(), 0.001); 
	BOOST_CHECK_CLOSE_FRACTION (B1, fn.getB1(), 0.001);
	BOOST_CHECK_CLOSE_FRACTION (yk, fn.getyk(), 0.001); 
}

BOOST_AUTO_TEST_SUITE_END( )
