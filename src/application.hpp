#ifndef application_hpp
#define application_hpp

class Application {
    public:
        Application();
        void run();
    private:
        sf::Transform spriteTransformation(int rows, int columns, int windowWidth, int windowHeight);
};

#endif