#include <iostream>
#include <windows.h>
#include "include/telemetry.hpp"

// Tactical Latency Auditor - Core Monitoring Node
int main() {
    SetConsoleTitleA("Tactical Auditor: System Telemetry Node");
    
    std::cout << "[SYSTEM] Initializing Telemetry Bridge..." << std::endl;
    
    if (!Telemetry::VerifyEngineSync()) {
        std::cerr << "[!] Warning: Engine synchronization not detected." << std::endl;
    }

    std::cout << "[*] Monitoring Network Jitter and Frame-Times..." << std::endl;
    
    while (Telemetry::IsProcessActive()) {
        // Log telemetry data to output/logs/
        Telemetry::RecordPerformanceMetrics();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}