cmake_minimum_required(VERSION 3.20)
project(Lab4_Data_delete)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Lab4_Data_delete main.cpp src/Operative.cpp src/Operative.h src/Weapon.cpp src/Weapon.h src/AmmoContainer.h src/Aidkit.h src/MyVector.h src/Creature.cpp src/Creature.h Map.cpp Map.h src/WildCreature.cpp src/WildCreature.h src/Object.h src/Furajir.h src/Furajir.cpp src/SmartCreature.cpp src/SmartCreature.h graphics/GraphicCreature.cpp graphics/GraphicCreature.h graphics/GraphicFurajir.cpp graphics/GraphicFurajir.h graphics/GraphicWild.cpp graphics/GraphicWild.h graphics/GraphicOperative.cpp graphics/GraphicOperative.h)

target_link_libraries(Lab4_Data_delete sfml-graphics sfml-audio)