#ifndef application_hpp
#define application_hpp

class Application {
    public:
        Application();
        void run();
    private:
        // Returns transformation that will be applied to all objects in the simulation
        sf::Transform spriteTransformation(int rows, int columns, int windowWidth, int windowHeight);
};

#endif