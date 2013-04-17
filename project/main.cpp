#include <iostream>
#include "commit.hpp"

using namespace std;

void welcomemsg() {
    cout << "Welcome to PDFGL (PSP data from git log) ! " << endl;
    cout << "Please choose type of PSP report." << endl;

    /*
     *  please add the character after there if you wanna add new feature
     *  For example, "b -- <feature short description>"
     */
    cout << "a -- number of commit sorted by author" << endl;

}

int main(){
    commits counter;
    char mode;
    welcomemsg();
    cin >> mode;

    /*
     *  please add the condition after there if you wanna add new feature
     *  For example, "else if(mode == 'c') { //your code }"
     */

    if(mode == 'a') {
        cout << " call function for mode a" << endl;
        
	cout << "result = " << endl;
	counter.numberOfCommitByAuthor();
	//counter.getResult();
    }
    else if(mode == 'b') {
        cout << " call function for mode b" << endl;
        // code for mode 'b'
    }
    else {
	cout << "You did not select the available mode. Try next time.";
    }

    return 0 ;
}
