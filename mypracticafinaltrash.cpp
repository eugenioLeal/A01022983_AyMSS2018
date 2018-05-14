#include <bits/stdc++11>

using namespace std;
//Documentos de texto simple, texto con formato e Imágenes.
class IVisitor;

// Element
class Printer {
public:
  virtual void accept(IVisitor*) = 0
};

template <class T>
class VisitorImplementation : public DocPart{
    void accept(IVisitor* visitor){
        visitor->accept(*T);
    }
};

// Concrete Element
class Text : public Printer, VisitorImplementation<Text>{
public:
  void accept(IVisitor* visitor);
};
// Concrete Element
class FormattedText : public Printer, VisitorImplementation<FormattedText>{
public:
  void accept(IVisitor* visitor);
};

// Concrete Element
class Images : public Printer, VisitorImplementation<Images>{
public:
  void accept(IVisitor* visitor);
};

// Interface
class IVisitor {
  public:
    virtual void visit(Text) = 0;
    virtual void visit(FormattedText) = 0;
    virtual void visit(Images) = 0;
};

// Concrete Visitor
class Laser : public IVisitor {
  void visit(Text T) {
    cout << "Estoy imprimiento texto... "  << T << " en formato laser" << endl;
  }
  void visit(FormattedText  T) {
    cout << "Estoy imprimiento FormattedText... "  << T << " en formato laser" << endl;
  }
  void visit(Images I) {
    cout << "Estoy imprimiento imagen... "  << I << " en formato laser" << endl;
  }
};

// Concrete Visitor
class Injection : public IVisitor {
  void visit(Text T) {
    cout << "Estoy imprimiento texto... "  << T << " en formato Injection" << endl;
  }
  void visit(FormattedText  T) {
    cout << "Estoy imprimiento FormattedText... "  << T << " en formato Injection" << endl;
  }
  void visit(Images I) {
    cout << "Estoy imprimiento imagen... "  << I << " en formato Injection" << endl;
  }
};

// Concrete Visitor
class PDF : public IVisitor {
  void visit(Text T) {
    cout << "Estoy imprimiento texto... "  << T << " en formato PDF" << endl;
  }
  void visit(FormattedText  T) {
    cout << "Estoy imprimiento FormattedText... "  << T << " en formato PDF" << endl;
  }
  void visit(Images I) {
    cout << "Estoy imprimiento imagen... "  << I << " en formato PDF" << endl;
  }
};

// Concrete Visitor
class Postscript : public IVisitor {
  void visit(Text T) {
    cout << "Estoy imprimiento texto... "  << T << " en formato Postscript" << endl;
  }
  void visit(FormattedText  T) {
    cout << "Estoy imprimiento FormattedText... "  << T << " en formato Postscript" << endl;
  }
  void visit(Images I) {
    cout << "Estoy imprimiento imagen... "  << I << " en formato Postscript" << endl;
  }
};
/*
void Text::accept(IVisitor* visitor) {
  visitor->visit(*this);
}
void FormattedText::accept(IVisitor* visitor) {
  visitor->visit(*this);
}
void Images::accept(IVisitor* visitor) {
  visitor->visit(*this);
}
*/

class Main {
public:
    void printAllDocuments(Documents** d, int countDocs, Printers** p, int countPrinters){
      for (int i = 0; i < countDocs; i++){
        for (int j = 0; j < countPrinters; j++){
          d[i].printOn(p[i]);
        }
      }
    }
};

int main(int argc, char const *argv[]) {

  return 0;
}
