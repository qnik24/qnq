#pragma once

#include "platform/platform_runtime.hpp"
#include "platform/window.hpp"
#include "events/event_bus.hpp"

class Host {
public:
     Host();
    ~Host();

    bool init();
    void frame();

private:

    bool run_;

    EventBus bus;
    OptPFR pfRuntime;
    OptWindow window;
};
