#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <iostream>

#include <uv.h>

using namespace std;

typedef struct {
    uv_write_t req;
    uv_buf_t buf;
} write_req_t;

namespace  UW
{

class TcpServer
{
public:
    TcpServer(const char *ip, uint16_t port);
    ~TcpServer();

    int start();

    static void displayError(int err);

private:
    static void freeWriteReq(uv_write_t *req);

    static void allocBuffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf);

    static void onClose(uv_handle_t* handle);

    static void echoWrite(uv_write_t *req, int status);

    static void echoRead(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf);

    static void _onNewConnection(uv_stream_t *server, int status);

    static void _onTcpServerClose(uv_handle_t* handle);

private:
    string              _ip;
    uint16_t            _port;
    sockaddr_in         _addr;

    uv_loop_t           *_loop =  uv_default_loop();
    uv_tcp_t            *_server = new uv_tcp_t;
    const int32_t      _DefaultBackLog = 128;
};
}
#endif // TCPSERVER_H
