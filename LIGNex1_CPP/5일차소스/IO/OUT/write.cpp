
#include <iostream>
#include <cstring>  // 또는 string.h

int main()
{
    using std::cout;
    using std::endl;
    const char * state1 = "Florida";
    const char * state2 = "Kansas";
    const char * state3 = "Euphoria";
    int len = std::strlen(state2);
    cout << "루프 인덱스 증가:\n";
    int i;
    for (i = 1; i <= len; i++)
    {
        cout.write(state2,i);
        cout << endl;
    }

// 연이어 출력한다
    cout << "루프 인덱스 감소:\n";
    for (i = len; i > 0; i--)
        cout.write(state2,i) << endl;

// 문자열 길이를 초과한다
    cout << "문자열 길이 초과:\n";
    cout.write(state2, len + 5) << endl;
    return 0; 
}
