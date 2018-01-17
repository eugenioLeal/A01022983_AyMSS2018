#include <iostream>
using namespace std;

class Prueba {
public:
  int *val;
  int val2;
  Prueba() {
    std::cout << "default constructor" << '\n';
  }
  Prueba(int val) : val(new int(val)), val2(val) {
    std::cout << "Params: " << val << '\n';
  }
  // Copy Constructor
  Prueba(const Prueba& temp) {
    std::cout << "Copy Constructor Activated" << '\n';
    val = new int(*(temp.val));
    //val2 = *(temp.val);
  }
};

int main(int argc, char const *argv[]) {
  //Prueba p;
  Prueba * z = new Prueba(2);
  std::cout << "before " << *(z->val) << '\n';
  // Calls Copy Constructor
  Prueba w = *z;
  std::cout << "copy " << *(w.val) << '\n';

  // Modify copy constructor
  std::cout << "modifying val" << '\n';
  *(w.val) = 8;
  // Printing original
  std::cout << "instancia " << *(z->val) << '\n';
  std::cout << "copy " << *(w.val) << '\n';
  return 0;
}
