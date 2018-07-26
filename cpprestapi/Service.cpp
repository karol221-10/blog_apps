#include "Service.h"
#include <string>
using std::string;
void Service::initRestOpHandlers() {
	_listener.support(methods::GET,std::bind(&Service::handleGet,this,std::placeholders::_1));
	_listener.support(methods::PUT,std::bind(&Service::handlePut,this,std::placeholders::_1));
}

float Service::calculateSum() {
    float sum = 0;
    for(unsigned int i = 0;i<numbers.size();i++) {
        sum+=numbers[i];
    }
    return sum;
}
void Service::handleGet(http_request message) {
    vector<string> path = requestPath(message);
    if(path.empty()) {
        vector <json::value> jsonNumbers;
        for(unsigned int i = 0;i<numbers.size();i++) {
            json::value number;
            number["number"] = json::value::number(numbers[i]);
            jsonNumbers.push_back(number);
        }
        json::value generatedNumberList;
        generatedNumberList["numbers"] = json::value::array(jsonNumbers);
        message.reply(status_codes::OK,generatedNumberList);
    }
    else {
        if(path[0]=="avg") {
            float avg = calculateSum()/numbers.size();
            json::value number;
            number["avg"] = json::value::number(avg);
            message.reply(status_codes::OK,number);
        }
        else if(path[0]=="sum") {
            float sum = calculateSum();
            json::value number;
            number["sum"] = json::value::number(sum);
            message.reply(status_codes::OK,number);
        }
        else {
            message.reply(status_codes::BadRequest);
        }
    }
}
void Service::handlePut(http_request message) {
    message.extract_json().then([=](pplx::task<json::value> task)
    {
        try
        {
            json::value val = task.get();
            int number = val[U("number")].as_number().to_int32();
            numbers.push_back(number);
            message.reply(status_codes::OK);
        }
        catch(std::exception& e) {
            message.reply(status_codes::BadRequest);
        }
    });
}
