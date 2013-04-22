
#include "extractor.hpp"
#include <list>
#include <iterator>
#include <iostream>
using namespace std;
int main(){
	extractor et;
	list <extractor> v = et.main_extract("../log/gitlog.txt");
	//cout << v.size() << endl;
	//et.printResultList(tmp);
        for (std::list<extractor>::iterator it = v.begin(); it != v.end(); it++)
    //std::cout << *it << ' ';
    //    for (size_t n = 0; n < v.size(); n++)
    {
        extractor et = *it;
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
