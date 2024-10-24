/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** Bird.hpp
*/

#ifndef STELLARFORGE_BIRD_HPP
#define STELLARFORGE_BIRD_HPP

#include "common/components/CPPMonoBehaviour.hpp"
#include "common/components/Transform.hpp"
#include "physics/components/RigidBody.hpp"
#include "common/json/JsonObject.hpp"
#include "common/event/EventSystem.hpp"
#include "physics/Box.hpp"

/**
 * @class Bird
 * @brief Handles the behavior of the bird in the game.
 * @version v0.1.0
 * @since v0.1.0
 * @author Landry Gigant
 */
class Bird : public CPPMonoBehaviour {
public:
    /**
     * @brief Constructor for the Bird class.
     * @param owner Pointer to the owner object.
     * @param data JSON data for configuration.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    Bird(IObject *owner, const json::IJsonObject *data);

    /**
     * @brief Default destructor for the Bird class.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    ~Bird() override = default;

    /**
     * @brief Initializes the bird's behavior.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    void start() override;

    /**
     * @brief Updates the bird's position and state every frame.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    void update() override;

    /**
     * @brief Makes the bird jump.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    void jump();

    /**
     * @brief Handles the bird's death.
     * @version v0.1.0
     * @since v0.1.0
     * @authors Landry Gigant & Aubane Nourry
     */
    void die();

    /**
     * @brief Sets the force applied during a jump.
     * @param newJumpForce New jump force value.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    void setJumpForce(float newJumpForce);

    /**
     * @brief Gets the current jump force.
     * @return The jump force of the bird.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    [[nodiscard]] float getJumpForce() const;

    /**
     * @brief Clones the bird component.
     * @param owner The owner of the new component.
     * @return A new Bird component clone.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    IComponent *clone(IObject *owner) const override;

    /**
     * @brief Deserializes bird data from JSON.
     * @param data JSON data for deserialization.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    void deserialize(const json::IJsonObject *data) override;

    /**
     * @brief Called when the bird component is destroyed.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    void end() override;

    /**
     * @brief Serializes the bird's data into JSON format.
     * @return Serialized JSON data.
     * @version v0.1.0
     * @since v0.1.0
     * @author Landry Gigant
     */
    json::IJsonObject *serializeData() override;

private:
    float jumpForce = 250.0f; ///< Force applied when the bird jumps
    bool isDead = false; ///< Indicates if the bird is dead
};

#endif // STELLARFORGE_BIRD_HPP
