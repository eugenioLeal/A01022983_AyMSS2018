#include <iostream>

template <class T>
class Collection {
public:
  virtual void add(T element) = 0;
  virtual int at(T position) = 0;
  virtual Iterator* getIterator() = 0;
  virtual int getNumElements() = 0;
};

template <class T>
class Iterator {
private:
  Collection c;
public:
  Iterator(Collection<T> cc) {
    c = cc;
  }
  bool hasNext() {
    if() {

    }
    return true;
  }
};

int main(int argc, char const *argv[]) {

  return 0;
}
