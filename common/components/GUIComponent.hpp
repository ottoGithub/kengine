#pragma once

#include <string>
#include "SerializableComponent.hpp"

namespace kengine {
    class GUIComponent : public kengine::SerializableComponent<GUIComponent>,
                         public putils::Reflectible<GUIComponent> {
    public:
        GUIComponent(std::string_view text = "", std::size_t textSize = 18, std::string_view font = "")
                : text(text), textSize(textSize), font(font) {}

        const std::string type = pmeta_nameof(GUIComponent);
        std::string text;
        double textSize;
        std::string font;

        /*
         * Reflectible
         */

    public:
        pmeta_get_class_name(GUIComponent);
        pmeta_get_attributes(
                pmeta_reflectible_attribute(&GUIComponent::type),
                pmeta_reflectible_attribute(&GUIComponent::text),
                pmeta_reflectible_attribute(&GUIComponent::textSize),
                pmeta_reflectible_attribute(&GUIComponent::font)
        );
        pmeta_get_methods();
        pmeta_get_parents();
    };
}
