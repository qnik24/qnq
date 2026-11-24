#pragma once

// i don't know how GLFW plays with multiple instances
// as event pushing may make things weird?
// idk, have this later for now, as new libraries can be added later

#include <optional>
#include <memory>

class PlatformRuntime{
public:
    static std::optional<std::shared_ptr<PlatformRuntime>>
    create();

    ~PlatformRuntime();

    PlatformRuntime(const PlatformRuntime&) = delete;
    PlatformRuntime& operator=(const PlatformRuntime&) = delete;
    PlatformRuntime(PlatformRuntime&&) = delete;
    PlatformRuntime& operator=(PlatformRuntime&&) = delete;
    
private:
    explicit PlatformRuntime();

    static inline std::weak_ptr<PlatformRuntime> instance; 
};

using OptPFR = std::optional<std::shared_ptr<PlatformRuntime>>;

