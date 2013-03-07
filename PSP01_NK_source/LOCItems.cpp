/*
 * LOCItems.cpp
 *
 *  Created on: Feb 11, 2013
 *      Author: nutkong
 */
#include "LOCItems.hpp"

Items::Items (std::string input_name, std::string input_beg , std::string input_end){
	item_name = input_name;
	setBeginEndchar(input_beg,input_end);
	line_position = std::string::npos;
}

void Items::setBeginEndchar(std::string input_beg, std::string input_end)
{
	beginChar = input_beg;
	endChar = input_end;
}
void Items::setName(std::string name_inp)
{
	item_name = name_inp;
}
std::string Items::getName()
{
	return this->item_name;
}
void Items::resetPosition()
{
	this->line_position = -1;
}


