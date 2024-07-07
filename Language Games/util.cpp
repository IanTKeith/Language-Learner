#include <random>
#include "util.hpp"

namespace Utility {
    std::wstring trim(std::wstring const& str) {
        static const wchar_t* ws = L" \t\n\r\f\v";
        std::wstring copy = str;
        return copy.erase(0, copy.find_first_not_of(ws)).erase(copy.find_last_not_of(ws) + 1);
    }

    unsigned int randInt(unsigned int min, unsigned int max) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(min, max);
        return dist(gen);
    }
}