

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {

	map<string, int> data;
	data.insert(make_pair("aaa", 12));
	data.insert(make_pair("bbb", 22));
	data.insert(make_pair("ccc", 32));

	map<string, int>::iterator it;

	for (it = data.begin(); it != data.end(); it++) {
		cout << it->first << " : " << it->second << endl;
	}


	return 0;
}
