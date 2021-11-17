cmake_minimum_required(VERSION 3.20)
project(Lab4_Data_delete)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(Lab4_Data_delete main.cpp src/Operative.cpp src/Operative.h src/Weapon.cpp src/Weapon.h src/Ammo_container.cpp src/Ammo_container.h src/Medkit.cpp src/Medkit.h src/Inventory.cpp src/Inventory.h src/Specifications.cpp src/Specifications.h Map.cpp Map.h)

target_link_libraries(Lab4_Data_delete sfml-graphics sfml-audio)