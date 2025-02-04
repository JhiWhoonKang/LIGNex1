

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int i;
	vector<int> data(5);

	for (i = 0; i < 5; i++) {
		data[i] = i + 1;
	}

	for (i = 0; i < 5; i++) {
		cout << "data[" << i << "]=" << data[i] << endl;
	}
	cout << endl;

	vector<double> data2(3);

	for (i = 0; i < 3; i++) {
		data2[i] = (i + 1) * 1.2;
	}

	for (i = 0; i < 3; i++) {
		cout << "data2[" << i << "]=" << data2[i] << endl;
	}
	cout << endl;

	vector<char*> strs(3);

	strs[0] = "aaa";
	strs[1] = "bbb";
	strs[2] = "ccc";

	for (i = 0; i < 3; i++) {
		cout << "strs[" << i << "]=" << strs[i] << endl;
	}

	return 0;
}
