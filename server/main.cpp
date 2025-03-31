#include "server.h"
#include "app_control.h"

int main()
{
    std::thread t1([&t1](){app_control ac; ac.loop();t1.join();});
    server server;
    server.RunServer();
    return 0;
}
