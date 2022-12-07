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

        cout << "Массив a (кол-во элементов: " << a.getSize() << ")." << endl;
        a.getArray();

        cout << "Удаляем 5-ый элемент:" << endl;
        a.remove(5);
        cout << "Массив a (кол-во элементов: " << a.getSize() << ")." << endl;
        a.getArray();

        Array<string> b(a);
        cout << "Массив b (кол-во элементов: " << b.getSize() << ")." << endl;
        b.getArray();

        Array<string> c(35);
        c = b;
        cout << "Массив c (кол-во элементов: " << c.getSize() << ")." << endl;
        c.getArray();

        cout << "Очищаем массив c:" << endl;
        c.erase();
        cout << "Массив c (кол-во элементов: " << c.getSize() << ")." << endl;
        //c.getArray(); //вызовет исключение
    }

    catch (exception& e)
    {
        cout << e.what();
    }

    

}