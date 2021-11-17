//
// Created by chicha-man on 13.11.2021.
//

#ifndef LAB4_DATA_DELETE_SPECIFICATIONS_H
#define LAB4_DATA_DELETE_SPECIFICATIONS_H


class Specifications {
protected:
    int curr_health = 0;
    int max_health = 0;
    int curr_points = 0;
    int max_points = 0;
    int walk_cost = 0;
    int accuracy = 0;
    int view_rad = 0;
    int max_weight = 0;
public:
    Specifications(int max_health, int curr_points, int max_points, int walk_cost, int accuracy, int view_rad, int max_weight);
    Specifications(Specifications & src);
};

#endif //LAB4_DATA_DELETE_SPECIFICATIONS_H
