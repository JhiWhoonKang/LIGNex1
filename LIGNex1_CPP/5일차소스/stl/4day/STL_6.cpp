
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int i;
	vector<int> data;
	for (i = 0; i < 5; i++) {
		data.push_back(i + 1);
	}

	vector<int>::iterator it;
	for (it = data.begin(); it != data.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
