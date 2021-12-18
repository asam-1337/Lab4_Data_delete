//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_MYVECTOR_H
#define LAB4_DATA_DELETE_MYVECTOR_H


#include <memory>

/**
 * @brief Структура
 *
 * @param first индекс элемента
 * @param second данные
 *
 */

template<class IND, class DATA>
struct Pair {
    IND first;
    DATA second;
};
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
 * @param operator ++ () постфиксный префиксный инкреммент
 * @param operator ++ (int) постфиксный постфиксный инкреммент
 *
 */
template <class IND, class DATA>
class MyVectorIt {

private:

    Pair<IND, DATA> * m_curr;

public:

    MyVectorIt() : m_curr(nullptr){}

    explicit MyVectorIt(Pair<IND, DATA> * ptr) : m_curr(ptr) {}

    MyVectorIt(const MyVectorIt & it) : m_curr(it.m_curr) {}

    bool operator != (const MyVectorIt & it) const {
        return m_curr != it.m_curr;
    }

    bool operator == (const MyVectorIt & it) const {
        return m_curr == it.m_curr;
    }

    Pair<IND, DATA> & operator * () {
        return *m_curr;
    }

    Pair<IND, DATA> * operator -> () {
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

/**
 * @brief Шаблонный класс MyVector, который является вектором
 *
 *
 *
 * @param
 * @param m_size полный размер вектора
 * @param m_curr текущий размер вектора
 * @param m_table указатель на адресс вектора
 * @param operator = (const MyVector & other) копирующий оператор присваивания
 * @param MyVector & operator = (MyVector && other) перемещающий оператор присваивания
 * @param operator ++ (int) постфиксный постфиксный инкреммент
 * @param find(int ind) функция поиска по индексу
 *
 */

template <class IND, class DATA>
class MyVector {

    friend class MyVectorIt<IND, DATA>;

private:

    size_t m_size = 0;
    size_t m_curr = 0;
    Pair<IND, DATA> *m_table;

public:
    MyVector() : m_size(1)
    {
        m_table = new Pair<IND, DATA>[1];
    }

    MyVector(const MyVector & other) : m_size(other.m_size), m_curr(other.m_curr), m_table(new Pair<IND, DATA>[other.m_size])
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
            m_table = new Pair<IND, DATA>[m_size];
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

            Pair<IND, DATA> *tarr = m_table;
            m_table = other.m_table;
            other.m_table = tarr;
        }
        return *this;
    }

    Pair<IND, DATA> &operator [] (const int n)
    {
        return m_table[n];
    }

    const Pair<IND, DATA> & operator [] (const int n) const
    {
        return m_table[n];
    }

    void push_back(IND ind, DATA item) {
        if (m_curr == m_size) {
            Pair<IND, DATA> * old = m_table;
            m_size++;
            m_table = new Pair<IND, DATA>[m_size];
            for (int j = 0; j < m_curr; j++)
                m_table[j] = old[j];
            delete [] old;
        }

        m_table[m_curr].first = ind;
        m_table[m_curr].second = item;
        m_curr++;
    }

    Pair<IND, DATA> &operator [] (const Pair<IND, DATA> & item)
    {
        int i = find(item);

        if (i < 0)
        {
            if (m_curr >= m_size)
            {
                Pair<IND, DATA> *tmp = m_table;
                m_table = new Pair<IND, DATA>[++m_size];

                for (int j = 0; j < m_curr; j++)
                    m_table[j] = tmp[j];

                delete[] tmp;
            }
            return m_table[m_curr++];
        }

        delete m_table[i];
        return m_table[i];
    }

    const Pair<IND, DATA> & operator [] (const Pair<IND, DATA> item) const
    {
        int i = find(item);

        if (i < 0)
            throw std::logic_error("Illegal index");

        return m_table[i];
    }

    int find(int ind) const
    {
        for (int i = 0; i < m_curr; i++)
            if (m_table[i].first == ind)
                return i;

        return -1;
    }

    void erase(int ind)
    {
        int i = find(ind);

        if (i < 0)
            throw std::logic_error("Illegal index");

        for (; i < m_curr; i++)
            m_table[i] = m_table[i + 1];

        m_curr--;
    }

    typedef class MyVectorIt<IND, DATA> Iterator;

    Iterator begin()
    {
        return Iterator(this->m_table);
    }

    Iterator end()
    {
        return Iterator(this->m_table + m_curr);
    }
};


#endif //LAB4_DATA_DELETE_MYVECTOR_H
