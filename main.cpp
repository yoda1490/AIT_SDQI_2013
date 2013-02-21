#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

typedef std::list< std::pair<float,float> > myType;

struct split
{
  enum empties_t { empties_ok, no_empties };
};

template <typename Container>
Container& split(
  Container&                                 result,
  const typename Container::value_type&      s,
  typename Container::value_type::value_type delimiter,
  split::empties_t                           empties = split::empties_ok )
{
  result.clear();
  std::istringstream ss( s );
  while (!ss.eof())
  {
    typename Container::value_type field;
    getline( ss, field, delimiter );
    if ((empties == split::no_empties) && field.empty()) continue;
    result.push_back( field );
  }
  return result;
}

int main()
{
    /* Input and preparation part: Start*/
    int number = 0;
    string input;
    list<pair<float,float> > pairList;

    vector <string> fields;

    cout << "How many pair of number? : \n";
    cout << "Enter number : ";
    cin >> number;

    for(int i = 0 ; i < number ; i++)
    {
        /* Input and preparation part: Start*/

        cout << "\nWrite the number in the pair like this > a b . For example 10 20 \n\n";
        cout << "Enter pair : ";
        cin.ignore();
        getline (cin, input);
        split( fields, input, ' ' );

        float number1,number2;
        //cout << "element 0 = " << stringstream(fields[0]) << " , element 1 = " << stringstream(fields[1]) << " \n";
        stringstream(fields[0]) >> number1;
        stringstream(fields[1]) >> number2;
        pairList.push_back(std::make_pair( number1, number2 ));


        /* Input and preparation part: End*/
    }
    /* Input and preparation part: End*/

    //myType::iterator iter = pairList.begin();

    for(myType::iterator iter = pairList.begin();iter != pairList.end();iter++)
    {
        float s = (*iter).first;
        float c = (*iter).second;

        cout << "pair : first = " << s << " and second = " << c << "\n";
    }

    return 0;
}
