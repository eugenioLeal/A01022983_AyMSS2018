#include <iostream>
using namespace std;

class ArrayInts {
  int * array;
  int size;
public:
  ArrayInts() {
    int size = 100;
    array = new int[size];
  }
  int& operator[] (int idx) {
    if( idx < 0 ) {
      std::cout << "no negative index" << '\n';
      // throw std::invalid_argument("No negative index");
    }
    return array[idx];
  }
};

int main(int argc, char const *argv[]) {
  ArrayInts a;
  a[-3] = 5;
  return 0;
}
