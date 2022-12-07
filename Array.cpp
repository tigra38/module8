#pragma once
#include <exception>
#include <iostream>
#include "Array.h"

using namespace std;

class bad_range : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad Range!";
    }
};

class bad_length : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Bad Length!";
    }
};

template <typename T> Array <T> ::Array(int length)
{
    m_length = length;
    
    if (length <= 0)
    {
        throw bad_length();
    }
    else
    {
        m_data = new T[m_length];
    }
}

template <typename T> Array<T>::~Array() {
    delete[] m_data;
}

template <typename T> void Array<T>::set(int num, T value) {
    if (num >= 0 && num < m_length) {
        m_data[num] = value;
    }
        
}

template <typename T> T Array<T>::get(int num) {
    if (num < 0 || num >= m_length){
        throw bad_range();
    }
    else return m_data[num];
}

template <typename T> int Array<T>::getSize() {
    return m_length;
}

template <typename T> Array<T>::Array(Array& _arr) {
    m_length = _arr.m_length;
    m_data = new T[_arr.m_length];
    for (size_t i = 0; i < m_length; i++)
        m_data[i] = _arr.m_data[i];
}

template <typename T> Array<T>& Array<T>::operator=(Array& _arr) {
    if (this != &_arr) {
        m_length = _arr.m_length;
        delete[] m_data;
        m_data = new T[m_length];
        for (size_t i = 0; i < m_length; i++) {
            m_data[i] = _arr.m_data[i];
        }
    }
    return *this;
}

template <typename T> void Array<T>::erase()
{
    delete[] m_data;
    m_data = nullptr;
    m_length = 0;
}

template <typename T> void Array<T>::getArray()
{
    for (auto i = 0; i < m_length-1; i++)
    {
        cout << get(i) << "; ";
    }
    cout << get(m_length - 1) << endl << endl;
}

template <typename T> void Array<T>::remove(int index)
{
    if (index < 0 || index >= m_length)
    {
        throw bad_range();
    }

    if (m_length == 1)
    {
        erase();
        return;
    }

    T* data{ new T[m_length - 1] };

    for (auto before = 0; before < index; ++before) {
        data[before] = m_data[before];
    }
        

    for (auto after{ index + 1 }; after < m_length; ++after) {
        data[after - 1] = m_data[after];
    }
        

    delete[] m_data;
    m_data = data;
    --m_length;
}
