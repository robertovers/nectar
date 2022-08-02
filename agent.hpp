#ifndef agent_hpp
#define agent_hpp

class Agent {
    public:
        Agent(float x, float y);
        void update();
    private:
        float pos_x;
        float pos_y;
        float vel_x = 0;
        float vel_y = 0;
};

#endif