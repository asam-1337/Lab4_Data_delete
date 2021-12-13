//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_CREATURE_H
#define LAB4_DATA_DELETE_CREATURE_H

#include <string>
#include <iostream>

class Creature {
protected:
    std::string name;
    int curr_health = 0;
    int max_health = 0;
    int curr_points = 0;
    int max_points = 0;
    int walk_cost = 0;
    int accuracy = 0;
    int view_rad = 0;
    int curr_weight = 0;
    int max_weight = 0;
public:
    Creature(std::string name, int max_health, int max_points, int walk_cost, int accuracy, int view_rad, int max_weight);

    [[nodiscard]] virtual int getWeight() const;

    virtual void walk();

    virtual void getHit(int damage);
};

#endif //LAB4_DATA_DELETE_CREATURE_H
