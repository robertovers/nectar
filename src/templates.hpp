/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file templates.hpp
 * @brief File containing typename templates used. 
 * @date 2022-10-04
 */

#ifndef templates_hpp
#define templates_hpp

#include <SFML/Graphics.hpp>
#include <optional>

template <typename T> using shared_ptr = std::shared_ptr<T>;
template <typename T> using opt_shared_ptr = std::optional<shared_ptr<T>>;
template <typename T> using vector_shared_ptr = std::vector<shared_ptr<T>>;
template <typename T> using vector2D_shared_ptr = std::vector<std::vector<shared_ptr<T>>>;

#endif