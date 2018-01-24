// utilizar templates en factoryMethod para eliminar if's
// Ensamblado, Hojalateria, Pintura, Entrega
#include <iostream>
using namespace std;

class Vehiculo {
public:
  virtual void ensamblado() = 0;
  virtual void hojalateria() = 0;
  virtual void pintura() = 0;
  virtual void entrega() = 0;
};

class Dodge : public Vehiculo {
public:
  void ensamblado() {
    std::cout << "Ensamblando Dodge" << '\n';
  }
  void hojalateria() {
    std::cout << "Hojalateria Dodge" << '\n';
  }
  void pintura() {
    std::cout << "Pintando Dodge" << '\n';
  }
  void entrega() {
    std::cout << "Entregando Dodge" << '\n';
  }
  void describe() {
    std::cout << "Soy un Dodge!" << '\n';
  }
};

class BMW : public Vehiculo {
public:
  void ensamblado() {
    std::cout << "Ensamblando BMW" << '\n';
  }
  void hojalateria() {
    std::cout << "Hojalateria BMW" << '\n';
  }
  void pintura() {
    std::cout << "Pintando BMW" << '\n';
  }
  void entrega() {
    std::cout << "Entregando BMW" << '\n';
  }
  void describe() {
    std::cout << "Soy un BMW!" << '\n';
  }
};

class VW : public Vehiculo {
public:
  void ensamblado() {
    std::cout << "Ensamblando VW" << '\n';
  }
  void hojalateria() {
    std::cout << "Hojalateria VW" << '\n';
  }
  void pintura() {
    std::cout << "Pintando VW" << '\n';
  }
  void entrega() {
    std::cout << "Entregando VW" << '\n';
  }
  void describe() {
    std::cout << "Soy un VW!" << '\n';
  }
};

class Nissan : public Vehiculo {
public:
  void ensamblado() {
    std::cout << "Ensamblando Nissan" << '\n';
  }
  void hojalateria() {
    std::cout << "Hojalateria Nissan" << '\n';
  }
  void pintura() {
    std::cout << "Pintando Nissan" << '\n';
  }
  void entrega() {
    std::cout << "Entregando Nissan" << '\n';
  }
  void describe() {
    std::cout << "Soy un Nissan!" << '\n';
  }
};

class Creator {
private:
  template <class Tipo>
  Tipo* factoryMethod() {
    return new Tipo;
  }
public:
  template <class Tipo>
  Tipo* create() {
    Tipo* temporal;
    temporal = factoryMethod<Tipo>();
    temporal->ensamblado();
    temporal->hojalateria();
    temporal->pintura();
    temporal->entrega();
    return temporal;
  }
};

int main(int argc, char const *argv[]) {
  Creator* c = new Creator;
  BMW* miBMW = c->create<BMW>();
  miBMW->describe();
  Nissan* miNissan = c->create<Nissan>();
  miNissan->describe();

  delete c;
  delete miBMW;
  delete miNissan;
  return 0;
}
