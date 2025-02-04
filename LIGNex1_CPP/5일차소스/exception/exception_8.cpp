

#include <iostream>
#include <string.h>
using namespace std;

class MyException {
private:
	char *msg;

public:
	MyException(const char *str) {
		int size = strlen(str);
		msg = new char[size + 1];
		strcpy(msg, str);
	}

	~MyException() {
		delete msg;
	}

	void printMsg() {
		cout << msg << endl;
	}
};

int main() {

	int x;
	cout << "1 ~ 3중 하나를 입력하라" << endl;
	cin >> x;
	try {
		switch (x) {
		case 1:
			throw MyException("1번 에러");
			break;
		case 2:
			throw MyException("2번 에러");
			break;
		case 3:
			throw MyException("3번 에러");
			break;
		default:
			cout << "잘못된 입력값" << endl;
		}
	} catch (MyException e) {
		e.printMsg();
	} catch (...) {
		cout << "기타 예외 발생" << endl;
	}

	return 0;
}
