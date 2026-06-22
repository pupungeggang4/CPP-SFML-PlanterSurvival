#include "includes.hpp"
#include "game.hpp"

int main(int argc, char** argv) {
    sptr<Game> game = make_shared<Game>();
    game->run();
    return 0;
}
