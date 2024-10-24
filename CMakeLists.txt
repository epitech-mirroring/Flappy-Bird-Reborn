add_executable(flappy-bird
        assets/objects/scripts/Score.hpp)

target_link_libraries(flappy-bird PUBLIC StellarForge StellarForgeGraphics StellarForgePhysics StellarForgeCommon sfml::sfml glm::glm)

target_sources(flappy-bird
        PUBLIC
        assets/objects/scripts/Background.hpp
        assets/objects/scripts/Bird.hpp
        assets/objects/scripts/Pipes.hpp
        assets/objects/scripts/Score.hpp
        PRIVATE
        main.cpp
        assets/objects/scripts/Background.cpp
        assets/objects/scripts/Bird.cpp
        assets/objects/scripts/Pipes.cpp
        assets/objects/scripts/Score.cpp
)
