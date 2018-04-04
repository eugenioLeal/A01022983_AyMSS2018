#include <iostream>
using namespace std;

class ArrayInts;

class Proxy {
  ArrayInts* a;
  int idx;
public:
  Proxy(ArrayInts* a, int idx) {
    this->a = a;
    this->idx = idx;
  }
  void operator=(int);
};

class ArrayInts {
  int * array;
  int size;
public:
  ArrayInts() {
    int size = 100;
    array = new int[size];
  }
  Proxy operator[] (int idx) {
    if( idx < 0 ) {
      std::cout << "No negative index" << '\n';
      // throw std::invalid_argument("No negative index");
    }
    return Proxy(this, idx);
  }
  int& setGet(int idx) {
    return array[idx];
  }
};

void Proxy::operator=(int value) {
  if( value < 0 ) {
    std::cout << "No negative values" << '\n';
  } else {
    a->setGet(idx) = value;
  }
}

int main(int argc, char const *argv[]) {
  ArrayInts a;
  a[3] = 5;
  std::cout << a.setGet(3) << '\n';
  
  return 0;
}
