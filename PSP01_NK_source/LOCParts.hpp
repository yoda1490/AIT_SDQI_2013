
#include "LOCItems.hpp"

using namespace std;
/*number of Items in each part*/
class Parts
{
  public:
	std::string partName;
	std::map< Items* , int >items; //Items to be screen and counting
	char beginChar;
	char endChar;
	std::string part_status;
	bool beg_symbol_found;
	std::string WARN_LINE; //= "unrespect to code standard implementation is found.";
	std::string WARN_NONEXCUTABLE; //= "unexcutable code is found";
	std::string warning_message;
	std::list<Items* > call_stack; //storing call stack
	std::string input_line;
	//Items* last_item; //temp storing the itemss
	int number_itemfound;
	Items* item_to_look_for;
	int pos;

	std::string getName();
	void setName(string inps);
	void insertItem(string inps, std::string inp_beg , std::string inp_end);
	//--Item parts----------
	Items* getItem(string inps); //Return the searching item
	std::string getItembeginChar(string ips);
	std::string getItemendChar(string ips);

	void detailsPrint(); //Print out all the Items
	int getTotal();

	void countValiditemsInPart(std::string string_input ,int line_number); //Plus the number of Items (if found)
	int countItem( int start_position);//Check all Items in the config
	int findCloseToken(int start_position); //Check the close token from the callstack
	int findBeginToken(int start_position);
	void resetItemsTempPosition(); // Reset the temp position of each items
	void countItemToken( int start_position); //account item, push them in stack
	int processTokenWithBeginChar( int beg_pos);
	int processTokenWithEndChar( int beg_pos);
	Items* fetchFirstToken(int line_size,int line_start); //fetch the first token of the line
	void plusItem(Items* ite);

	void setItem2Look(Items* ite);

	std::string showTheError();
};
