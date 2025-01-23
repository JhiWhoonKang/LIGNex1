#include <iostream>
#include <string>
using namespace std;

class Storage {
private:
    int id;
    string name;
    string phone;

public:
    Storage()
    {
        id = -1;
        name = "";
        phone = "";
    }

    int getId() const
    {
        return id;
    }
    string getName() const
    {
        return name;
    }
    string getPhone() const
    {
        return phone;
    }

    void setPhone(string newPhone)
    {
        phone = newPhone;
    }

    void setStorage(int newId, string newName, string newPhone)
    {
        id = newId;
        name = newName;
        phone = newPhone;
    }

    void clearStorage()
    {
        id = -1;
    }

    bool ValidID() const
    {
        return id != -1;
    }

    void printStorage ()const
    {
        cout << "ID: " << id << ", Name: " << name << ", Phone: " << phone << endl;
    }
};

class AddressBook {
private:
    Storage storage[10];
    int cnt;

    int FindID(int id) const
    {
        for (int i = 0; i < 10; ++i)
        {
            if (storage[i].ValidID() && storage[i].getId() == id)
            {
                return i;
            }
        }
        return -1;
    }

public:
    AddressBook()
    {
        cnt = 0;
    }

    void Add(int id, string name, string phone)
    {
        if (cnt >= 10)
        {
            cout << "max " << endl;
            return;
        }

        if (FindID(id) != -1)
        {
            cout << "Invalid ID" << endl;
            return;
        }

        for (int i = 0; i < 10; ++i)
        {
            if (!storage[i].ValidID())
            {
                storage[i].setStorage(id, name, phone);
                ++cnt;
                cout << "Success" << endl;
                return;
            }
        }
    }

    void Search (int id)const
    {
        int index = FindID(id);
        if (index != -1)
        {
            storage[index].printStorage();
        }
        else
        {
            cout << "Not found" << endl;
        }
    }

    void Update(int id, string newPhone)
    {
        int index = FindID(id);
        if (index != -1)
        {
            storage[index].setPhone(newPhone);
            cout << "Updated" << endl;
        }
        else
        {
            cout << "Not found" << endl;
        }
    }

    void Delete(int id)
    {
        int index = FindID(id);
        if (index != -1)
        {
            storage[index].clearStorage();
            --cnt;
            cout << "deleted successfully." << endl;
        }
        else
        {
            cout << "not found." << endl;
        }
    }

    void PrintAll ()const
    {
        if (cnt == 0)
        {
            cout << "empty." << endl;
            return;
        }

        for (int i = 0; i < 10; ++i)
        {
            if (storage[i].ValidID())
            {
                storage[i].printStorage();
            }
        }
    }
};

int main()
{
    AddressBook addressBook;
    int num, id;
    string name, phone;

    while (num != 6)
    {
        cout << "======LIG Nex1 C++ Address Book HW======";
        cout << "\nAddress Book\n";
        cout << "1. Add\n";
        cout << "2. Search\n";
        cout << "3. Update\n";
        cout << "4. Delete\n";
        cout << "5. Print All\n";
        cout << "6. Exit\n";
        cout << "Enter number: ";
        cin >> num;

        switch (num) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin>>name;
                cout << "Enter Phone: ";
                cin>>phone;

                addressBook.Add(id, name, phone);
                break;

            case 2:
                cout << "Search ID: ";
                cin >> id;
                addressBook.Search(id);
                break;

            case 3:
                cout << "New ID: ";
                cin >> id;
                cout << "New Phone: ";
                cin >> phone;
                addressBook.Update(id, phone);
                break;

            case 4:
                cout << "Delete ID: ";
                cin >> id;
                addressBook.Delete(id);
                break;

            case 5:
                addressBook.PrintAll();
                break;

            case 6:
                cout << "bye" << endl;
                break;

            default:
                cout << "?" << endl;
        }
    }

    return 0;
}
