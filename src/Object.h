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
    int weight = 0;
    Type type = NOT;
    Name name = NO;
public:
    Object() = default;

    explicit Object(Type type, Name name, int weight) : weight(weight), type(type), name(name) {}

    virtual void reload(int& ammo) = 0;

    virtual bool fire() = 0;

    [[nodiscard]] virtual int& getAmmo() = 0;

    [[nodiscard]] virtual int getAmmo() const = 0;

    [[nodiscard]] virtual int getMaxAmmo() const = 0;

    [[nodiscard]] virtual int getReloadCost() const = 0;

    [[nodiscard]] virtual int getShootCost() const = 0;

    [[nodiscard]] virtual int getDamage() const = 0;

    [[nodiscard]] virtual int getWeight() const { return weight; }

    [[nodiscard]] virtual Type getType() const { return type; }

    [[nodiscard]] virtual Name getName() const { return name; }

};
#endif //LAB4_DATA_DELETE_OBJECT_H
