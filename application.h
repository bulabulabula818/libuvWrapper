#ifndef APPLICATION_H
#define APPLICATION_H

#include <uv.h>

namespace UW {
class Application
{
public:
    Application();
    ~Application();
    int exec();

    void stop();

private:
    uv_loop_t *_loop = uv_default_loop();
};

}



#endif // APPLICATION_H
