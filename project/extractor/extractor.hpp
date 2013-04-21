#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <iostream>
#include "../readlog/read_log.hpp"

class extractor {
    protected:
        std::string iterationID, phase, startdate, workinghour, worker, defect_inject, defect_type, comment;

    public:	

        extractor() 
    	{ 
        	iterationID = "";
        	phase = "";
        	startdate = "";
        	workinghour = "";
        	worker = "";
        	defect_inject = "";
        	defect_type = "";
        	comment = "";
    	}     

        std::string getIterationID(){
   		return iterationID;
	};
        void setIterationID(std::string input);

        std::string getPhase(){
   		return phase;
	};
        void setPhase(std::string input);

        std::string getStartdate(){
   		return startdate;
	}
        void setStartdate(std::string input);

        std::string getWorkinghour(){
   		return workinghour;
	}
        void setWorkinghour(std::string input);

        std::string getWorker(){
   		return worker;
	}
        void setWorker(std::string input);

        std::string getDefectInject(){
   		return defect_inject;
	}
        void setDefectInject(std::string input);

        std::string getDefectType(){
   		return defect_type;
	}
        void setDefectType(std::string input);

        std::string getComment(){
   		return comment;
	}
        void setComment(std::string input);
	std::vector<extractor> main_extract(std::string file_name);
	//void printExtractor(extractor et);
	//void printResultList(std::vector<extractor> & v);
};

