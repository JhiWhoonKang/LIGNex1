

#include <iostream>
using namespace std;

void func3() {
	cout << "func3:func3() throw 전" << endl;
	throw "error";
	cout << "func3:func3() throw 후" << endl;
}

void func2() {
	cout << "func2:func3() 호출 전" << endl;
	func3();
	cout << "func2:func3() 호출 후" << endl;
}

void func1() {
	cout << "func1:func2() 호출 전" << endl;
	func2();
	cout << "func1:func2() 호출 후" << endl;
}

int main() {

	try {
		cout << "main:func1() 호출 전" << endl;
		func1();
		cout << "main:func1() 호출 후" << endl;
	} catch (const char *e) {
		cout << "catch:" << e << endl;
	}

	return 0;
}
