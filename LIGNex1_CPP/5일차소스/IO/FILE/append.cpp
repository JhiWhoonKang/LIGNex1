#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>      // (또는 stdlib.h) exit()를 사용하기 위해

const char * file = "guests.txt";
int main()
{
    using namespace std;
    char ch;

// 초기 내용을 화면에 표시한다
    ifstream fin;
    fin.open(file);

    if (fin.is_open())
    {
        cout << file << "파일의 현재 내용은 다음과 같습니다:\n";
        while (fin.get(ch))
            cout << ch;
        fin.close();
    }

// 새로운 손님 이름들을 추가한다
    ofstream fout(file, ios_base::out | ios_base::app);
    if (!fout.is_open())
    {
        cerr << "출력을 위해 " << file << " 파일을 열 수 없습니다.\n";
        exit(EXIT_FAILURE);
    }

    cout << "새로운 손님 이름들을 입력하십시오(끝내려면 빈 줄 입력):\n";
    string name;
    while (getline(cin,name) && name.size() > 0)
    {
          fout << name << endl;
    }
    fout.close();

// 개정된 파일을 화면에 표시한다
    fin.clear();    // 어떤 컴파일러는 이것을 요구하지 않는다
    fin.open(file);
    if (fin.is_open())
    {
        cout << file << " 파일의 개정된 내용은 다음과 같습니다:\n";
        while (fin.get(ch))
            cout << ch;
        fin.close();
   }
    cout << "프로그램을 종료합니다.\n";
    return 0; 
}
