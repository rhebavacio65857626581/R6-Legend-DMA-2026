#pragma once
#include <cstdint>

namespace Telemetry {
    bool VerifyEngineSync();
    void RecordPerformanceMetrics();
    bool IsProcessActive();
    
    struct PerformanceData {
        float frame_time;
        int64_t network_jitter;
        uint64_t input_delta;
    };
}