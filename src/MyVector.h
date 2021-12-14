//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_MYVECTOR_H
#define LAB4_DATA_DELETE_MYVECTOR_H


#include <memory>
#include <iostream>

/**
 * @brief Класс итертарор для шаблонного класса MyVector
 *
 *
 *
 * @param
 * @param m_curr указатель на текущий элемнт
 * @param operator != () оператор сравнения
 * @param operator == () оператор сравнения
 * @param operator * () оператор разыменовывания
 *
 * @return Program exit status
 */
template <class T>
class MyVectorIt {

private:

    T * m_curr;

public:

    MyVectorIt() : m_curr(nullptr){}

    explicit MyVectorIt(T * ptr) : m_curr(ptr) {}

    MyVectorIt(const MyVectorIt & it) : m_curr(it.m_curr) {}

    bool operator != (const MyVectorIt & it) const {
        return m_curr != it.m_curr;
    }

    bool operator == (const MyVectorIt & it) const {
        return m_curr == it.m_curr;
    }

    T & operator * () {
        return *m_curr;
    }
    T * operator -> () {
        return m_curr;
    }

    MyVectorIt & operator ++ () {
        ++m_curr;
        return *this;
    }

    MyVectorIt *operator ++ (int) {
        ++(*this);
        return this;
    }
};

template <class T>
class MyVector {

    friend class MyVectorIt<T>;

private:

    size_t m_size = 0;
    size_t m_curr = 0;
    T *m_table;

public:
    MyVector() : m_size(1)
    {
        m_table = new T[1];
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
        if (this != &other)
        {
            delete[] m_table;
            m_size = other.m_size;
            m_curr = other.m_curr;
            m_table = new T[m_size];
            for (int i = 0; i < m_curr; ++i)
                m_table[i] = other.m_table[i];
        }
        return *this;
    }

    MyVector & operator = (MyVector && other) noexcept
    {
        if (this != &other)
        {
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

    T &operator [] (const int n)
    {
        return m_table[n];
    }

    const T & operator [] (const int n) const
    {
        return m_table[n];
    }

    void push_back(T item) {
        if (m_curr == m_size) {
            T * old = m_table;
            m_size++;
            m_table = new T[m_size];
            for (int j = 0; j < m_curr; j++)
                m_table[j] = old[j];
            delete [] old;
        }
        m_table[m_curr++] =  item;
    }

    T &operator [] (const T item)
    {
        int i = find(item);

        if (i < 0)
        {
            if (m_curr >= m_size)
            {
                T *tmp = m_table;
                m_table = new T[++m_size];

                for (int j = 0; j < m_curr; j++)
                    m_table[j] = tmp[j];

                delete[] tmp;
            }
            return m_table[m_curr++];
        }

        delete m_table[i];
        return m_table[i];
    }

    const T & operator [] (const T item) const
    {
        int i = find(item);

        if (i < 0)
            throw std::logic_error("Illegal index");

        return m_table[i];
    }

    int find(int ind) const
    {
        for (int i = 0; i < m_curr; i++)
            if (typeid(item).name() == typeid(m_table[i]).name())
                return i;

        return -1;
    }

    void erase(T item)
    {
        int i = find(item);

        if (i < 0)
            throw std::logic_error("Illegal index");

        for (; i < m_curr; i++)
            m_table[i] = m_table[i + 1];

        m_curr--;
    }

    //typedef class MyVectorIt<T> Iterator;

    MyVectorIt<T> begin()
    {
        return MyVectorIt(this->m_table);
    }

    MyVectorIt<T> end()
    {
        return MyVectorIt(this->m_table + m_curr);
    }
};

#endif //LAB4_DATA_DELETE_MYVECTOR_H
