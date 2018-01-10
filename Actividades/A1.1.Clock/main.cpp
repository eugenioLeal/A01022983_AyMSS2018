#include <iostream>
#include "Clock.h"

using namespace std;

int main(int argc, char const *argv[]) {
  Clock *instance = Clock::getInstance();
  instance->date();
  Clock *instance2 = Clock::getInstance();
  instance2->date();

  std::cout << instance << '\n';
  std::cout << instance2 << '\n';
  return 0;
}
