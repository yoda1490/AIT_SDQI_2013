/* Created by Sakares Saengkaew & Mahdi on 12 april 2013
 * A little piece of code that ask you some information needed to execute
 * git command with good parameter for this project
*/

#define BOOST_TEST_MODULE gitLogTest
#include <boost/test/included/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/filesystem.hpp>
#include <iostream>
#include <fstream>
#include <istream>

BOOST_AUTO_TEST_SUITE ( gitLogFileSystem ) 

BOOST_AUTO_TEST_CASE( logFileExisted )
{
   assert( boost::filesystem::exists( "../../log/gitlog.txt" ) );
}

BOOST_AUTO_TEST_CASE( FileSizeIsNotZero )
{
   long begin,end;
   std::ifstream myfile ("../../log/gitlog.txt");
   begin = myfile.tellg();
   myfile.seekg (0, std::ios::end);
   end = myfile.tellg();
   myfile.close();
  
   BOOST_ASSERT( (end-begin) != 0);
}

BOOST_AUTO_TEST_SUITE_END( )

