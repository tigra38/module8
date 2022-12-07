#include <iostream>
#include "Array.cpp"

using namespace std;

int main()
{

    setlocale(LC_ALL, "");
    try {
        Array<string> a(10);
        for (auto i = 0; i < a.getSize(); i++)
            a.set(i, "123");

        cout << "������ a (���-�� ���������: " << a.getSize() << ")." << endl;
        a.getArray();

        cout << "������� 5-�� �������:" << endl;
        a.remove(5);
        cout << "������ a (���-�� ���������: " << a.getSize() << ")." << endl;
        a.getArray();

        Array<string> b(a);
        cout << "������ b (���-�� ���������: " << b.getSize() << ")." << endl;
        b.getArray();

        Array<string> c(35);
        c = b;
        cout << "������ c (���-�� ���������: " << c.getSize() << ")." << endl;
        c.getArray();

        cout << "������� ������ c:" << endl;
        c.erase();
        cout << "������ c (���-�� ���������: " << c.getSize() << ")." << endl;
        //c.getArray(); //������� ����������
    }

    catch (exception& e)
    {
        cout << e.what();
    }

    

}