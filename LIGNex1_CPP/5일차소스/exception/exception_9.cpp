

#include <iostream>
#include <string.h>
using namespace std;

class MyException {
protected:
	char *msg;

public:
	MyException(const char *str) {
		int size = strlen(str);
		msg = new char[size + 1];
		strcpy(msg, str);
	}

	~MyException() {
		delete[] msg;
	}

	void printMsg() {
		cout << msg << endl;
	}
};

class DevidedException: public MyException {
private:
	int num;
public:
	DevidedException(int n, const char *str) :
			MyException(str) {
		num = n;
	}
	void printNum() {
		printMsg();
		cout << num << " : 으로 나눌수 없음" << endl;
	}
};

class IndexException: public MyException {
private:
	int idx;
public:
	IndexException(int i, const char *str) :
			MyException(str) {
		idx = i;
	}
	void printIdx() {
		printMsg();
		cout << idx << " : 잘못된 인덱스" << endl;
	}
};

int main() {

	int x, y, size = 3, i;
	int a[size];
	cout << "1 ~ 3중 하나를 입력하라" << endl;
	cin >> x;
	try {
		switch (x) {
		case 1:
			cout << "1을 입력하라" << endl;
			cin >> y;
			if (y != 1) {
				throw MyException("잘못된 입력값");
			}
			break;
		case 2:
			for (i = 0; i < size; i++) {
				a[i] = i + 1;
			}
			for (i = 0; i <= size; i++) {
				if (i < size) {
					cout << "a[" << i << "]=" << a[i] << endl;
				} else {
					throw IndexException(i, "배열 인덱스 에러");
				}
			}
			break;
		case 3:
			cout << "나눌 숫자를 입력하라, 0은 안됨" << endl;
			cin >> y;
			if (y != 0) {
				i = 3 / y;
				cout << "3/" << y << " = " << i << endl;
			} else {
				throw DevidedException(y, "0으로 나눌수 없다. 불능");
			}
			break;
		default:
			cout << "잘못된 입력값" << endl;
		}
	} catch (DevidedException e) {
		e.printNum();
	} catch (IndexException e) {
		e.printIdx();
	} catch (MyException e) {
		e.printMsg();
	} catch (...) {
		cout << "기타 예외 발생" << endl;
	}
	cout << "프로그램 종료" << endl;
	return 0;
}
