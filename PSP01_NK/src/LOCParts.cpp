/*
 * LOCParts.cpp
 *
 *  Created on: Feb 11, 2013
 *      Author: nutkong
 */
#include "LOCParts.hpp"

//--the Parts -------
  std::string Parts::getName()
  {
	return this->partName;
  }
  void Parts::setName(string inps)
  {
	  partName = inps;
  }
  void Parts::insertItem(string inps, std::string inp_beg , std::string inp_end)
  {
	 items.insert( std::pair<Items*,int>(new Items(inps, inp_beg, inp_end),0) );
  }
 //--Item parts----------

  Items::Items* Parts::getItem(string inps) //Return the searching item
  {
	  std::map<Items::Items* ,int>::iterator it;
	  //cout << "----"<< inps << " "<< items.size() << endl ;
	  for (it=items.begin(); it!=items.end(); ++it)
	  {
		  //cout <<"item:" << it->first->getName() << endl;
		  if( inps.compare(it->first->getName()) ==0 )
		  {
			  //cout << "found:" << it->first << endl;
			  return it->first;
		  }
	  }
	  //cout <<"not found:" << inps <<endl;
	  return NULL;
	  //return this->items[inps];
  }
  std::string Parts::getItembeginChar(string ips)
  {
	  Items::Items* temp_item = this->getItem(ips);
		return temp_item->beginChar;
  }
  std::string Parts::getItemendChar(string ips)
  {
	  Items::Items* temp_item = this->getItem(ips);
	  return temp_item->endChar;
  }

  void Parts::detailsPrint() //Print out all the items
  {
 	  std::map<Items::Items* ,int>::iterator it;
 	  for (it=items.begin(); it!=items.end(); ++it)
 	  {
 	     std::cout << it->first->getName() << " => " << it->second << '\n';
 	  }
  }
  int Parts::getTotal(){
  	  int total = 0;
  	  std::map<Items::Items* ,int>::iterator it;
  	  for (it=items.begin(); it!=items.end(); ++it)
  	  {
  		  total += it->second;
  	  }
  	  return total;
    }



 void Parts::countValiditemsInPart(std::string string_input ,int line_number) //Plus the number of items (if found)
  {
	  input_line = string_input;
	  std::string sub_input  = input_line;
	  //cout<<input_line <<endl;

	  number_itemfound = 0;
	  pos = 0;
	  resetItemsTempPosition(); //set all item in the line to npos

	  countItemToken(pos); //accounting token in the line
	  Items* found_token =  fetchFirstToken(input_line.size(),pos); //fetch the first token

	  //cout << found_token->getName() <<endl;
	  if(!call_stack.empty() && !call_stack.back()->beginFlag ) //look for the beginning line
	  {
		  //cout << "LOOK FOR THE BEGINNING LINE1" <<endl;
		  pos = processTokenWithBeginChar(pos);
		  //cout << "GET BEGIN :" <<pos <<endl;
	  }
	  else if(!call_stack.empty() && call_stack.back()->beginFlag) //look for the end line
	  {

		 //cout << "LOOK FOR THE END LINE1" <<endl;
		 pos = processTokenWithEndChar(pos);
		 //cout << "GET END : "<<pos <<endl;
	  }

	  if (found_token != NULL)
	  {
		  //cout<< "token is not null!" << found_token->line_position <<endl;
		  if(found_token->beginChar == "" && ( call_stack.back()->beginFlag|| call_stack.empty()) )
		  {
			  //cout << "plus1-nochar "<< found_token->getName() << " "<< pos << " n:"<< found_token->beginChar << endl;
			  plusItem(found_token);
			  pos = found_token->line_position; //set the new position
		  }
		  else if(found_token->beginChar != "" && call_stack.back()->beginFlag )
		  {
		  }
		  else if(call_stack.back()->beginFlag)
		  {
			  pos = found_token->line_position;
		  }
	  }

	  //cout<< " move pos to:" <<pos <<endl;

	  while(pos != std::string::npos)
	  {
		  countItemToken(pos+1);
		 found_token =  fetchFirstToken(input_line.size(),pos+1); //fetch the next token

		 if(found_token != NULL)
		 {
			 pos = found_token->line_position;

		 }

		 if(!call_stack.empty() && !call_stack.back()->beginFlag ) //look for the beginning line
		 {
			 //cout << "LOOK FOR THE BEGINNING LINE2" <<endl;
			 pos = processTokenWithBeginChar(pos + 1);
		 }
		 else if(!call_stack.empty() && call_stack.back()->beginFlag) //look for the end line
		 {
			 //cout << "LOOK FOR THE END LINE2" <<endl;
			 pos = processTokenWithEndChar(pos + 1);
			 //processTokenWithEndChar(pos + 1);
		 }

		 if (found_token != NULL)
		 {
			 if(found_token->beginChar =="" && (call_stack.back()->beginFlag || call_stack.empty()) )
			 {
				 plusItem(found_token);
				 if(pos < found_token->line_position)
				 pos = found_token->line_position; //set the new position
				 //cout<<" ok plus nochar the found token " << pos<< found_token->getName() << endl;
			 }
			 else if(found_token->beginChar != "" && call_stack.back()->beginFlag )
			 {
				 //cout<<" ok plus char the found token " << pos<< found_token->getName() << endl;
			 }
			 else if( !call_stack.back()->beginFlag )
			 {
				 //cout<<"break!"<<endl;
				 break;
			 }
		 }
		 else
		 {
			 break;
		 }
	  }


	  //cout << call_stack.size() <<endl;
	  if(number_itemfound > 1)
	  {
		  string line_string = static_cast<ostringstream*>( &(ostringstream() << line_number) )->str();
		  warning_message += "\nWarning: multiple items found in one line :" + line_string + " " +input_line;
	  }

  }

  //find and mark items
  void Parts::countItemToken( int start_position)
  {
	  //this method will only check the input string with the insert token
	  std::map<Items::Items* ,int>::iterator it;
	  Items::Items* last_item = NULL;
	  int returnClosingflag = std::string::npos; //use for handle multiple length	 ending flag
	  int returning_pos = std::string::npos;

	  for (it=items.begin(); it!=items.end(); ++it)
	  {
		  int pos = input_line.find(it->first->getName(), start_position);
		  if (pos != std::string::npos)
		  {
			  //cout<< "found item-:" << it->first->getName() << pos <<endl;
			  it->first->line_position = pos;

			  if(it->first->getName() == ";" && pos != 0)
			  if(input_line.substr(pos-1,pos) == "};") //exceptional case
			  {
				 // cout << " it is exceptional"  <<endl;
				  it->first->line_position = std::string::npos;
			  }

		  }
	  }
  }

  int Parts::processTokenWithBeginChar(int beg_pos)//determine the start and close on the item
  {
	  //call_stack.push_back(ite); //push value into the call stack
	  int pos = findBeginToken(beg_pos);
	  if( pos != std::string::npos) //found the start position
	  {
		  //cout <<"found begin! posi "<<pos <<endl;
		  call_stack.back()->line_position = pos;
		  call_stack.back()->beginFlag = true; //search for the closing /Valid to look for token
		  plusItem(call_stack.back());
	  }
	  else //no start found.... it should clear everything behind this position
	  {
		  Items::Items* return_item = NULL;
		  std::map<Items::Items* ,int>::iterator it;
		  for (it=items.begin(); it!=items.end(); ++it)
		  {
			  if(it->first->line_position != std::string::npos && it->first->line_position > beg_pos)
			  {
				  it->first->resetPosition();
			  }
		  }

		  call_stack.back()->beginFlag = false;
		 // cout <<"no begin! found...."<<endl;
	  }

	  return call_stack.back()->line_position;
  }

  int Parts::processTokenWithEndChar( int beg_pos)
  {
	  int pos = findCloseToken(beg_pos);
	  //int close_size ;
	  if( pos != std::string::npos) //found the end position
	  {
		  //cout << "found --end-- posi "<<pos << " " <<call_stack.back()->endChar <<endl;
		  pos += call_stack.back()->endChar.size()+1;
		  /*if(call_stack.back()->endChar == "};")
		  {
			  items[getItem(";")] -=1;
		  }*/
		  call_stack.pop_back(); //remove the call_stack
	  }
	  else //no end found....
	  {
		  pos = 0;
		  //cout <<"no end found...."<<pos <<endl;
	  }
	 // cout << " ---return end :" <<pos <<endl;
	  return pos;
  }

  //get the first token in line
  Items* Parts::fetchFirstToken(int line_size,int line_start)
  {
	//cout<< line_size << " " <<line_start <<endl;
	  Items::Items* return_item = NULL;
	  int min = line_size ;
	  std::map<Items::Items* ,int>::iterator it;
	  for (it=items.begin(); it!=items.end(); ++it)
	  {
		  if(it->first->line_position != std::string::npos && it->first->line_position >= line_start)
		  {
			  if(min >= it->first->line_position) //get the most beginning token
			  {
				  min = it->first->line_position;
				  return_item = it->first;
				  //cout << "fetch First :" << return_item->getName() <<endl;
			  }
		  }
	  }

	  if (return_item != NULL)
	  {
		 // cout<< "return token:" <<return_item->getName() << " line:"<<return_item->line_position <<endl;
		  if(return_item->beginChar != "" ) //found a token that have to look for the beginning char
		  {
			  return_item->beginFlag = false;
			  call_stack.push_back(return_item);
			 // processTokenWithBeginChar(return_item->line_position);
		  }
		  else
		  {
			  return_item->beginFlag =true; //set the token green light
		  }
	  }
	  //else cout <<"return null" <<endl;

	  return return_item;
  }

  void Parts::resetItemsTempPosition()//for start finding item in the line
  {
	  std::map<Items::Items* ,int>::iterator it;
	  for (it=items.begin(); it!=items.end(); ++it)
	  {
		  it->first->resetPosition();
	  }
  }
int Parts::findCloseToken(int start_position) //Check the close token from the callstack
{
	int pos = input_line.find(call_stack.back()->endChar,start_position);
	return pos;
}
int Parts::findBeginToken(int start_position)
{
	int pos = input_line.find(call_stack.back()->beginChar,start_position);
	return pos;
}
void Parts::plusItem(Items* ite)
{
	//cout<<" +plus:"<<ite->getName() <<endl;
	items[ite] +=1;
	++number_itemfound;
}

void Parts::setItem2Look(Items::Items* ite)
{
	item_to_look_for = ite;
}

/*
  int Parts::countItem( int start_position)//Check all items in the config
  {
	  std::map<Items::Items* ,int>::iterator it;
	  Items::Items* last_item = NULL;
	  //int returning_pos = sub_input.size();
	  int returnClosingflag = std::string::npos; //use for handle multiple length ending flag
	  int returning_pos = std::string::npos;

	  //Before start iteration..... look for the Begin character first
	  if(!call_stack.empty() && !call_stack.back()->beginFlag)
	  {
		  int begin_pos = findBeginToken(start_position); //move the call function to the start position of the item
		  if(begin_pos != std::string::npos)
		  {
			  //it->first->beginFlag = true; //found the beginning
			  returning_pos = begin_pos;
			  start_position = begin_pos;
			  last_item = call_stack.back();
			  call_stack.pop_back(); //remove the item from call_stack
			  cout << " found the begin! : " <<endl;
		  }
	  }

	  if(last_item == NULL)
	  for (it=items.begin(); it!=items.end(); ++it)
	  {
		  int pos = input_line.find(it->first->getName(), start_position); //begin line
		  //cout << pos << " " << it->first->getName() <<endl;
		  if (pos != std::string::npos)
		  {
			  if(it->first->beginChar != "") //there exist the begin char
			  {
				  it->first->beginFlag = false;
				  call_stack.push_back(it->first); //Push it to stack and set flag to find the beginning
				  int begin_pos = input_line.find(it->first->beginChar,pos+1); //move the call function to the start position of the item
				  if(begin_pos != std::string::npos)
				  {
					  if(returning_pos > begin_pos || returning_pos == std::string::npos)
					  {
						  it->first->beginFlag = true; //found the beginning now look for the end
						  last_item = it->first;
						  returning_pos = begin_pos;
						  //break;
					  }
				  }
				  else //can't find the beginning in this state
				  {
					  returning_pos = sub_input.size(); //Move to the end and terminate
					  break;
				  }
			  }
			  else //token does not require endChar
			  {
				 if(!call_stack.empty())
				 {
					 if(!call_stack.back()->beginFlag) //in finding beginChar mode , ignore all
						if(returning_pos > pos || returning_pos == std::string::npos)
						{
							last_item = it->first;
							returning_pos = pos;
						}
				 }
				 else
				 {
					 if(returning_pos > pos || returning_pos == std::string::npos)
					  {
						  last_item = it->first;
						  returning_pos = pos;
					  }
				 }
			  }
		  }

		  //Also look for close token too, if no token found
		  if(!call_stack.empty() && call_stack.back()->beginFlag)
		  {
			  int close_pos = findCloseToken(start_position);
			  if( close_pos != std::string::npos)//found end char.... move forward
			  {
				  //if(close_pos < returning_pos || returning_pos == std::string::npos)
				  //{
				  int end_char_size = call_stack.back()->endChar.size();
				  //cout<< "found item in call stack:" << call_stack.back()->endChar <<endl;
				  //call_stack.pop_back();
				  returning_pos = close_pos;
				  returnClosingflag = close_pos;
				  //}
			  }
			  //if the endChar is not in this sub string, carry on
		  }

	  }

	  //Finish iterations return the first token that found
	  if(returning_pos == returnClosingflag && returnClosingflag != std::string::npos )
	  {
		  int end_char_size = call_stack.back()->endChar.size();
		  call_stack.pop_back();
		  returnClosingflag = returning_pos + (end_char_size-1);
	  }
	  else if(last_item != NULL)
	  {
		  items[last_item] += 1;
		  ++number_itemfound;
	  }

	  cout << "return:" <<returning_pos <<endl;
	  return returning_pos;
  }*/

/*
void Parts::countValiditemsInPart(std::string string_input ,int line_number) //Plus the number of items (if found)
{
	  input_line = string_input;
}*/





  std::string Parts::showTheError(){
	  if(!call_stack.empty())
	  {
		  warning_message += "\nWarning: the call stack is not empty, forget to close a syntax somewhere";
	  }
	  return warning_message;
  }

