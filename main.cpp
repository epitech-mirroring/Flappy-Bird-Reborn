/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there , just an epitech header example .
** You can even have multiple lines if you want !
*/

#include "assets/objects/scripts/Background.hpp"
#include "assets/objects/scripts/Bird.hpp"
#include "assets/objects/scripts/Pipes.hpp"
#include "assets/objects/scripts/Score.hpp"
#include "StellarForge/Engine/Engine.hpp"
#include "StellarForge/Common/factories/ComponentFactory.hpp"
#include "StellarForge/Common/components/DynamicComponentLoader.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    try {
        auto loader = DynamicComponentLoader("assets/components");
        Engine const engine([&loader]() {
            REGISTER_COMPONENT(Background);
            REGISTER_COMPONENT(Bird);
            REGISTER_COMPONENT(Pipes);
            REGISTER_COMPONENT(Score);
            loader.loadComponents();
        }, "FlappyBird");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}
