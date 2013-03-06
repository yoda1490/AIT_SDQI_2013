
#include <string>
#include <list>
using namespace std;

class finds{
	private:
		int max;
		double xty;
		double xp2;
		double yp2;
		double sumx;
		double sumy;
		double meanx;
		double meany;
		double B1;
		double B0;
		double yk;

	public:
		std::list < pair<double,double> >  temp_list;
		finds(){
			xty = 0.0;
			xp2 = 0.0;
			yp2 = 0.0;
			sumx = 0.0;
			sumy = 0.0;
			meanx = 0.0;
			meany = 0.0;
			B1 = 0.0;	//Regression parameter
			B0 = 0.0;	//Regression parameter
			yk = 0.0;	//The prediction value
		}
		
		void createnode();
		void calculate();
		double getB1(){
			return B1;
		}
		double getB0(){
			return B0;
		}
		double getyk(){
			return yk;
		}
		void setmax(int m){
			max = m;
		}

};
