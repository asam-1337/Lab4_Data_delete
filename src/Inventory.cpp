//
// Created by chicha-man on 13.11.2021.
//

#include "Inventory.h"

int Inventory::getSize() const
{
    return std::size(table);
}

Item Inventory::getItem(int num) const
{
    auto result = table.find(num);
    if (result == table.end())
        throw std::logic_error("You don't have such item");
    return result->second;
}

void Inventory::addItem()
{
    obj[0] = new Weapon(M4, 10, 5, 0, 30, 10);
}