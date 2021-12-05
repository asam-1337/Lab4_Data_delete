//
// Created by chicha-man on 13.11.2021.
//

#include "Inventory.h"

T* Inventory::getItem(int num) const {
    if (m_table[num]->getType() == NOT)
        throw std::logic_error("You don't have such item");
    return m_table[num];
}

void Inventory::addItem(T* item) {
    switch (item->getType()) {
        case WEAPON:
            switch (item->getName()) {
                case M4:
                    m_table[0] = new Weapon(M4, 10, 5, 0, 30, 10);
                    break;
                case AK:
                    m_table[1] = new Weapon(AK, 10, 5, 0, 30, 10);
                    break;
            }
        case AIDKIT:
            m_table[2] = new Aidkit();
            break;
        case AMMO:
            switch (item->getName()) {
                case M4:
                    m_table[3] = new Ammo_container(M4, 90);
                    break;
                case AK:
                    m_table[4] = new Ammo_container(AK, 60);
            }
    }
}

Inventory<T>::~Inventory() {
    delete[] m_table;
}

Inventory<T>::Inventory(Inventory &&) noexcept {

}

Inventory::Iterator Inventory::begin() {
    return Inventory::Iterator(m_table);
}

Inventory::Iterator Inventory::end() {
    return Inventory::Iterator(m_table + m_curr);
}

Inventory::Inventory(const Inventory & src) : m_curr(src.m_curr), m_table(new T*[src.m_curr]) {
    for (int i = 0; i < m_curr; i++)
        m_table[i] = src.m_table[i];

}

Inventory & Inventory::operator = (const Inventory & src) {
    if (this != &src){
        delete[] m_table;
        m_curr = src.m_curr;
        m_table = new T*[5];
        for (int i = 0; i < m_curr; ++i)
            m_table[i] = src.m_table[i];
    }
    return *this;
}

Inventory &Inventory::operator=(Inventory && src)  noexcept {
    if (this != &src){
        int tmp = m_curr;
        m_curr = src.m_curr;
        src.m_curr = tmp;
        //tmp = cnt;
        //cnt = a.cnt;
        //a.cnt = tmp;
        T* * tarr = m_table;
        m_table = src.m_table;
        src.m_table = tarr;
    }
    return *this;
}

bool InventoryIt::operator!=(const InventoryIt & it) const {
    return m_curr != it.m_curr;
}

bool InventoryIt::operator==(const InventoryIt & it) const {
    return m_curr == it.m_curr;
}

T InventoryIt::operator*() {
    if (m_curr)
        return m_curr;
    throw std::logic_error("illegal value for Iterator");
}

InventoryIt &InventoryIt::operator++() {
    ++m_curr;
    return *this;
}

InventoryIt InventoryIt::operator++(int) {
    InventoryIt res;
    res.m_curr = m_curr;
    ++m_curr;
    return res;
}
