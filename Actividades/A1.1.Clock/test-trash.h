#ifndef CLOCK_H
#define CLOCK_H

class Clock {
private:
  Clock(){};
  ~Clock(){};
  static Clock* instance;
public:
  void date() {
    std::cout << "date!" << '\n';
  }
  static Clock *getInstance() {

  }
};
#endif
