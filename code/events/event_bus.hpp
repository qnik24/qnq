#pragma once

#include "events/event.hpp"
#include "events/event_sink.hpp"

#include <vector>

class EventBus {
public:
    EventBus();
    ~EventBus();

    EventSink& sink();

    void process();

private:
    void dispatch(Event event);

    EventSink sink_;
    std::vector<Event> buff_;
};
