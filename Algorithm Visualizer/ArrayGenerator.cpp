#include "ArrayGenerator.h"
#include <random>
#include <fstream>
#include <sstream>

std::vector<int> ArrayGenerator::random(int size, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    std::vector<int> arr;
    arr.reserve(size);
    for (int i = 0; i < size; ++i)
        arr.push_back(dist(gen));
    return arr;
}

std::vector<int> ArrayGenerator::nearlySorted(int size, int swaps) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i)
        arr[i] = i + 1;
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int i = 0; i < swaps; ++i) {
        std::uniform_int_distribution<> dist(0, size - 1);
        int a = dist(gen), b = dist(gen);
        std::swap(arr[a], arr[b]);
    }
    return arr;
}

std::vector<int> ArrayGenerator::reversed(int size) {
    std::vector<int> arr(size);
    for (int i = 0; i < size; ++i)
        arr[i] = size - i;
    return arr;
}

std::vector<int> ArrayGenerator::fromString(const std::string& input) {
    std::vector<int> arr;
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ','))
        arr.push_back(std::stoi(token));
    return arr;
}

std::string ArrayGenerator::toFile(const std::vector<int>& arr, const std::string& filename) {
    std::ofstream file(filename);
    for (size_t i = 0; i < arr.size(); ++i) {
        file << arr[i];
        if (i + 1 < arr.size()) file << " ";
    }
    file.close();
    return filename;
}
