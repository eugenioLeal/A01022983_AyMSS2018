//----------------------------//
//-- Eugenio Leal A01022983 --//
//-- Activity 1             --//
//-- Parcial 1              --//
//-- Clock Singleton        --//
//----------------------------//
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

  instance->deleteInstance();

  std::cout << instance << '\n';
  std::cout << instance2 << '\n';

  //------------------------------------------------------//
  //-- Double delete will cause a compilation error! :) --//
  //------------------------------------------------------//
  // delete instance;
  // delete instance2;
  return 0;
}
