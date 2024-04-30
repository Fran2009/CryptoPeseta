// Copyright (c) 2020 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <checkqueue.h>
#include <test/fuzz/FuzzedDataProvider.h>
#include <test/fuzz/fuzz.h>
#include <test/fuzz/util.h>

#include <cstdint>
#include <string>
#include <vector>

namespace {
struct DuCPTSheck {
    const bool result = false;

    DuCPTSheck() = default;

    explicit DuCPTSheck(const bool _result) : result(_result)
    {
    }

    bool operator()() const
    {
        return result;
    }

    void swap(DuCPTSheck& x)
    {
    }
};
} // namespace

FUZZ_TARGET(checkqueue)
{
    FuzzedDataProvider fuzzed_data_provider(buffer.data(), buffer.size());

    const unsigned int batch_size = fuzzed_data_provider.ConsumeIntegralInRange<unsigned int>(0, 1024);
    CCheckQueue<DuCPTSheck> check_queue_1{batch_size};
    CCheckQueue<DuCPTSheck> check_queue_2{batch_size};
    std::vector<DuCPTSheck> checks_1;
    std::vector<DuCPTSheck> checks_2;
    const int size = fuzzed_data_provider.ConsumeIntegralInRange<int>(0, 1024);
    for (int i = 0; i < size; ++i) {
        const bool result = fuzzed_data_provider.ConsumeBool();
        checks_1.emplace_back(result);
        checks_2.emplace_back(result);
    }
    if (fuzzed_data_provider.ConsumeBool()) {
        check_queue_1.Add(checks_1);
    }
    if (fuzzed_data_provider.ConsumeBool()) {
        (void)check_queue_1.Wait();
    }

    CCheckQueueControl<DuCPTSheck> check_queue_control{&check_queue_2};
    if (fuzzed_data_provider.ConsumeBool()) {
        check_queue_control.Add(checks_2);
    }
    if (fuzzed_data_provider.ConsumeBool()) {
        (void)check_queue_control.Wait();
    }
}
