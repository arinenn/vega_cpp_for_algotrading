#include <benchmark/benchmark.h>

#include "../src/my_add.hpp"

static void BM_RunApp(benchmark::State& state) {
    for (auto _ : state) {
        my_add(2, 3);
    }
}
BENCHMARK(BM_RunApp);

BENCHMARK_MAIN();