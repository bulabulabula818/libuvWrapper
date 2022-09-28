#include "application.h"
#include "tcpserver.h"

namespace UW
{
Application::Application()
{

}

Application::~Application()
{
    uv_run(_loop, UV_RUN_DEFAULT);
    int ret = uv_loop_close(uv_default_loop());

    if(ret != 0)
    {
        TcpServer::displayError(ret);
    }
}

int Application::exec()
{
    cout << "uv_run" << endl;
    return uv_run(_loop, UV_RUN_DEFAULT);
}

void Application::stop()
{
    return uv_stop(uv_default_loop());
}

}
