/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** Background.hpp
*/

#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <chrono>
#include "StellarForge/Common/components/CPPMonoBehaviour.hpp"
#include "StellarForge/Common/components/Transform.hpp"
#include "StellarForge/Common/json/JsonObject.hpp"
#include "StellarForge/Common/event/EventSystem.hpp"

/**
 * @class Background
 * @brief Handles the background behavior in the game.
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane Nourry
 */
class Background final : public CPPMonoBehaviour {
public:
    /**
     * @brief Constructor for the Background class.
     * @param owner Pointer to the owner object.
     * @param data JSON data used to configure the background.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    Background(IObject *owner, const json::IJsonObject *data);

    /**
     * @brief Default destructor for the Background class.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    ~Background() override = default;

    /**
     * @brief Initializes the background.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void start() override;

    /**
     * @brief Updates the background every frame.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void update() override;

    /**
     * @brief Event handler for when the game is lost.
     * @param data Event data for game loss.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void onGameLost(const EventData &data);

    /**
     * @brief Sets the background scrolling speed.
     * @param newSpeed New speed value.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void setSpeed(float newSpeed);

    /**
     * @brief Gets the current background speed.
     * @return The speed of the background.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    [[nodiscard]] float getSpeed() const;

    /**
     * @brief Clones the background component.
     * @param owner The owner of the new component.
     * @return A new Background component clone.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    IComponent *clone(IObject *owner) const override;

    /**
     * @brief Deserializes background data from JSON.
     * @param data JSON data to deserialize.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void deserialize(const json::IJsonObject *data) override;

    /**
     * @brief Called when the background component is destroyed.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void end() override;

    /**
     * @brief Serializes the background data into JSON format.
     * @return Serialized JSON data.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    json::IJsonObject *serializeData() const override;

private:
    float speed = 1.00f; ///< Speed of the background scrolling
    #ifdef _WIN32
     std::chrono::steady_clock::time_point startTime;
     std::chrono::steady_clock::time_point actualTime;
    #else
     std::chrono::system_clock::time_point startTime;
     std::chrono::system_clock::time_point actualTime;
    #endif // _WIN32
    bool gameLost = false; ///< Indicates if the game is lost
};

#endif // BACKGROUND_HPP
