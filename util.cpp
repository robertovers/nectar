#ifndef UTIL_CPP
#define UTIL_CPP
/*
    A class for holding functions and global variables that are useful across the program. 
*/

#include <vector>
#include "mapObject.hpp"

using mapObjectPtr = std::shared_ptr<MapObject>;
using mapObjectPtrVector = std::vector<mapObjectPtr>;

#endif