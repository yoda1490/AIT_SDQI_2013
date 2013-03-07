#include "Countln.hpp"
#include <boost/tokenizer.hpp>
using namespace std;
using namespace boost;
bool countln::ccomment(string t){
	boost::char_separator<char> sep(" \t");
	tokenizer< char_separator<char> > tok(t, sep);
	for ( tokenizer< char_separator<char> >::iterator beg = tok.begin();
		beg != tok.end();
		++beg){
      		if(comment == true && commentl == false){
			if (*beg == "*/"){
				comment = false;
			}
		}
		else if (*beg == "/*"){
			comment = true;
			
		}
		else if (*beg == "//"){
			comment = true;
			commentl = true;	
			break;	
		}
		else if (commentl == true){
			commentl = false;
			return false;
			break;		
		}
		else{
			comment = false;		
		}
	}
	return comment;
	
}






void countln::cclass(string t){
	boost::char_separator<char> sep(" \t","::");
	tokenizer< char_separator<char> > tok(t, sep);
	tokenizer< char_separator<char> >::iterator wbeg = tok.begin();
	if (*wbeg == "class"){
		classc = true;
		n = new node;
		if (start_ptr == NULL){
			start_ptr= n;
			temp = n;
			n->name = *++wbeg;
			n->num = 0;
		}
		else if (temp->next == NULL){
			temp->next = n;
			temp = n;
		}
	}
	if (classc == true){
		cloc(t);
		for ( tokenizer< char_separator<char> >::iterator beg = tok.begin();
		beg != tok.end();
		++beg){	
			//cout << *beg;
			if (*beg == "};"){   
				classc = false;
			}
		}
	}
	else{
	 	classc = false;
		cloc(t);
	}
}




bool countln::cloc(string t){
	boost::char_separator<char> sep(" \t","::");
	maxsemi=1;
	csemi=0;
	tokenizer< char_separator<char> > tok(t, sep);
	tokenizer< char_separator<char> >::iterator wbeg = tok.begin();
	if (*wbeg == "while" || *wbeg == "do" || *wbeg == "if" || *wbeg == "else"){
		maxsemi =0;
		numline++;
		if (classc == true){
			n->num++;
		}
	}
	else if (t[0] == '#'){
		numline++;
		if (classc == true){
			n->num++;	
		}
	}
	if(*wbeg == "for"){
		maxsemi =3;
		numline++;
		if (classc == true){
			n->num++;
		}
	}
	for(int i = 0 ;i <= t.size()-1; i++){
		if (t[i] == ';'){
			csemi++;
			if (csemi>=maxsemi){
				if (classc == true){
					n->num+=1;
				}
				numline++;
			}
		}
		//cout << maxsemi<<"\t" << csemi <<"\t" << t[i]<<"\t" <<numline <<"\n";
	}
	
	if (maxsemi< csemi){
		return false;
	}
	else{
		return true;
	}
}
