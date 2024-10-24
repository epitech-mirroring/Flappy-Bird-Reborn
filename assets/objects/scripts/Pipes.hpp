/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** Pipes.hpp
*/

#ifndef STELLARFORGE_PIPES_HPP
#define STELLARFORGE_PIPES_HPP

#include <chrono>
#include "common/components/CPPMonoBehaviour.hpp"
#include "common/components/Transform.hpp"
#include "physics/components/RigidBody.hpp"
#include "common/json/JsonObject.hpp"
#include "common/event/EventSystem.hpp"
#include "common/managers/ObjectManager.hpp"
#include "physics/Box.hpp"

/**
 * @class Pipes
 * @brief Manages the pipes spawning and movement in the game.
 * @version v0.1.0
 * @since v0.1.0
 * @author Landry Gigant
 */
class Pipes : public CPPMonoBehaviour {
public:
    /**
     * @brief Constructor for the Pipes class.
     * @param owner Pointer to the owner object.
     * @param data JSON data for configuration.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    Pipes(IObject *owner, const json::IJsonObject *data);

    /**
     * @brief Default destructor for the Pipes class.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    ~Pipes() override = default;

    /**
     * @brief Initializes the pipes behavior.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    void start() override;

    /**
     * @brief Updates the pipes' position and state every frame.
     * @version v0.1.0
     * @since v0.1.0
     * @authors Landry Gigant & Aubane Nourry
     */
    void update() override;

    /**
     * @brief Sets the pipes' movement speed.
     * @param newSpeed New speed value.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    void setSpeed(float newSpeed);

    /**
     * @brief Gets the current pipes' speed.
     * @return The speed of the pipes.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    [[nodiscard]] float getSpeed() const;

    /**
     * @brief Sets the rate at which pipes spawn.
     * @param newSpawnRate New spawn rate value.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    void setSpawnRate(float newSpawnRate);

    /**
     * @brief Gets the current spawn rate of the pipes.
     * @return The spawn rate of the pipes.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    [[nodiscard]] float getSpawnRate() const;

    /**
     * @brief Spawns a pipe with a specified offset.
     * @param offset The offset for spawning the pipe.
     * @version v0.1.0
     * @since v0.1.0
     * @authors Landry Gigant & Aubane Nourry
     */
    void spawnPipe(float offset);

    /**
     * @brief Event handler for when the game is lost.
     * @param data Event data for game loss.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void onGameLost(const EventData &data);

    /**
     * @brief Clones the pipes component.
     * @param owner The owner of the new component.
     * @return A new Pipes component clone.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    IComponent *clone(IObject *owner) const override;

    /**
     * @brief Deserializes pipes data from JSON.
     * @param data JSON data for deserialization.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    void deserialize(const json::IJsonObject *data) override;

    /**
     * @brief Called when the pipes component is destroyed.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    void end() override;

    /**
     * @brief Serializes the pipes' data into JSON format.
     * @return Serialized JSON data.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    json::IJsonObject *serializeData() override;

private:
    float speed = 300.0f; ///< Speed of the pipes' movement
    float spawnRate = 2.00f; ///< Rate at which pipes spawn
    std::chrono::time_point<std::chrono::system_clock> startTime; ///< Start time for pipes
    std::chrono::time_point<std::chrono::system_clock> actualTime; ///< Current time
    std::vector<UUID> pipes; ///< List of pipes spawned
    bool gameLost = false; ///< Indicates if the game is lost
};

#endif // STELLARFORGE_PIPES_HPP