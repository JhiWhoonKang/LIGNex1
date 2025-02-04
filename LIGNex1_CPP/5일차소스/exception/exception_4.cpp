

#include <iostream>
using namespace std;

void func() {
	cout << "func(): throw 전" << endl;
	throw "error";
	cout << "func(): throw 후" << endl;
}

int main() {

	try {
		cout << "func() 호출 전" << endl;
		func();
		cout << "func() 호출 후" << endl;
	} catch (const char *e) {
		cout << e << endl;
	}

	return 0;
}
