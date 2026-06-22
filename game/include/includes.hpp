#pragma once
#include <iostream>
#include <iomanip>

#include <vector>
#include <unordered_map>
#include <memory>
#include <optional>
#include <variant>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

template <typename T>
using sptr = std::shared_ptr<T>;

template <typename T>
using uptr = std::unique_ptr<T>;

template <typename T>
using wptr = std::weak_ptr<T>;

using std::make_shared;
using std::make_unique;
