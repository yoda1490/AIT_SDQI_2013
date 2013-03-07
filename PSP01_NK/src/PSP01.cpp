//============================================================================
// Name        : PSP01.cpp
// Author      : Nuttapon Kongkitimanon
// Version     :
// Copyright   : SDQI
// Description : Line counterin C++, Ansi-style
//============================================================================

#include "LOCParts.hpp" //include Parts Class


int main() {

	char temp[255];
	//char fname[255] = "PSP0.cpp";
	char fname[255] = "test";

	getcwd(temp, 255);
	strcat (temp, "/" );
	strcat (temp , fname);
	//---------- READ CONFIG FILE ----------
	/* 1.Store the sections of the code in partsName
	 * 2.Prepare the configuration on this partsName by setting a parts
	 * */

	Parts allparts[1];
	allparts[0].setName("all");
	allparts[0].insertItem("#","","");
	allparts[0].insertItem("class","{","};");
	allparts[0].insertItem("for","{","}");
	allparts[0].insertItem("switch","{","}");
	allparts[0].insertItem("case","","");
	allparts[0].insertItem(";","","");


	//allparts[0].countValiditemsInPart("; ; ",0);
	//cout << "------------"<<endl;
	//allparts[0].countValiditemsInPart("foo; }; ",1);
	//cout << "------------"<<endl;
	//allparts[0].countValiditemsInPart(" foo; for(;;){",2);
	//cout << "------------"<<endl;
	//allparts[0].countValiditemsInPart(" foo; }} ",3);
	//cout << "------------"<<endl;
	//allparts[0].countValiditemsInPart("} } ",4);
	//allparts[0].countValiditemsInPart(" for{  # for {  for(;;) #{ } }}");
	//allparts[0].detailsPrint();

	/*allparts[0].insertItem("",char( 0 ),char( 0 ));
	allparts[0].insertItem(";",char( 0 ),char( 0 ));
	allparts[0].setBeginEndChar("{","}");

	allparts[1].setName("class");
	allparts[1].setPart("public",0);
	allparts[1].setPart("void",0);*/

	//---------- READ SOURCE CODE ----------
	std::ifstream infile;
	infile.open(temp);
	if (infile.fail()) //Handle reading file
	{
		cout << "Error opening file input.\n";
		return 1;
	}

	std::string line;
	std::string temp_line;
	std::list<std::string> lineOfCode;
	int line_number = 0;
	bool comments_flag = false;
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

			allparts[0].countValiditemsInPart(temp_line,line_number);
			//cout << "--------" <<endl;
			lineOfCode.push_back(temp_line);
		}
	}
	allparts[0].detailsPrint();
	cout << "total line: " <<allparts[0].getTotal();

	cout << allparts[0].showTheError() <<endl;

	return 0;
}
