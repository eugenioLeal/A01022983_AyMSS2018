#include <iostream>
using namespace std;

class Foo {
public:
	int* pointer;
	explicit Foo(int i = 0) : pointer(new int (i)) {
		cout << "constructor def/para" << endl;
	}
	Foo(const Foo& original) {
		pointer = new int(10);
		cout << "copy const" << endl;
	}
	Foo(Foo&& temporal) {
		swap(this->pointer, temporal.pointer);
		//temporal.pointer = nullptr;
		cout << "move const" << endl;
	}
	~Foo() {
		delete pointer;
		cout << "destructor" << endl;
	}
};

Foo returnFoo(Foo a) {
	return a;
}

int main(int argc, char const *argv[])
{
	Foo a;
	// Testing
	cout << *(a.pointer) << endl;
	// Calling copy constructor
	Foo b(a);
	Foo c(returnFoo(a));
	cout << *(c.pointer) << endl;
	return 0;
}