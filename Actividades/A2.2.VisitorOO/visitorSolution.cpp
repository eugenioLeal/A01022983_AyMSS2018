// Agregar patron Visitor que permita hacer double dispatch
#include <string>
#include <list>
#include <iostream>
using namespace std;

class IVisitor;

// Element
class DocPart {
public:
  string text;
  virtual void accept(IVisitor*) = 0;
};
// Concrete Element
class Text : public DocPart {
public:
  void accept(IVisitor* visitor);
};
// Concrete Element
class Hyperlink : public DocPart {
public:
  string URL;
  void accept(IVisitor* visitor);
};
// Concrete Element
class Bold : public DocPart {
public:
  void accept(IVisitor* visitor);
};

// Interface
class IVisitor {
private:

public:
  string out;
  virtual void visit(Hyperlink) = 0;
  virtual void visit(Text) = 0;
  virtual void visit(Bold) = 0;
};
// Concrete Visitor
class HTMLVisitor : public IVisitor {
public:
  void visit(Hyperlink h) {
    out += "<a href='" + h.URL + "'>" + h.text + "</a>";
  }
  void visit(Text t) {
    out += t.text;
  }
  void visit(Bold b) {
    out += "<b>" + b.text + "</b";
  }
};
// Concrete Visitor
class TextVisitor : public IVisitor {
  void visit(Hyperlink h) {
    out += h.text;
  }
  void visit(Text t) {
    out += t.text;
  }
  void visit(Bold b) {
    out += b.text;
  }
};
// Concrete Visitor
class LaTeXVisitor : public IVisitor {
  void visit(Hyperlink h) {
    out += "\\href{" + h.URL + "}{" + h.text + "}";
  }
  void visit(Text t) {
    out += t.text;
  }
  void visit(Bold b) {
    out += "\\textbf{" + b.text + "}";
  }
};

void Text::accept(IVisitor* visitor) {
  visitor->visit(*this);
}
void Bold::accept(IVisitor* visitor) {
  visitor->visit(*this);
}
void Hyperlink::accept(IVisitor* visitor) {
  visitor->visit(*this);
}


class Document {
public:
  list<DocPart*> docpart;
  void accept(IVisitor* visitor) {
    for( DocPart* d : docpart ) {
      d->accept(visitor);
    }
  }
};

int main(int argc, char const *argv[]) {
  Document d;
  Text t1;
  t1.text = "Hola, visita";
  Bold t2;
  t2.text = "mi";
  Hyperlink t3;
  t3.text = "pagina";
  t3.URL = "www.mypage.com";
  d.docpart.push_back(&t1);
  d.docpart.push_back(&t2);
  d.docpart.push_back(&t3);
  HTMLVisitor* htmlvisitor = new HTMLVisitor();
  TextVisitor* textvisitor = new TextVisitor();
  LaTeXVisitor* latexvisitor = new LaTeXVisitor();
  d.accept(htmlvisitor);
  cout << "TEXT TO HTML:\n" << htmlvisitor->out << endl;
  d.accept(textvisitor);
  cout << "TEXT TO TEXT:\n" << textvisitor->out << endl;
  d.accept(latexvisitor);
  cout << "TEXT TO LATEX:\n" << latexvisitor->out << endl;
  delete htmlvisitor;
  delete textvisitor;
  delete latexvisitor;
  return 0;
}
