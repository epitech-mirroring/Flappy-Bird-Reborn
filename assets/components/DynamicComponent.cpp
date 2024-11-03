/*
** EPITECH PROJECT, 2024
** StellarForge
** File description:
** No file there, just an epitech header example.
** You can even have multiple lines if you want!
*/

#include "StellarForge/Common/factories/ComponentFactory.hpp"
#include "StellarForge/Common/fields/StringField.hpp"
#include "StellarForge/Common/fields/groups/InvisibleFieldGroup.hpp"
#include "StellarForge/Common/json/JsonNull.hpp"
#include "StellarForge/Common/utils/Logger.hpp"
#include "StellarForge/Common/components/Transform.hpp"

extern "C"  {
    SYMBOL const char **getComponentName() {
        static const char *components[] = {
            "DynamicComponent",
            nullptr
        };
        return components;
    }
}

class DynamicComponent final : public AComponent {
public:
    class Meta final : public IMeta {
    protected:
        DynamicComponent *_owner;
        InvisibleFieldGroup _fieldGroup;

    public:
        explicit Meta(DynamicComponent *owner): _owner(owner), _fieldGroup(InvisibleFieldGroup({})) {
        }

        [[nodiscard]] std::string getName() const override {
            return "DynamicComponent";
        }

        [[nodiscard]] std::string getDescription() const override {
            return "DynamicComponent component dynamically loaded.";
        }

        [[nodiscard]] bool isUnique() const override {
            return true;
        }

        [[nodiscard]] bool canBeRemoved() const override {
            return true;
        }

        [[nodiscard]] std::vector<const IFieldGroup *>
        getFieldGroups() const override {
            return {&_fieldGroup};
        }
    };

    explicit DynamicComponent(IObject *owner,
                   const json::JsonObject *data = nullptr): AComponent(
        owner, new Meta(this), data) {
    }

    ~DynamicComponent() override = default;

    [[nodiscard]] IComponent *clone(IObject *owner) const override {
        return new DynamicComponent(owner, dynamic_cast<json::JsonObject *>(this->serializeData()));
    }

    void runComponent() override {
        const auto *transformComponent = getParentComponent<Transform>();
        if (transformComponent != nullptr) {
            const std::string str= "I Dynamicly know the position of the object: " + std::to_string(transformComponent->getPosition().x) + ", " + std::to_string(transformComponent->getPosition().y) + ", " + std::to_string(transformComponent->getPosition().z) + "\n";
            this->_log.info << str;
            return;
        }
        const std::string str= "I Dynamicly don't know the position of the object\n";
        this->_log.info << str;
    }

    void deserialize(const json::IJsonObject *data) override {
    }

protected:
    Logger _log;

    [[nodiscard]] json::IJsonObject *serializeData() const override {
        return new json::JsonNull();
    }
};

extern "C" {
    SYMBOL void registerComponents(ComponentFactory *factory) {
        factory->registerComponent<DynamicComponent>("DynamicComponent");
    }
}
