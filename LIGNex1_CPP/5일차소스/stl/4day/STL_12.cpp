
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int i;
	vector<int> data;
	vector<int> data2(5);
	for (i = 0; i < 10; i++) {
		data.push_back(i + 1);
	}

	copy(&data[2], &data[7], &data2[0]);

	vector<int>::iterator it;
	for (it = data2.begin(); it != data2.end(); it++) {
		cout << *it << ", ";
	}

	return 0;
}
