

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int i;
	vector<int> data;
	for (i = 0; i < 10; i++) {
		data.push_back(i + 1);
	}

	vector<int>::iterator it;
	for (it = data.begin(); it != data.end(); it++) {
		cout << *it << ", ";
	}
	cout << endl << "찾고 싶은 값을 입력하라" << endl;

	cin >> i;

	it = find(data.begin(), data.end(), i);

	if (it != data.end()) {
		cout << "찾는 값:" << *it << endl;
	} else {
		cout << "찾는 값이 없다." << endl;
	}
	return 0;
}
