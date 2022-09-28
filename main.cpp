#include <iostream>

#include <application.h>
#include <tcpserver.h>

using namespace std;

using UW::Application;
using UW::TcpServer;

//int *a = new int;

int main()
{
//    free(a);
    Application app;

    TcpServer server("0.0.0.0", 7000);
    server.start();
    app.exec();

    return 0;
}
