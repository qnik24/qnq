#include "platform/window.hpp"
#include "events/event_sink.hpp"

#include <GLFW/glfw3.h>

#include <memory>
#include <optional>

struct Window::Data {
    GLFWwindow* handle;
    EventSink& sink;
    
    static std::unique_ptr<Data> create(EventSink& sink) {
        // hard code for now
        GLFWwindow* handle = glfwCreateWindow(800, 600, "test", nullptr, nullptr);

        if(handle) return std::make_unique<Data>(handle, sink);
        else return nullptr;
    }

    explicit Data(GLFWwindow* handle, EventSink& sink)
        : handle(handle), sink(sink) {
        glfwSetWindowUserPointer(handle, this);
    }

    ~Data() {
        if(handle)
            glfwDestroyWindow(handle);
    }
};

Window::Window(std::unique_ptr<Data>&& data) : data_(std::move(data)) {
    // pump events to the event queue
    glfwSetWindowCloseCallback(data_->handle, [](GLFWwindow* handle) {
                auto* data = static_cast<Data*>(glfwGetWindowUserPointer(handle));
                data->sink.push(WindowCloseEvent{});
            });
}

Window::~Window() = default;
Window::Window(Window&&) = default;
Window& Window::operator=(Window&&) = default;

std::optional<Window> Window::create(EventSink& sink) {
    auto data = Data::create(sink);

    if(data) return Window(std::move(data));
    else return { };
}
