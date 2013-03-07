#include <iostream>
#include <fstream>
#include <cstring> //string.h
#include <map> //map object to each other
#include <list>
#include <sstream> //read file

using namespace std;
/* The item is one item to be count in parts, */
class Items{
public:
	std::string item_name;
	std::string beginChar,endChar ;
	bool beginFlag ; //FALSE = look for begin , TRUE = look for end
	int line_position; //temp this item position, default = -1

	void setBeginEndchar(std::string input_beg, std::string input_end);
	void setName(std::string name_inp);
	std::string getName();
	void resetPosition();
	Items(std::string, std::string , std::string); //constructor
};

