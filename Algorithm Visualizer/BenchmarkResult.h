#pragma once
#include <string>
#include <chrono>

class BenchmarkResult {
public:
    std::string algorithm;
    double milliseconds;
    int operations;

    BenchmarkResult(const std::string& algo, double ms, int ops);
    static std::string exportCSV(const std::vector<BenchmarkResult>& results);
};
