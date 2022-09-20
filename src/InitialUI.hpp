#ifndef INITIALUI_HPP
#define INITIALUI_HPP

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include "utility.hpp"

class InitialUI{
    public:
        InitialUI();
        Parameters run();
};

#endif


