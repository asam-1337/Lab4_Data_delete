//
// Created by chicha-man on 13.11.2021.
//

#include "Creature.h"

#include <utility>

Creature::Creature(std::string name, int max_health, int curr_points, int max_points,
               int walk_cost, int accuracy, int view_rad, int curr_weight, int max_weight)
               : name(std::move(name)), curr_health(max_health), max_health(max_health), curr_points(curr_points),
               max_points(max_points),walk_cost(walk_cost), accuracy(accuracy),
               view_rad(view_rad), curr_weight(curr_weight), max_weight(max_weight) {}

Creature::Creature(Creature & src) {
    this->curr_health = src.curr_health;
    this->max_health = src.max_health;
    this->curr_points = src.curr_points;
    this->max_points = src.max_points;
    this->walk_cost = src.walk_cost;
    this->accuracy = src.accuracy;
    this->view_rad = src.view_rad;
    this->curr_weight = src.curr_weight;
    this->max_weight = src.max_weight;
}