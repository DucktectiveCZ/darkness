#include "../include/game.hpp"
#include "../include/GlobalConstants.hpp"
#include <spdlog/spdlog.h>
#include <string>
#include <vector>

int main(int argc, char** argv) {
    // Handle console line arguments
    {
        std::vector<std::string> args;
        for (auto i = 0; i < argc; ++i) {
            args.reserve(argc);
            args.push_back(argv[i]);
        }
        for (auto arg : args) {
            if (arg == "--debug" || arg == "-d")
                globalConstants::debug = true;
        }
    }
    if (globalConstants::debug)
        spdlog::set_level(spdlog::level::debug);
    
    game::start();
}
