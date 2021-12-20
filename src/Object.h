//
// Created by sam on 21.11.2021.
//

#ifndef LAB4_DATA_DELETE_OBJECT_H
#define LAB4_DATA_DELETE_OBJECT_H

#include <string>
#include <utility>

enum Type {
    WEAPON,
    AIDKIT,
    AMMO
};

enum Name{
    M4,
    AK
};

class Object {
public:
    std::string name;
protected:
    int m_weight = 0;
public:
    Object() = default;

    Object(std::string name, int weight) : name(std::move(name)), m_weight(weight) {}

    virtual ~Object() = default;

    [[nodiscard]] virtual int getWeight() const { return m_weight; }

    [[nodiscard]] virtual Type getType() const = 0;

};


#endif //LAB4_DATA_DELETE_OBJECT_H
