#ifndef templates_hpp
#define templates_hpp

#include <SFML/Graphics.hpp>
#include <optional>

template <typename T> using shared_ptr = std::shared_ptr<T>;
template <typename T> using opt_shared_ptr = std::optional<shared_ptr<T>>;
template <typename T> using vector_shared_ptr = std::vector<shared_ptr<T>>;
template <typename T> using vector2D_shared_ptr = std::vector<std::vector<shared_ptr<T>>>;

#endif