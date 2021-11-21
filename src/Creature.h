//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_CREATURE_H
#define LAB4_DATA_DELETE_CREATURE_H


class Creature {
protected:
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
    Creature(int max_health, int curr_points, int max_points, int walk_cost, int accuracy, int view_rad, int curr_weight, int max_weight);
    Creature(Creature & src);
};

#endif //LAB4_DATA_DELETE_CREATURE_H
