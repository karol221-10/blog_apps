#ifndef BASICCONTROLLER_H_INCLUDED
#define BASICCONTROLLER_H_INCLUDED
#include <cpprest/http_listener.h>
#include <pplx/pplxtasks.h>
#include <string>
#include <cpprest/http_msg.h>
using namespace web;
using namespace http;
using namespace http::experimental::listener;

class BasicController {
    public:
    BasicController(const std::string& address,const std::string& port);
    ~BasicController();
    void setEndpoint(const std::string& mount_point);
    std::string endpoint() const;
    pplx::task<void> accept();
    pplx::task<void> shutdown();

    virtual void initRestOpHandlers() = 0;

    std::vector<utility::string_t> requestPath(const http_request & message);
    protected:
    http_listener _listener;
    private:
    uri_builder endpointBuilder;
};

#endif // BASICCONTROLLER_H_INCLUDED
