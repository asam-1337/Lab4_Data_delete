//
// Created by chicha-man on 14.11.2021.
//

#ifndef LAB4_DATA_DELETE_MAP_H
#define LAB4_DATA_DELETE_MAP_H

#include <string>

class Map {
    static const int height = 12;
    const int width = 40;
    std::string TileMap[height] = {
            "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
            "B                                B     B",
            "B                                B     B",
            "B                                B     B",
            "B                                B     B",
            "B         0000                BBBB     B",
            "B                                B     B",
            "BBB                              B     B",
            "B              BB                BB    B",
            "B              BB                      B",
            "B    B         BB         BB           B",
            "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    };
};


#endif //LAB4_DATA_DELETE_MAP_H
