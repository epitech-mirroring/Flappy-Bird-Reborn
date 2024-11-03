/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** Score.hpp
*/

#ifndef SCORE_HPP
#define SCORE_HPP

#include <chrono>
#include "StellarForge/Common/components/CPPMonoBehaviour.hpp"
#include "StellarForge/Common/components/Transform.hpp"
#include "StellarForge/Graphics/components/UIText.hpp"
#include "StellarForge/Common/json/JsonObject.hpp"
#include "StellarForge/Common/event/EventSystem.hpp"

/**
 * @class Score
 * @brief Manages the game's score display and calculation.
 * @version v0.1.0
 * @since v0.1.0
 * @author Aubane Nourry
 */
class Score final : public CPPMonoBehaviour {
public:
    /**
     * @brief Constructor for the Score class.
     * @param owner Pointer to the owner object.
     * @param data JSON data for configuration.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    Score(IObject *owner, const json::IJsonObject *data);

    /**
     * @brief Default destructor for the Score class.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    ~Score() override = default;

    /**
     * @brief Initializes the score management.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void start() override;

    /**
     * @brief Updates the score every frame.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void update() override;

    /**
     * @brief Updates the UI score text.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void setUITextScore();

    /**
     * @brief Event handler for when the game is lost.
     * @param data Event data for game loss.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void onGameLost(const EventData &data);

    /**
     * @brief Sets the current score.
     * @param newScore New score value.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void setScore(const unsigned int newScore) { score = newScore; }

    /**
     * @brief Gets the current score.
     * @return The current score.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    [[nodiscard]] unsigned int getScore() const { return score; }

    /**
     * @brief Clones the score component.
     * @param owner The owner of the new component.
     * @return A new Score component clone.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    IComponent *clone(IObject *owner) const override;

    /**
     * @brief Deserializes score data from JSON.
     * @param data JSON data for deserialization.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void deserialize(const json::IJsonObject *data) override;

    /**
     * @brief Called when the score component is destroyed.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    void end() override;

    /**
     * @brief Serializes the score data into JSON format.
     * @return Serialized JSON data.
     * @version v0.1.0
     * @since v0.1.0
     * @author Aubane Nourry
     */
    json::IJsonObject *serializeData() const override;

private:
    #ifdef _WIN32
     std::chrono::steady_clock::time_point startTime;
     std::chrono::steady_clock::time_point actualTime;
    #else
     std::chrono::system_clock::time_point startTime;
     std::chrono::system_clock::time_point actualTime;
    #endif // _WIN32
    unsigned int score = 0; ///< Current game score
    float timeBeforePipe = 8.5f; ///< Time before next pipe spawns
    bool gameLost = false; ///< Indicates if the game is lost
};

#endif // SCORE_HPP
