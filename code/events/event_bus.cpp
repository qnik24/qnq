#include "events/event_bus.hpp"
#include "events/event_sink.hpp"

#include <GLFW/glfw3.h>

#include <vector>
// DELETE
#include <iostream>

EventBus::EventBus()
    : buff_(std::vector<Event>()), sink_(buff_) { }

EventBus::~EventBus() = default;

EventSink& EventBus::sink() {
    return sink_;
}

void EventBus::process() {
    glfwPollEvents();

    std::vector<Event> batch;
    batch.swap(buff_);

    for(auto event : batch) {
        dispatch(event);
    }
}

void EventBus::dispatch(Event event) {
    std::cout << "Dispatching" << std::endl; 
}
