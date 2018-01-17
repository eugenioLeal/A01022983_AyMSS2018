#include <iostream>
using namespace std;

class Moviles {
public:
  Moviles() {}
  virtual Moviles* clone() = 0;
  void encender() {
    encendido = true;
    std::cout << "Encendido! " << '\n';
  };
  void apagar() {
    encendido = false;
    std::cout << "Apagado!" << '\n';
  };
  void reiniciar() {
    std::cout << "Reiniciando!" << '\n';
  };
  void restaurar() {
    std::cout << "Restaurando!" << '\n';
    sistemaOperativo = NULL;
    marca = NULL;
    id = 0;
    encendido = false;
  };
protected:
  char* sistemaOperativo;
  char* marca;
  int id;
  bool encendido;
};
class Tablet : public Moviles {
public:
  Tablet() {}
  // Copy Constructor
  Tablet(const Tablet& temp) {
    sistemaOperativo = new char(*(temp.sistemaOperativo));
    marca = new char(*(temp.marca));
    id = temp.id;
    encendido = temp.encendido;
    model = new char(*(temp.model));
  }
  Moviles* clone() {
    return new Tablet(*this);
  }
protected:
  char* model;
};
class Smartphone : public Moviles {
public:
  Smartphone() {}
  // Copy Constructor
  Smartphone(const Smartphone& temp) {
    sistemaOperativo = new char(*(temp.sistemaOperativo));
    marca = new char(*(temp.marca));
    id = temp.id;
    encendido = temp.encendido;
    model = new char(*(temp.model));
  }
  Moviles* clone() {
    return new Smartphone(*this);
  }
protected:
  char* model;
};
class Smartwatch : public Moviles {
public:
  Smartwatch() {}
  // Copy Constructor
  Smartwatch(const Smartwatch& temp) {
    sistemaOperativo = new char(*(temp.sistemaOperativo));
    marca = new char(*(temp.marca));
    id = temp.id;
    encendido = temp.encendido;
    model = new char(*(temp.model));
  }
  Moviles* clone() {
    return new Smartwatch(*this);
  }
protected:
  char* model;
};

int main(int argc, char const *argv[]) {
  Moviles* uno = new Tablet();

  return 0;
}
