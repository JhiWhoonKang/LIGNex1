
#include <iostream> 
#include <fstream>
#include <string>

int main()
{
    using namespace std;
    string filename;

    cout << "�� ���ϸ�: ";
    cin >> filename;

// �� ������ ���� ��� ��Ʈ�� ��ü�� fout�̶�� �̸����� �����Ѵ�
    ofstream fout(filename);

    fout << "��� ��ȣ ���⿡ �����Ͻʽÿ�.\n";        	// ���Ͽ� ����Ѵ�
    cout << "��� ��ȣ�� �Է��Ͻʽÿ�: ";   		// ȭ�鿡 ����Ѵ�
    float secret;
    cin >> secret;
    fout << "������ ��� ��ȣ�� " << secret << "�Դϴ�.\n";
    fout.close();           // ������ �ݴ´�

// �� ������ ���� �Է� ��Ʈ�� ��ü�� fin�̶�� �̸����� �����Ѵ�
    ifstream fin(filename);
    cout << filename << " ������ ������ ������ �����ϴ�:\n";
    char ch;
    while (fin.get(ch))     // ���Ϸκ��� �� ���ڸ� �д´�
        cout << ch;         // �� ���ڸ� ȭ�鿡 ����Ѵ�
    cout << "���α׷��� �����մϴ�.\n";
    fin.close();
    return 0; 
}
