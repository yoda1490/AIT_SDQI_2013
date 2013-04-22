#include "extractor.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;
void extractor::setIterationID(string input) {
   iterationID = input;
}

void extractor::setPhase(string input) {
   phase = input;
}

void extractor::setStartdate(string input) {
   startdate = input;
}

void extractor::setWorkinghour(string input) {
   workinghour = input;
}

void extractor::setWorker(string input) {
   worker = input;
}

void extractor::setDefectInject(string input) {
   defect_inject = input;
}

void extractor::setDefectType(string input) {
   defect_type = input;
}

void extractor::setComment(string input) {
   comment = input;
}


bool have_var = false;

template <typename T>
string Str( const T & t ) {
	ostringstream os;
	os << t;
	return os.str();
}

struct split
{
  enum empties_t { empties_ok, no_empties };
};

template <typename Container>
Container& split(
  Container&                                 result,
  const typename Container::value_type&      s,
  typename Container::value_type::value_type delimiter,
  split::empties_t                           empties = split::empties_ok )
{
  result.clear();
  std::istringstream ss( s );
  while (!ss.eof())
  {
    typename Container::value_type field;
    getline( ss, field, delimiter );
    if (field.empty()) continue;
    result.push_back( field );
  }
  return result;
}
/*
void printExtractor(extractor et)
{
	cout << "==================== Extracted Object ====================" << endl;
        cout << "@iterationID = " << et.getIterationID() << endl;
        cout << "phase = " << et.getPhase() << endl;
        cout << "startdate = " << et.getStartdate() << endl;
        cout << "workinghour = " << et.getWorkinghour() << endl;
        cout << "worker = " << et.getWorker() << endl;
        cout << "defect_inject = " << et.getDefectInject() << endl;
        cout << "defect_type = " << et.getDefectType() << endl;
        cout << "comment = " << et.getComment() << endl;
}

void printResultList(vector<extractor> & v)
{
    for (size_t n = 0; n < v.size(); n++)
    {
        extractor et = v[n];
        cout << "==================== Extracted Object ====================" << endl;
        cout << "@iterationID = " << et.getIterationID() << endl;
        cout << "phase = " << et.getPhase() << endl;
        cout << "startdate = " << et.getStartdate() << endl;
        cout << "workinghour = " << et.getWorkinghour() << endl;
        cout << "worker = " << et.getWorker() << endl;
        cout << "defect_inject = " << et.getDefectInject() << endl;
        cout << "defect_type = " << et.getDefectType() << endl;
        cout << "comment = " << et.getComment() << endl;
    }

}
*/
list<extractor> extractor::main_extract(std::string file_name){
    bool key_commit = false;
    bool key_author = false;
    bool key_date = false;


    bool s_iterationID = false;
    bool s_phase = false;
    bool s_startdate = false;
    bool s_workinghour = false;
    bool s_worker = false;
    bool s_defect_inject = false;
    bool s_defect_type = false;
    bool s_comment = false;

    string comment_stream = "";

    list<extractor> result_list;
  
    readlog rl;
    extractor et; 

    char_separator<char> sep("=\t\n ");
    string t = rl.logdata(file_name);
    //cout << "content = " << t << endl;
    tokenizer< char_separator<char> > tok(t, sep);
    for ( tokenizer< char_separator<char> >::iterator beg = tok.begin();
	  beg != tok.end();
          ++beg)
    { 
        
        if(*beg == "commit" || beg == tok.end()) {
             if(key_commit == false) {
	     	key_commit = true;
             }
	     else {
                s_comment = false;
		et.setComment(comment_stream);
		
		if(have_var) {
                   result_list.push_back(et);
                   //printExtractor(et);
		}
                comment_stream = "";
                key_author = false;
		key_date = false;
		have_var = false;
             }
        }
        else if(*beg == "Author:") {
             key_author = true;
        }
        else if(*beg == "Date:") {
             key_date = true;
             et = extractor();
        }

        if(key_commit == true && key_author == true && key_date == true)
        {
        	if(s_iterationID){
                    have_var = true;
		    et.setIterationID(*beg);
        	    s_iterationID = false;
		}
        	else if(s_phase){
                    have_var = true;
		    et.setPhase(*beg);
        	    s_phase = false;
		}
        	else if(s_startdate){
                    have_var = true;
		    et.setStartdate(*beg);
        	    s_startdate = false;
		}
        	else if(s_workinghour){
                    have_var = true;
		    et.setWorkinghour(*beg);
        	    s_workinghour = false;
		}
        	else if(s_worker){
                    have_var = true;
		    et.setWorker(*beg);
        	    s_worker = false;
		}
        	else if(s_defect_inject){
                    have_var = true;
		    et.setDefectInject(*beg);
        	    s_defect_inject = false;
		}
        	else if(s_defect_type){
                    have_var = true;
		    et.setDefectType(*beg);
        	    s_defect_type = false;
		}
        	else if(s_comment){
                    have_var = true;
                    comment_stream += *beg;
		    comment_stream += " ";
		    //et.setComment(*beg);
        	    //s_comment = false;
		}

        	if(*beg == "@iterationID") {s_iterationID = true;}
        	else if(*beg == "@phase") {s_phase = true;}
        	else if(*beg == "@startdate") {s_startdate = true;}
        	else if(*beg == "@workinghour") {s_workinghour = true;}
        	else if(*beg == "@worker") {s_worker = true;}
        	else if(*beg == "@defect_inject") {s_defect_inject = true;}
        	else if(*beg == "@defect_type") {s_defect_type = true;}
        	else if(*beg == "@comment") {s_comment = true;}
        
        }
    }

    // You can use from result_list that contain extractor object
    //printResultList(result_list);
    return result_list;
}
