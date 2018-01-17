class Prototype {
public:
  virtual Prototype* clone() = 0;
};

class Concrete1 : public Prototype {
public:
  Prototype* clone() {
    // not correct because it only returns a reference to itself
    // return this;
    // using keyword new utilizes Heap
    return new Concrete1(*this);
    /* the problem with this is that it dangling pointer
     Concrete1 copia = *(this);
     return &copia; */
  }
};
int main(int argc, char const *argv[]) {
  Concrete1 *c1 = new Concrete1;
  return 0;
}
