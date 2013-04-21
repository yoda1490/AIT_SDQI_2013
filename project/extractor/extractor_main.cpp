
#include "extractor.hpp"
using namespace std;
int main(){
	extractor et;
	vector <extractor> v = et.main_extract("../log/gitlog.txt");
	//cout << v.size() << endl;
	//et.printResultList(tmp);

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
