#pragma once

struct WindowCloseEvent {};

struct Event {
    enum class Type {
        WindowClose,
    };

    Type type;
    union {
        WindowCloseEvent data_WindowClose;
    };

    Event(WindowCloseEvent e)
        : type(Type::WindowClose), data_WindowClose(e) { }
};
