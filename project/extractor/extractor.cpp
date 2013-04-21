#include "extractor.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

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
