#include "BasicController.h"

BasicController::BasicController(const std::string& naddress,const std::string& nport) {
   this->endpointBuilder.set_host(naddress);
   this->endpointBuilder.set_port(nport);
   this->endpointBuilder.set_scheme("http");
}
BasicController::~BasicController() {

}

void BasicController::setEndpoint(const std::string& mount_point)
{
    endpointBuilder.set_path(mount_point);
    _listener = http_listener(endpointBuilder.to_uri());
}
std::string BasicController::endpoint() const {
    return _listener.uri().to_string();
}
pplx::task<void> BasicController::accept() {
    initRestOpHandlers();
    return _listener.open();
}
pplx::task<void> BasicController::shutdown() {
    return _listener.close();
}
std::vector<utility::string_t> BasicController::requestPath(const http_request& message)
{
    auto relativePath = uri::decode(message.relative_uri().path());
    return uri::split_path(relativePath);
}
