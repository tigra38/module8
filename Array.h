#pragma once
#include <exception>

template <typename T>  class Array {

private:
    int m_length;			// Размер массива
    T* m_data{};			// Указатель на массив

public:
    Array(int length);
    virtual ~Array();
    Array(Array& _arr);
    Array& operator=(Array& _arr);
    void set(int i, T val);
    T get(int i);
    int getSize();
    void getArray();
    void erase();
    void remove(int index);
};