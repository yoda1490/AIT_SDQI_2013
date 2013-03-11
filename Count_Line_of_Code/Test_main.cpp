#include "main.cpp"
#define BOOST_TEST_MODULE floatingTest
#include <boost/test/included/unit_test.hpp>
#include <string>
#include <iostream>

BOOST_AUTO_TEST_SUITE ( test ) 

BOOST_AUTO_TEST_CASE( test )
{
  	BOOST_CHECK (nLOC() == 13); 
	BOOST_CHECK (classname().size() == 2);
	BOOST_CHECK (classLOC("s") == 3);
	BOOST_CHECK (classLOC("ss") == 1);
}

BOOST_AUTO_TEST_SUITE_END( )
