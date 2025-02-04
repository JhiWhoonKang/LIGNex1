

#include <iostream>
#include <set>
using namespace std;

int main() {

	set<int> data;
	data.insert(3);
	data.insert(2);
	data.insert(6);
	data.insert(1);

	set<int>::iterator it;
	for (it = data.begin(); it != data.end(); it++) {
		cout << *it << endl;
	}
	return 0;
}
