#include "platform/platform_runtime.hpp"

#include <GLFW/glfw3.h>

#include <optional>
#include <memory>

std::optional<std::shared_ptr<PlatformRuntime>>
PlatformRuntime::create() {
    if(!instance.expired())
        return instance.lock();

    if(!glfwInit())
        return { };
    
    auto ret = std::shared_ptr<PlatformRuntime>(new PlatformRuntime());
    instance = ret;

    return ret;
}

PlatformRuntime::PlatformRuntime() = default;
PlatformRuntime::~PlatformRuntime() {
    glfwTerminate();
}
