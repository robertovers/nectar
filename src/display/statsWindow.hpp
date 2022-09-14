#ifndef statsWindow_hpp
#define statsWindow_hpp

#include "../utility.hpp"
#include "../templates.hpp"

class StatsWindow {
    public:
        StatsWindow(shared_ptr<Metrics> metrics);
        void display();
    private:
        shared_ptr<Metrics> metrics;
};

#endif