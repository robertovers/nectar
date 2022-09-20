#ifndef PLANT_HPP
#define PLANT_HPP

#include <SFML/Graphics.hpp>
#include "location.hpp"

class Plant : public Location {
    public:
        /**
        * @brief Construct a new Plant object
        * 
        * @param x the x-coordinate of the plant.
        * @param y the y-coordinate of the plant.
        */
        Plant(int x, int y);
        virtual ~Plant();
        /**
         * @brief Checks if this location is a Plant - used before type casting.
         *
         * @return true since this is a Plant.
         */
        bool isPlant() override;
        /**
         * @brief Checks if this Plant contains nectar.
         *
         * @return true if this Plant contains > 0 nectar.
         * @return false if this Plant contains no nectar.
         */
        bool hasNectar();
        /**
         * @brief Calculates the percentage of nectar, compared to its max capacity
         *
         * @return float value between 0 (no nectar) and 1 (nectar = max nectar)
         */
        float nectarPercentage() const;
        /**
         * @brief Checks if this Plant contains nectar.
         *
         * @return true if this Plant contains over 75% of nectar, relative to its max capacity.
         * @return false if this Plant contains less than 75% of nectar, relative to its max capacity.
         */
        bool hasLotsOfNectar();
        /**
        * @brief Checks if this Plant is pollinated.
        *
        * @return true if this Plant has been pollinated.
        * @return false if this Plant has not been pollinated.
        */
        bool isPollinated() const;
        /**
        * @brief Mark the plant as pollinated
        */
        void pollinate();
        /**
        * @brief Removes a set amount of nectar from the Plant
        * 
        * @return the quantity of nectar harvested and removed from the plant
        */
        float harvestNectar();
        /**
         * @brief Renders this location to the target.
         *
         * @param target a render target.
         * @param states states to be applied when rendering to the target.
         */
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    protected:
        /// Whether or not the plant is pollinated
        bool pollinated = false;
        /// @brief The quantity of nectar within the plant. Should be less than MAX_NECTAR
        float nectar = MAX_NECTAR;
        /// @brief The sprite to be drawn over the location if pollinated.
        shared_ptr<sf::Shape> pollinatedOverlay = nullptr;
        /// @brief The sprite to be drawn over the location, depending on nectar levels.
        shared_ptr<sf::Shape> nectarOverlay = nullptr;
    private:
        /// @brief The maximum amount of nectar the Plant can contain.
        const int MAX_NECTAR = 20;
};

#endif