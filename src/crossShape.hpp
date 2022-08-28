#include <SFML/Graphics.hpp>

class CrossShape : public sf::Drawable, public sf::Transformable {
    public:
        void setShape(float diameter, float x, float y);
        // add functions to play with the entity's geometry / colors / texturing...
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        sf::VertexArray m_vertices;
};
