#include <iostream>
#include <fstream>
#include <cstring> //string.h
#include <list>
#include <sstream> //read file

using namespace std;



string content;
list<string> classes;


struct classStruct{
	string name;	  //name of the class
	int LOC;		  //nb of line in the class
	int stackCounter; //if <0 end of a class
};

int main( int argc, const char* argv[]){
	
	
	char temp[255];
	//char fname[255] = "PSP0.cpp";
	
	//char fname[255] = "test";

	//getcwd(temp, 255);
	//strcat (temp, "/" );
	//strcat (temp , fname);
	
	const char * file = argv[1];
	
	
	
	//---------- READ SOURCE CODE ----------
	
	infile.open(file);
	if (infile.fail()) //Handle reading file
	{
		cout << "Error opening file input.\n";
		return 1;
	}


	std::ifstream infile;
	
	std::string line;
	std::string temp_line;
	std::list<std::string> lineOfCode;
	int line_number = 0;
	bool comments_flag = false;*
	
	//----------- START PARSING INPUT ------
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		++line_number;
		if (line.size() != 0) //skip empty string
		{
			temp_line = line;
			temp_line.erase(0,line.find_first_not_of(" \n\r\t"));
			if(comments_flag) // Find the closing multiple line comments
			{
				int close_found = temp_line.find("*/");
				if ( close_found != std::string::npos)
				{
					temp_line.erase(0,close_found);
					comments_flag = false;
					if(temp_line.size() != 0) //skip this line
					{
						continue;
					}
				}
				else //close comment not found  skip the whole line
				{
					continue; //still in comment skip to next line
				}
			}

			//CLEAN OUT ALL THE COMMENTS
			if(temp_line.find("//") != std::string::npos)
			{
				temp_line.erase(temp_line.find("//"),temp_line.size());
				if(!temp_line.size())//line is empty, skip this reading
				{
					continue;
				}
			}

			if(temp_line.find("/*")!= std::string::npos)
			{
				if(temp_line.find("*/")!=std::string::npos) //Comment the line
				{
					temp_line.erase(temp_line.find("/*"),temp_line.find("*/"));
				}
				else
				{
					temp_line.erase(temp_line.find("/*"),temp_line.size());
					comments_flag = true;
					continue;
				}
			}


			//cout << temp_line <<endl;
			content << temp_line << endl;

		}
		
	}
	

	return 0;
	
}


int nLOC(){
	
}

list<string> className(){
	
	string line;
	while (std::getline(infile, line))
	{
			
	}
}


int classLOC(string){
	
}
