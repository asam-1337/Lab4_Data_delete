//
// Created by chicha-man on 10.12.2021.
//

#include "GraphicOperative.h"

void GraphicOperative::fire(Creature * creature) {
    dynamic_cast<Operative *>(m_creature)->fire(creature);
}

void GraphicOperative::reload() {
    dynamic_cast<Operative *>(m_creature)->reload();
}

void GraphicOperative::selectWeapon(int n) {
dynamic_cast<Operative*>(m_creature)->selectWeapon(n);
}
