//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_MYVECTOR_H
#define LAB4_DATA_DELETE_MYVECTOR_H

#include <map>
#include <vector>
#include "Object.h"
#include "Weapon.h"
#include "Aidkit.h"
#include "AmmoContainer.h"

template <class T>
class MyVectorIt {

private:

    T *m_curr;

public:

    MyVectorIt() : m_curr(nullptr){}

    explicit MyVectorIt(T *it) : m_curr(it){}

    bool operator != (const MyVectorIt & it) const {
        return m_curr != it.m_curr;
    }

    bool operator == (const MyVectorIt & it) const {
        return m_curr == it.m_curr;
    }

    T operator * () {
        if (m_curr)
            return m_curr;
        throw std::logic_error("illegal value for Iterator");
    }

    MyVectorIt operator ++ () {
        ++m_curr;
        return *this;
    }

    MyVectorIt operator ++ (int) {
        MyVectorIt res;
        res.m_curr = m_curr;
        ++m_curr;
        return res;
    }
};

template <class T>
class MyVector {

private:

    int m_size = 0;
    int m_curr = 0;
    T *m_table;

public:

    MyVector()
    {
        m_table = new T[5];
    }

    explicit MyVector(int n)
    {
        m_table = new T[n];
    }

    MyVector(const MyVector & other) : m_size(other.m_size), m_curr(other.m_curr), m_table(new T[other.m_size])
    {
        for (int i = 0; i < m_curr; i++)
            m_table[i] = other.m_table[i];
    }

    MyVector(MyVector && other) noexcept : m_size(other.m_size), m_curr(other.m_curr), m_table(other.m_table)
    {
        other.m_table = nullptr;
    }

    ~MyVector()
    {
        delete[] m_table;
    }

    MyVector & operator = (const MyVector & other)
    {
        if (this != &other){
            delete[] m_table;
            m_size = other.m_size;
            m_curr = other.m_curr;
            m_table = new T*[m_size];
            for (int i = 0; i < m_curr; ++i)
                m_table[i] = other.m_table[i];
        }
        return *this;
    }

    MyVector & operator = (MyVector && other) noexcept
    {
        if (this != &other){
            int tmp = m_curr;
            m_curr = other.m_curr;
            other.m_curr = tmp;
            tmp = m_size;
            m_size = other.m_size;
            other.m_size = tmp;
            T *tarr = m_table;
            m_table = other.m_table;
            other.m_table = tarr;
        }
        return *this;
    }

    T &operator [] (int n)
    {
        return m_table[n];
    }

    T operator [] (int n) const
    {
        return m_table[n];
    }

    friend class MyVectorIt<T>;
    typedef class MyVectorIt<T> Iterator;

    Iterator begin()
    {
        return MyVector::Iterator(m_table);
    }
    Iterator end()
    {
        return MyVector::Iterator(m_table + m_curr);
    }
};

#endif //LAB4_DATA_DELETE_MYVECTOR_H
