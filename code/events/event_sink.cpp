#include "events/event_sink.hpp"

#include <vector>

EventSink::EventSink(std::vector<Event>& buff)
    : buff_(buff) { }

EventSink::~EventSink() = default;

void EventSink::push(Event event) {
    buff_.push_back(event);
}
