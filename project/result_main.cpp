#include "statistic/Team_report.hpp"
using namespace std;

int main(){
    Teamdata team;
    team.Cal_Statistic(/* output from p'Nut*/);
    cout << "Total hours of testing " << team.get_Total_hours_phase()["T"];
    cout << "Total hours of coding " << team.get_Total_hours_phase()["C"];
    cout << "Total hours of working " << team.get_Total_hours_phase()["C"] + team.get_Total_hours_phase()["T"];
    cout << "Total number of iteration " << temp.size();
        cout << "Average working hours per iteration " << (team.get_Total_hours_phase()["C"] + team.get_Total_hours_phase()["T"])/temp.size();;
    
}
