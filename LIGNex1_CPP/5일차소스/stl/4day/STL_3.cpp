

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int i;
	vector<int> data;

	for (i = 0; i < 3; i++) {
		data.push_back(i + 1);
	}

	for (i = 0; i < data.size(); i++) {
		cout << "data[" << i << "]=" << data[i] << endl;
	}

	data.clear();
	if (data.empty()) {
		cout << "벡터가 비었다." << endl;
	}
	return 0;
}
