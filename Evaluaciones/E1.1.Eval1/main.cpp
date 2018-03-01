// compilar con g++ version 14
// g++ -std=g++14 main.cpp
#include <bits/stdc++.h>
using namespace std;

class Command {
public:
  virtual void Execute() = 0;
};

class Invoker {
private:
  std::vector<Command*> _commands;
public:
    void StoreAndExecute(Command *command)
    {
        if (command){
            _commands.push_back(command);
            command->Execute();
        }
    }
};

// Receiver
class Cliente {
  // id, nombre, apellido, forma de contacto, correo, teléfono, calle, número y colonia.
  int id;
  string nombre;
  string apellido;
  string formaDeContacto;
  string correo;
  string telefono;
  string calle;
  string numero;
  string colonia;

public:
  Cliente() {}
  ~Cliente() {}
  //Cliente(int id, string nombre, string apellido, Command c) : cmd(c) {}

  void mandarCorreo() {
    std::cout << "Mandar Correo!" << '\n';
  }
  void enviarSms() {
    std::cout << "Enviar SMS!" << '\n';
  }
  void realizarLlamada() {
    std::cout << "Realizar Llamada!" << '\n';
  }
  void setInfo(int id,string nombre,string apellido,string formaDeContacto,string correo,string telefono,string calle,string numero,string colonia) {
    this->id = id;
    this->nombre = nombre;
    this->apellido = apellido;
    this->formaDeContacto = formaDeContacto;
    this->correo = correo;
    this->telefono = telefono;
    this->calle = calle;
    this->numero = numero;
    this->colonia = colonia;
  }
};

class MandarCorreo : public Command {
private:
  Cliente *_cliente;
public:
  MandarCorreo(Cliente *cliente) {
    _cliente = cliente;
  }
  void Execute() {
    _cliente->mandarCorreo();
  }
};

class EnviarSms : public Command {
private:
  Cliente *_cliente;
public:
  EnviarSms(Cliente *cliente) {
    _cliente = cliente;
  }
  void Execute() {
    _cliente->enviarSms();
  }
};

class RealizarLlamada : public Command {
private:
  Cliente *_cliente;
public:
  RealizarLlamada(Cliente *cliente) {
    _cliente = cliente;
  }
  void Execute() {
    _cliente->realizarLlamada();
  }
};

class Tienda {
private:
  Tienda() {}
  ~Tienda() {}
  static Tienda* instance;
  vector<Cliente> list;
public:
  static Tienda *getInstance() {
    std::cout << "getInstance!" << '\n';
    if( instance = 0 ) {
      instance = new Tienda;
    }
    return instance;
  }
  static Tienda *deleteInstance() {
    if( instance != NULL ) {
      delete instance;
      instance = NULL;
    }
  }

  void leerArchivo(string fileName) {
    // id, nombre, apellido, forma de contacto, correo, teléfono, calle, número y colonia.
    int id;
    string nombre;
    string apellido;
    string formaDeContacto;
    string correo;
    string telefono;
    string calle;
    string numero;
    string colonia;

    std::fstream myfile( fileName, std::ios_base::in);
    while(myfile)
    {

        std::string line;
        std::string word;
        getline(myfile,line);
        std::stringstream ss(line);
        while(getline(myfile,line))
        {
            std::stringstream sss(line);
            getline(sss, word,',');
            id=stoi(word);
            getline(sss, word,',');
            nombre=word;
            getline(sss, word,',');
            apellido=word;
            getline(sss, word,',');
            formaDeContacto=word;
            getline(sss, word,',');
            correo=word;
            getline(sss, word,',');
            telefono=word;
            getline(sss, word,',');
            calle=word;
            getline(sss, word,',');
            numero=word;
            getline(sss, word,',');
            colonia=word;
            Cliente cliente = new Cliente();
            cliente.setInfo(id, nombre, apellido, formaDeContacto, correo, telefono, calle, numero, colonia);
        }
        delete cliente;

    }
  }
};
Tienda* Tienda::instance = 0;



int main(int argc, char const *argv[]) {
  Tienda *instance = Tienda::getInstance();
  // instance->leerArchivo("customers.txt");
  instance->deleteInstance();

  // std::unique_ptr<Cliente> cliente = std::make_unique<Cliente>();
  // std::unique_ptr<Command> correo (new MandarCorreo(cliente.get()));
  // std::unique_ptr<Command> llamada (new RealizarLlamada(cliente.get()));
  // std::unique_ptr<Command> sms (new EnviarSms(cliente.get()));
  //
  //
  // std::unique_ptr<Invoker> switcher = std::make_unique<Invoker>();
  // switcher->StoreAndExecute(correo.get());
  // switcher->StoreAndExecute(llamada.get());
  // switcher->StoreAndExecute(sms.get());
  return 0;
}

/*
Crees las clases necesarias para almacenar la información de los clientes
Leas el archivo con la información de los clientes
Crees instancias de clases a partir de la información leída del archivo
Programes tres funciones diferentes (mandar correo, enviar sms y realizar llamada). Cada función es una función dummy que únicamente imprime en pantalla la operación que está realizando con los detalles de cada operación
Programar una función que envíe un mensaje a todos sus clientes informándoles los detalles del nuevo lanzamiento
Incluir los diagramas de casos de uso y clase de todo lo programado (entrega la imagen y el archivo puml)
Utiliza los patrones de programación vistos en clase (singleton, factory method, prototype and command)
Al menos utiliza : command y dos de creación
*/

// En main
// Creator* cliente1 = new ConcreteCreator();
// Cliente* miCliente = cliente1->createProduct(1);
//
// Creator* cliente1 = new ConcreteCreator();
// Cliente* miCliente = cliente1->createProduct(2);
//
// Creator* cliente1 = new ConcreteCreator();
// Cliente* miCliente = cliente1->createProduct(3);

// class Creator {
// public:
//   virtual Cliente* factoryMethod(int) = 0;
//   Cliente* createCliente(int tipo) {
//     Cliente* myCliente = factoryMethod(tipo);
//     myCliente->leerArchivo();
//     return myCliente;
//   }
// };
//Programes tres funciones diferentes (mandar correo, enviar sms y realizar llamada). Cada función es una función dummy que únicamente imprime en pantalla la operación que está realizando con los detalles de cada operación

// class ConcreteCreator : public Creator {
//   Cliente* factoryMethod(int tipo) {
//     if( tipo == 1 ) {
//       return new ClienteCorreo;
//     } else if( tipo == 2 ){
//       return new ClienteSMS;
//     } else if( tipo == 3 ) {
//       return new ClienteLlamada;
//     }
//   }
// };

// void leerArchivo(char* fileName) {
//   char* id, *nombre, *apellido, *formaDeContacto, *correo, *telefono, *calle, *numero, *colonia;
//   FILE *fp;
//   char buff[500];
//   fp = fopen(fileName, "r");
//   // id, nombre, apellido, forma de contacto, correo, teléfono, calle, número y colonia.
//   while( fp != EOF ) {
//     fscanf(fp, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]\n", id, nombre, apellido, formaDeContacto, correo, telefono, calle, numero, colonia);
//     std::cout << id << " " << nombre << " " << apellido << " " << formaDeContacto << " " << correo << " " << telefono << " " << calle << " " << numero << " " << colonia << " " <<'\n';
//   }
// }
