//
// Created by chicha-man on 13.11.2021.
//

#include "Specifications.h"

Specifications::Specifications(int max_hlth, int curr_points, int max_points,
               int walk_cost, int accuracy, int view_rad, int max_weight)
               : curr_health(max_hlth), max_health(max_hlth), curr_points(curr_points), max_points(max_points),
               walk_cost(walk_cost), accuracy(accuracy), view_rad(view_rad), max_weight(max_weight) {
}

Specifications::Specifications(Specifications & src) {
    this->curr_health = src.curr_health;
    this->max_health = src.max_health;
    this->curr_points = src.curr_points;
    this->max_points = src.max_points;
    this->walk_cost = src.walk_cost;
    this->accuracy = src.accuracy;
    this->view_rad = src.view_rad;
    this->max_weight = src.max_weight;
}