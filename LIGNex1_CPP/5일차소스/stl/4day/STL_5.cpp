

#include <iostream>
#include <list>
using namespace std;

int main() {
	int i;
	list<int> data;

	for (i = 0; i < 3; i++) {
		data.push_back(i + 1);
	}

	for (i = 3; i < 6; i++) {
		data.push_front(i + 1);
	}

	list<int>::iterator it;
	for (it = data.begin(); it != data.end(); it++) {
		cout << *it << ", ";
	}

	return 0;
}
