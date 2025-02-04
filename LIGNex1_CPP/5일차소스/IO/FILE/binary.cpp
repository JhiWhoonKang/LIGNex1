
#include <iostream> 
#include <fstream>
#include <iomanip>
#include <cstdlib>  

inline void eatline() { while (std::cin.get() != '\n') continue; }
struct planet
{
    char name[20];      // 행성의 이름
    double population;  // 행성의 인구
    double g;           // 행성의 중력가속도
};

const char * file = "planets.dat";

int main()
{
    using namespace std;
    planet pl;
    cout << fixed << right;

// 초기의 내용을 화면에 표시한다
    ifstream fin;
    fin.open(file, ios_base::in |ios_base::binary);  // 2진 파일
    
    if (fin.is_open())
    {
    cout << file << " 파일의 현재 내용은 다음과 같습니다:\n";
    while (fin.read((char *) &pl, sizeof pl))
    {
        cout << setw(20) << pl.name << ": "
             << setprecision(0) << setw(12) << pl.population
             << setprecision(2) << setw(6) << pl.g << endl;
    }    
    fin.close();
    }

// 새로운 데이터를 추가한다
    ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
    
    if (!fout.is_open())
    {
        cerr << "출력을 위해 " << file << " 파일을 열 수 없습니다.\n";
        exit(EXIT_FAILURE);
    }

    cout << "행성의 이름을 입력하십시오(끝내려면 빈 줄 입력):\n";
    cin.get(pl.name, 20);
    while (pl.name[0] != '\0')
    {
        eatline();
        cout << "행성의 인구를 입력하십시오: ";
        cin >> pl.population;
        cout << "행성의 중력가속도를 입력하십시오: ";
        cin >> pl.g;
        eatline();
        fout.write((char *) &pl, sizeof pl);
        cout << "행성의 이름을 입력하십시오(끝내려면 빈 줄 입력):\n";
        cin.get(pl.name, 20);
    }
    fout.close();

// 개정된 파일을 화면에 표시한다
    fin.clear();    
    fin.open(file, ios_base::in | ios_base::binary);
    if (fin.is_open())
    {
        cout << file << " 파일의 개정된 내용은 다음과 같습니다:\n";
        while (fin.read((char *) &pl, sizeof pl))
        {
            cout << setw(20) << pl.name << ": "
                 << setprecision(0) << setw(12) << pl.population
                 << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }
    cout << "프로그램을 종료합니다.\n";
    return 0; 
}
