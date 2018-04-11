#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Abstract Class
class Observer {
public:
  virtual void update(string name, string m) = 0;
  string getName() {
    return name;
  }
protected:
  string name;
};

class ConcreteObserver : public Observer {
public:
  ConcreteObserver(string n) {
    name = n;
  }
  void update(string n, string m) {
    std::cout << name << ": " << n << " message: " << m << '\n';
  }
};


// Abstract class
class Subject {
public:
  virtual void attach(Observer * obs) = 0;
  virtual void detach(Observer * obs) = 0;
  virtual void notifyAll() = 0;
  void setMessage(string m) {
    message = m;
  }
protected:
  vector<Observer*> observers;
  string message;
  string name;
};

class ConcreteSubject : public Subject {
public:
  ConcreteSubject(string n) {
    name = n;
  }
  
  void attach(Observer * obs) {
    observers.push_back(obs);
  }
  void detach(Observer * obs) {
    for(int i = 0; i < observers.size(); i++) {
      if(obs->getName() == observers[i]->getName()) {
        observers.erase(observers.begin() + i);
      }
    }
  }
  void notifyAll() {
    for(int i = 0; i < observers.size(); i++) {
      observers[i]->update(name, message);
    }
  }
};




int main(int argc, char const *argv[]) {
  ConcreteSubject Trump("Trump");
  ConcreteSubject Penia("Pena Nieto");
  ConcreteObserver mvs_news("MVSNews");
  ConcreteObserver televisa_noticias("Televisa Noticias");
  ConcreteObserver cnn("CNN");
  Trump.setMessage("Kovfefe");
  Trump.attach(&mvs_news);
  Trump.attach(&televisa_noticias);
  Trump.attach(&cnn);
  Trump.detach(&televisa_noticias);
  Trump.notifyAll();
  Penia.setMessage("Infrastructructure");
  Penia.attach(&televisa_noticias);
  Penia.notifyAll();
  return 0;
}
