#include "ui.hpp"

std::unordered_map<std::string, std::vector<float>> UI::title = {
    {"text_title", {20, 20}},
    {"button_start", {160, 160, 960, 80}},
    {"button_erase", {160, 240, 960, 80}},
    {"button_collection", {160, 320, 960, 80}},
    {"button_quit", {160, 400, 960, 80}},
    {"arrow", {80, 160, 80, 80, 0, 80}}
};

std::unordered_map<std::string, std::vector<float>> UI::menu = {
    {"rect", {320, 200, 640, 320}},
    {"text_title", {340, 220}},
    {"button_resume", {320, 280, 640, 80}},
    {"button_surrender", {320, 360, 640, 80}},
    {"button_quit", {320, 440, 640, 80}},
    {"arrow", {240, 280, 80, 80, 0, 80}}
};
