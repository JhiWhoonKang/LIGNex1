

#include <iostream>
#include <vector>
using namespace std;

class Member {
private:
	char *name;
	int age;

public:
	Member() {
		name = "no name";
		age = 0;
	}

	Member(char *name, int age) {
		this->name = name;
		this->age = age;
	}

	void printMember() {
		cout << "name:" << name << ", age:" << age << endl;
	}
};

int main() {
	int i;
	vector<Member> data(3);

	data[0] = Member("aaa", 12);
	data[1] = Member("bbb", 22);
	data[2] = Member("ccc", 32);

	for (i = 0; i < 3; i++) {
		data[i].printMember();
	}

	return 0;
}
