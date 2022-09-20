#ifndef PLANT_HPP
#define PLANT_HPP

#include <SFML/Graphics.hpp>
#include "location.hpp"

class Plant : public Location {
    public:
        Plant(int x, int y);
        virtual ~Plant();
        bool isPlant() override;
        bool hasNectar();
        float nectarPercentage() const;
        bool hasLotsOfNectar();
        bool isPollinated() const;
        void pollinate();
        float harvestNectar();
        /**
         * @brief Renders this location to the target.
         *
         * @param target a render target.
         * @param states states to be applied when rendering to the target.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    protected:
        bool pollinated = false;
        float nectar = std::rand() % MAX_NECTAR;
        /// @brief The sprite to be drawn over the location if pollinated.
        shared_ptr<sf::Shape> pollinatedOverlay = nullptr;
        /// @brief The sprite to be drawn over the location, depending on nectar levels.
        shared_ptr<sf::Shape> nectarOverlay = nullptr;
    private:
        const int MAX_NECTAR = 20;
};

#endif