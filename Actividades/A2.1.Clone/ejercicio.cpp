// Patrón clonar (clase móviles, tablet, smartphone, smartwatch): 
//3 apuntadores, 2 variables normales. 4 métodos. Método clone. Constructores copia.
// Tarea: hacer que todos hereden el metodo clone() 

#include <iostream>
#include <string>
using namespace std;
//------------------------------------//
class Movil {
public:
  Movil() {}
  virtual Movil* clone() = 0;
  virtual void queSoy() = 0;
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
public:
  char* sistemaOperativo;
  char* marca;
  int id;
  bool encendido;
};
//------------------------------------//
// Aqui trate de usar templates para heredar clone
// template <typename Padre, typename Hijo>
// class MovilClonable : public Padre {
// public:
//   virtual Padre* clone() {
//     return new Hijo(static_cast<Hijo const &>(*this));
//   }
// };
//------------------------------------//
//class Tablet : public MovilClonable<Movil, Tablet> {
class Tablet : public Movil {
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
  Movil* clone() {
    return new Tablet(*this);
  }
  void queSoy() {
    std::cout << "soy Tablet" << std::endl;
  }
protected:
  char* model;
// private:
//   typedef MovilClonable<Movil, Tablet> ClasePadre;
};
class Smartphone : public Movil {
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
  Movil* clone() {
    return new Smartphone(*this);
  }
  void queSoy() {
    std::cout << "soy Smartphone" << std::endl;
  }
protected:
  char* model;
};
//------------------------------------//
class Smartwatch : public Movil {
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
  Movil* clone() {
    return new Smartwatch(*this);
  }
  void queSoy() {
    std::cout << "soy Smartwatch" << std::endl;
  }
protected:
  char* model;
};

int main(int argc, char const *argv[]) {
  Movil *miTablet = new Tablet();
  miTablet->encender();
  miTablet->queSoy();
  
  Movil *desconocido = miTablet->clone();

  // free memory
  delete miTablet;
  delete desconocido;
  return 0;
}
