
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cout << "두 개의 숫자를 입력하라" << endl;
	cin >> a >> b;
	try {
		if (b == 0) {
			throw -1;
		}
		c = a / b;
		cout << a << "/" << b << "=" << c << endl;
	} catch (int) {
		cout << "0으로 나눌수 없습니다. 계산취소." << endl;
	}

	return 0;
}
