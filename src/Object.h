//
// Created by sam on 21.11.2021.
//

#ifndef LAB4_DATA_DELETE_OBJECT_H
#define LAB4_DATA_DELETE_OBJECT_H

#include <string>
#include <utility>

enum Type{
    NOT,
    WEAPON,
    AIDKIT,
    AMMO
};
class Object {
protected:
    //std::string name;
    int weight = 0;
    Type type = NOT;
public:
    Object(): weight(0), type(NOT){}
    explicit Object(Type type, int weight = 0) : weight(weight), type(type) {}
};


#endif //LAB4_DATA_DELETE_OBJECT_H
