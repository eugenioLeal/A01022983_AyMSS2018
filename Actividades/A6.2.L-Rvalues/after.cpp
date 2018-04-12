// Rvalue references

#include <iostream>
using namespace std;

class Foo {
private:
	int value;
	int* pointer;
public:
	explicit Foo(int value = 0) : value(value), pointer(new int[value]) {
		cout << "param constructor" << endl;
	}
	Foo(const Foo& val) {
		cout << "copy constructor" << endl;
	}
	Foo& operator = (const Foo& ref) {
		// Para intercambiar valores podrias
		// Foo temp;
		// this->value = ref.value;
		// this->pointer = new int[value];
		// Podrias hacer un right value a un left value
		cout << "copy assignment" << endl;
		Foo temp(ref);
		std::swap(value, temp.value);
		std::swap(pointer, temp.pointer);
		return *this;
		// Ciclo para copiar cada valor del arreglo pointer
	}
	Foo(Foo&& temp) {}
	//R value modificable
	Foo& operator = (Foo&& temp) {
		cout << "move assignment operator" << endl;
		std::swap(value, temp.value);
		std::swap(pointer, temp.pointer);
	}
};

int main(int argc, char const *argv[])
{
	// el keyword explicit bloquea listas de inicializacion y por parameters

	// inicializacion directa
	Foo a(5);
	Foo b;
	b = a;
	b = Foo(10);


	// param inicialization
	// Foo b = {5};
	// param-list inicialization
	// Foo c = {5, 6, 7};
	return 0;
}