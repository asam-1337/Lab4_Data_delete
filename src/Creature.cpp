//
// Created by chicha-man on 13.11.2021.
//

#include "Creature.h"

#include <utility>

Creature::Creature(std::string name, int max_health, int max_points,
               int walk_cost, int accuracy, int view_rad, int max_weight)
               : name(std::move(name)), curr_health(max_health), max_health(max_health), curr_points(max_points),
               max_points(max_points),walk_cost(walk_cost), accuracy(accuracy),
               view_rad(view_rad), max_weight(max_weight) {}

int Creature::getWeight() const {
    return curr_weight;
}

void Creature::walk() {
    curr_points -= walk_cost;
}

void Creature::getHit(int damage) {
    if (curr_health - damage <= 0)
        throw std::logic_error("You are die");
    curr_health -= damage;
}
