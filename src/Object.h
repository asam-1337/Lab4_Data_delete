//
// Created by sam on 21.11.2021.
//

#ifndef LAB4_DATA_DELETE_OBJECT_H
#define LAB4_DATA_DELETE_OBJECT_H

#include <string>
#include <utility>

enum Type {
    NOT,
    WEAPON,
    AIDKIT,
    AMMO
};

enum Name{
    NO,
    M4,
    AK
};

class Object {
protected:
    int m_weight = 0;
    Type m_type = NOT;
    Name m_name = NO;
public:
    Object() = default;

    Object(Type type, Name name, int weight) : m_weight(weight), m_type(type), m_name(name) {}

    [[nodiscard]] virtual int getWeight() const { return m_weight; }

    [[nodiscard]] virtual Type getType() const { return m_type; }

    [[nodiscard]] virtual Name getName() const { return m_name; }

    void selectType (Type type) { m_type = type; }

};
#endif //LAB4_DATA_DELETE_OBJECT_H
