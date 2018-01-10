#ifndef CLOCK_H
#define CLOCK_H

#include <ctime>
using namespace std;
class Clock {
public:

  void date() {
    // current date/time based on current system
   time_t now = time(0);

   // convert now to string form
   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;

  }
  static Clock *getInstance() {
    std::cout << "hola" << '\n';
    if( instance == 0 ) {
      instance = new Clock;
    }
    return instance;
  }
private:
  Clock(){};
  static Clock* instance;
};

Clock* Clock::instance = 0;

#endif
