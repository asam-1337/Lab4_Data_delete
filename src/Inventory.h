//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_INVENTORY_H
#define LAB4_DATA_DELETE_INVENTORY_H

#include <map>
#include <vector>
#include "Object.h"
#include "Weapon.h"
#include "Aidkit.h"
#include "AmmoContainer.h"

template <class T>
class InventoryIt {

private:

    T *m_curr;

public:

    InventoryIt() : m_curr(nullptr){}

    explicit InventoryIt(T *it) : m_curr(it){}

    bool operator != (const InventoryIt & it) const {
        return m_curr != it.m_curr;
    }

    bool operator == (const InventoryIt & it) const {
        return m_curr == it.m_curr;
    }

    T operator * () {
        if (m_curr)
            return m_curr;
        throw std::logic_error("illegal value for Iterator");
    }

    InventoryIt operator ++ () {
        ++m_curr;
        return *this;
    }

    InventoryIt operator ++ (int) {
        InventoryIt res;
        res.m_curr = m_curr;
        ++m_curr;
        return res;
    }
};

template <class T>
class Inventory {

private:

    int m_size = 0;
    int m_curr = 0;
    T *m_table;

public:

    Inventory()
    {
        m_table = new T[5];
    }

    explicit Inventory(int n)
    {
        m_table = new T[n];
    }

    Inventory(const Inventory & other) : m_size(other.m_size), m_curr(other.m_curr), m_table(new T[other.m_size])
    {
        for (int i = 0; i < m_curr; i++)
            m_table[i] = other.m_table[i];
    }

    Inventory(Inventory && other) noexcept : m_size(other.m_size), m_curr(other.m_curr), m_table(other.m_table)
    {
        other.m_table = nullptr;
    }

    ~Inventory()
    {
        delete[] m_table;
    }

    Inventory & operator = (const Inventory & other)
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

    Inventory & operator = (Inventory && other) noexcept
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

    friend class InventoryIt<T>;
    typedef class InventoryIt<T> Iterator;

    Iterator begin()
    {
        return Inventory::Iterator(m_table);
    }
    Iterator end()
    {
        return Inventory::Iterator(m_table + m_curr);
    }
};

#endif //LAB4_DATA_DELETE_INVENTORY_H
