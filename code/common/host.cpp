#include "common/host.hpp"
#include "platform/platform_runtime.hpp"

Host::Host() = default;
Host::~Host() = default;

bool Host::init() {
    pfRuntime = PlatformRuntime::create();
    window = Window::create(bus.sink());

    if(!pfRuntime || !window)
        return false;

    run_ = true;
    
    return true;
}

void Host::frame() {
    while(run_) {
        bus.process();
    }
}
