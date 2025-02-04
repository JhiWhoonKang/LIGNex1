

#include <iostream>
using namespace std;

int main() {

	int x;
	cout << "1 ~ 3중 하나를 입력하라" << endl;
	cin >> x;
	try {
		switch (x) {
		case 1:
			throw -1;
			break;
		case 2:
			throw "error message";
			break;
		case 3:
			throw 2.5;
			break;
		default:
			cout << "잘못된 입력값" << endl;
		}
	} catch (int e) {
		cout << "error int code:" << e << endl;
	} catch (const char *e) {
		cout << e << endl;
	} catch (float e) {
		cout << "error float code:" << e << endl;
	} catch (...) {
		cout << "기타 예외 발생" << endl;
	}

	return 0;
}
