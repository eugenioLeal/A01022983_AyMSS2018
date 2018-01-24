#include <iostream>
using namespace std;

class Product {
public:
  virtual void operacion1() = 0;
  virtual void operacion2() = 0;
};

class Producto1 : public Product {
public:
  void operacion1() {
    std::cout << "Estoy en operacion 1 Product 1" << '\n';
  }
  void operacion2() {
    std::cout << "Estoy en operacion 2 Product 1" << '\n';
  }
};

class Producto2 : public Product {
public:
  void operacion1() {
    std::cout << "Estoy en operacion 1 Product 2" << '\n';
  }
  void operacion2() {
    std::cout << "Estoy en operacion 2 Product 2" << '\n';
  }
};

class Creator {
public:
  virtual Product* factoryMethod(int) = 0;
  Product* createProduct(int tipo) {
    Product* myProduct = factoryMethod(tipo);
    myProduct->operacion1();
    myProduct->operacion2();
    return myProduct;
  }
};

class ConcreteCreator : public Creator {
  Product* factoryMethod(int tipo) {
    if( tipo == 1 ) {
      return new Producto1;
    } else {
      return new Producto2;
    }
  }
};
int main(int argc, char const *argv[]) {
  Creator* cliente = new ConcreteCreator();
  Product* miProducto = cliente->createProduct(1);
  return 0;
}
