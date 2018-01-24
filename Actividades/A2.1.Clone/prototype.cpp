class Prototype {
public:
  virtual Prototype* clone() = 0;
};

class Concrete1 : public Prototype {
public:
  Prototype* clone() {
    //--------------------------------------------------//
    //-- return this; is NOT correct because it only  --//
    //-- returns a reference to itself.               --//
    //--------------------------------------------------//
    //-- Concrete1 copia = *(this); return &copia;    --//
    //-- is NOT correct because it creates a          --//
    //-- dangling pointer.                            --//
    //--------------------------------------------------//
    //-- Use the keyword new so that the program      --//
    //-- utilizes the heap.                           --//
    //--------------------------------------------------//
    return new Concrete1(*this);
  }
};
int main(int argc, char const *argv[]) {
  Concrete1 *c1 = new Concrete1;
  return 0;
}
