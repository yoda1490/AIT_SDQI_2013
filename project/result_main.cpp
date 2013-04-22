#include "statistic2/Team_report.hpp"
using namespace std;

int main(){
    Teamdata team;
    extractor et;
    list<extractor> tmp = et.main_extract("log/gitlog.txt");
    team.Cal_Statistic(tmp);
    float Total_h_PT = team.get_Total_hours_phase("t");
    float Total_h_PC = team.get_Total_hours_phase("c");
    cout << "Total hours of testing " << Total_h_PT << endl;
    cout << "Total hours of coding " << Total_h_PC << endl;
    cout << "Total hours of working " << Total_h_PC + Total_h_PT << endl;
    cout << "Total number of iteration " << tmp.size() << endl;
        cout << "Average working hours per iteration " << (Total_h_PC + Total_h_PT)/tmp.size() << endl;
    
}
