
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cout << "�� ���� ���ڸ� �Է��϶�" << endl;
	cin >> a >> b;
	try {
		if (b == 0) {
			throw -1;
		}
		c = a / b;
		cout << a << "/" << b << "=" << c << endl;
	} catch (int) {
		cout << "0���� ������ �����ϴ�. ������." << endl;
	}

	return 0;
}
