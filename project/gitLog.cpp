/* Created by Sakares Saengkaew & Mahdi on 12 april 2013
 * A little piece of code that ask you some information needed to execute
 * git command with good parameter for this project
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

void saveGitLog() 
{
    system("git log > log/gitlog.txt");
}

int main(int argc, char ** argv)
{
    saveGitLog();
}
