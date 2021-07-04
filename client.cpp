#include <iostream>
#include <future>
#include "signalrclient/hub_connection.h"
#include "signalrclient/hub_connection_builder.h"
#include "signalrclient/signalr_value.h"

constexpr char HUB_URL [] {"http://localhost:80/simple"};

int main()
{
    // SignalR hub connection
    signalr::hub_connection connection = signalr::hub_connection_builder::create(HUB_URL).build();

    // Handler for Pong
    connection.on("Pong", [](const signalr::value& m)
    {
        std::ignore = m;
        std::cout << "Pong Received" << std::endl;
    });

    // Handler for Hello IntervalSendModel
    connection.on("Hello", [](const signalr::value& m)
    {
        auto& content = m.as_array()[0].as_map();
        for (auto && [field, value]: content)
        {
            std::cout << field << ":" << value.as_string() << std::endl;
        }
        std::cout << "----------" << std::endl;
    });

    // Start connection
    std::promise<void> start_task;
    connection.start([&start_task](const std::exception_ptr& exception)
    {
        if (exception)
        {
            start_task.set_exception(exception);
        }
        start_task.set_value();
    });
    start_task.get_future().get();

    // TODO: Send Ping

    // Block until disconnection
    std::promise<void> connection_disconnected;
    connection.set_disconnected([&connection_disconnected](const std::exception_ptr& exception)
    {
        if (exception)
        {
            connection_disconnected.set_exception(exception);
        }
        connection_disconnected.set_value();
    });
    connection_disconnected.get_future().get();

    return 0;
}
