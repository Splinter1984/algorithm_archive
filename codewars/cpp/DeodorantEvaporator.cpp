/*This program tests the life of an evaporator containing a gas.
We know the content of the evaporator (content in ml), the percentage of foam or gas lost every day (evap_per_day) and the threshold (threshold) in percentage beyond which the evaporator is no longer useful. All numbers are strictly positive.
The program reports the nth day (as an integer) on which the evaporator will be out of use.
Example:
evaporator(10, 10, 5) -> 29*/

using namespace std;
class Evaporator
{

  public:
  static int evaporator(double content, double evap_per_day, double threshold);
};

int Evaporator::evaporator(double content, double evap_per_day, double threshold)
{
    int days = 1;
    double border = content*threshold/100;
    while(content - content*evap_per_day/100 > border)
    {
      result++;
      content-=content*evap_per_day/100;
    }
    return days;
}
