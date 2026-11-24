#pragma once

#include "events/event_sink.hpp"

#include <memory>
#include <optional>

class Window {
public:
    static std::optional<Window> create(EventSink&);
    ~Window();

    Window(Window&&);
    Window& operator=(Window&&);

private:
    struct Data;

    explicit Window(std::unique_ptr<Data>&&);

    std::unique_ptr<Data> data_;
};

using OptWindow = std::optional<Window>;
