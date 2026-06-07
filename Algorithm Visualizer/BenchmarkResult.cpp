#include "BenchmarkResult.h"
#include <iomanip>
#include <sstream>

BenchmarkResult::BenchmarkResult(const std::string& algo, double ms, int ops)
    : algorithm(algo), milliseconds(ms), operations(ops) {}

std::string BenchmarkResult::exportCSV(const std::vector<BenchmarkResult>& results) {
    std::stringstream ss;
    ss << "Algorithm,Time(ms),Operations\n";
    for (const auto& r : results)
        ss << r.algorithm << "," << std::fixed << std::setprecision(3) << r.milliseconds << "," << r.operations << "\n";
    return ss.str();
}
