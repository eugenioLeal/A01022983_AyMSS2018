// Agregar patron Visitor que permita hacer double dispatch
#include <string>
#include <list>
#include <iostream>
using namespace std;

class DocPart {
private:

public:
  string text;
  virtual string toHTML() = 0;
  virtual string toText() = 0;
  virtual string toLaTeX() = 0;
};

class Text : public DocPart {
public:
  string toHTML() {
    return text;
  }
  string toText() {
    return text;
  }
  string toLaTeX() {
    return text;
  }
};
class Bold : public DocPart {
public:
  string toHTML() {
    return "<b>" + text + "</b";
  }
  string toText() {
    return text;
  }
  string toLaTeX() {
    return "\\textbf{" + text + "}";
  }
};
class Hyperlink : public DocPart {
public:
  string URL;
  string toHTML() {
    return "<a href='" + URL + "'>" + text + "</a>";
  }
  string toText() {
    return text;
  }
  string toLaTeX() {
    return "\\href{" + URL + "}{" + text + "}";
  }
};
class Document {
public:
  list<DocPart*> docpart;
  string toHTML() {
    string out = "";
    for( DocPart* d : docpart ) {
      out += d->toHTML();
    }
    return out;
  }
  string toText() {
    string out = "";
    for( DocPart* d : docpart ) {
      out += d->toText();
    }
    return out;
  }
  string toLaTeX() {
    string out = "";
    for( DocPart* d : docpart ) {
      out += d->toLaTeX();
    }
    return out;
  }
};

// Interface
class IVisitor {
private:

public:

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
  cout << "TEXT TO HTML:\n" << d.toHTML() << endl;
  cout << "TEXT TO LATEX:\n" << d.toLaTeX() << endl;
  cout << "TEXT TO TEXT:\n" << d.toText() << endl;

  return 0;
}
