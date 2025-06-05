#include <benchmark/benchmark.h>
#include <vector>
#include <cstdint>
#include "my_mean.h"
#include "origin_mean.h"

std::vector<uint8_t> data{1, 2, 3, 4, 5};

static void BM_originMeanFunction(benchmark::State &state)
{
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(originMean(data));
    }
}

static void BM_myMeanFunction(benchmark::State &state)
{
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(myMean(data));
    }
}

BENCHMARK(BM_originMeanFunction);
BENCHMARK(BM_myMeanFunction);
BENCHMARK_MAIN();