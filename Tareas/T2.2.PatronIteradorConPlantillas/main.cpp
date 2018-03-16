#include <iostream>

template <class T>
class Collection {
public:
  virtual void add(T element) = 0;
  virtual T at(T position) = 0;
  // virtual Iterator<Array>* getIterator() = 0;
  virtual T getNumElements() = 0;
};

template <class T>
class Iterator {
private:
  Collection<T> c;
public:
  Iterator(Collection<T> cc) {
    c = cc;
  }
  bool hasNext() {
    if(1) {

    }
    return true;
  }
  int next() {

  }
};

int main(int argc, char const *argv[]) {
  // Create a collection of integers
  Collection<int>* int_collection = new 

  // Create a Collection of floats

  // Create an iterator for an array
  Iterator<Array>* i = int_collection->getIterator();
  while( i->hasNext() ) {
    cout << i->next() << " ";
  }
  cout << endl;

  return 0;
}
