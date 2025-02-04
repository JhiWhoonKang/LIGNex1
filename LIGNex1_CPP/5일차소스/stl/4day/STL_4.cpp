

#include <iostream>
#include <deque>
using namespace std;

int main() {
	int i;
	deque<int> data;

	for (i = 0; i < 3; i++) {
		data.push_back(i + 1);
	}

	for (i = 3; i < 6; i++) {
		data.push_front(i + 1);
	}

	for (i = 0; i < data.size(); i++) {
		cout << "data[" << i << "]=" << data[i] << endl;
	}

	return 0;
}
