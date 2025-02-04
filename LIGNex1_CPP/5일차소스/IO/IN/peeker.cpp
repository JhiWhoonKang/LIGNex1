
#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

// # 문자까지 입력을 읽고 에코한다
    char ch;

    while(cin.get(ch))          // EOF에서 종료한다
    {
        if (ch != '#')
            cout << ch;
        else
        {
            cin.putback(ch);    // # 문자를 입력 스트림에 되삽입한다
            break;
        }
    }

    if (!cin.eof())
    {
        cin.get(ch);
        cout << endl << ch << "은 다음 입력 문자입니다.\n";
    }
    else
    {
        cout << "파일 끝에 도달했습니다.\n";
        std::exit(0);
    }

    while(cin.peek() != '#')    // 미리 엿보기
    {
        cin.get(ch);
        cout << ch;
    }
    if (!cin.eof())
    {
        cin.get(ch);
        cout << endl << ch << "은 다음 입력 문자입니다.\n";
    }
    else
        cout << "파일 끝에 도달했습니다.\n";

    return 0; 
}
