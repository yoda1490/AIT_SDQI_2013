#include <string>
struct node{
	std::string name;
	int num;
	node* next;
};
class countln{
	private:
		int numline;
		int maxsemi;
		int csemi;
		node* start_ptr;
		bool comment;
		bool classc;
		bool commentl;
		node* n;
		node* temp;
	public:
		countln(){
			start_ptr = NULL;
			comment=false;
			classc = false;
			commentl = false;
			numline = 0;
		}
		
		bool ccomment(std::string t);
		void cclass(std::string t);
		bool cloc(std::string t);
		int getnumline(){
			return numline;
		}		
		node* getstart_ptr(){
			return start_ptr;
		}
		bool getclassc(){
			return classc;
		}
		int getmaxsemi(){
			return  maxsemi;
		}
		int getcsemi(){
			return csemi;
		}
		
};
