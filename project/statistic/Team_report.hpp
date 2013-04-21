#include <string>
#include <map>
#include <list>
#include <iostream>
#include "../commit_data/LogData.hpp"
class Teamdata {
	protected:
		std::map <std::string,float> Total_hours_phase;
		std::map <std::string,float> Total_hours_iter;
		std::map <std::string,int> Total_def_phase;
		std::map <std::string,int> Total_def_iter;
		std::map <std::string,int> Total_def_per_type;
		typedef pair <std::string,float> St_f_pair;
	public:
		void Cal_Statistic(std::list<LogData> temp);
		//void Cal_def_Statistic(std::list<DefectData> temp)

		 // ----  get total hour for each phrase ----
		float get_Total_hours_phase(std::string f)
		{
			return 	Total_hours_phase.at(f);
		}


		// ----  get total hour for each iteration ----
		float get_Total_hours_iter(std::string f)
		{
			return 	Total_hours_iter.at(f);
		}

		// ----  get total defects for each phrase ----
		std::map <std::string,int> get_Total_def_phase()
		{
			return 	Total_def_phase;
		}

		// ----  get total defects for each iteration ----
		std::map <std::string,int> get_Total_def_iter()
		{
			return 	Total_def_iter;
		}

		// ----  get total defects for each type ----
		std::map <std::string,int> get_Total_def_per_type()
		{
			return 	Total_def_per_type;
		}
};
