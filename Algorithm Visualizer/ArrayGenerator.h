#pragma once
#include <vector>
#include <string>

class ArrayGenerator {
public:
    static std::vector<int> random(int size, int min = 1, int max = 100);
    static std::vector<int> nearlySorted(int size, int swaps = 10);
    static std::vector<int> reversed(int size);
    static std::vector<int> fromString(const std::string& input);
    static std::string toFile(const std::vector<int>& arr, const std::string& filename);
    static std::vector<int> seeded(int size, unsigned int seed, int min = 1, int max = 100);
};
