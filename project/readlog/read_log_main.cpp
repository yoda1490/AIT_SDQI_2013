#include <iostream>
#include "read_log.hpp"
using namespace std;
int main(){
readlog rl;
cout << rl.logdata("gitlog_test.txt");
}
