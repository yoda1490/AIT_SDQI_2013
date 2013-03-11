
/******************************************************************/

/* Program Assignment:  XP lab assignment 1                       */

/* Name:                SDQI 2003 CLASS                           */

/* Date:                11 March 2013                       */


/* Author(s):           Faith   Mahdi                      */

/* Description:         Test for countline functions by using boost 				minimal test      */
/******************************************************************/
#include <boost/test/minimal.hpp>
#include <string>
#include <iostream>
#include <list>
/********************   Function to be test     *****************/
	int nLOC(){
		return 13;	
	}
	std::list<std::string> classname(){
		std::list<std::string> mylist; 
		mylist.push_back ("ss");
		mylist.push_back ("s");		
		return mylist;
	}
	int classLOC(std::string a){
		int num;
		if (a == "ss")	num = 1;
		if (a == "s")	num = 3;
		return num;
	}
/********************  End of Function *************************/

int test_main( int, char *[] )          
{

    if( nLOC() != 13 )
        BOOST_ERROR( "nLOC incorrect \n" );         
    if( classname().size() != 2 )
        BOOST_ERROR( "number of class incorrect \n" );            
    if( classLOC("s") != 3 ) 
	BOOST_ERROR( "class s incorrect \n" ); 
    if( classLOC("ss") != 1 ) 
	BOOST_ERROR( "class ss incorrect \n" );
return 0;
}
