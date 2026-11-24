#pragma once

#include "events/event.hpp"

#include <vector>

class EventSink {
public:
    explicit EventSink(std::vector<Event>&);
    ~EventSink();

    void push(Event);

private:
    std::vector<Event>& buff_;
};
