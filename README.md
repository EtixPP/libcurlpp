# README #

### libcurlpp ###
This is a simple libcurl C++ wrapper.

### Simple example ###
```
#!c++
#include <iostream>
#include <string>

#include "curl/curl.hpp"

int main()
{
    curl::global::init();

    std::string buffer;

    try
    {
        curl::Easy request;

        request.setOpt(CURLOPT_URL, "http://www.example.com");
        request.setOpt(CURLOPT_WRITEDATA, &buffer);
        request.setOpt(CURLOPT_WRITEFUNCTION, curl::write::toString);

        request.perform();
    }
    catch (const curl::Exception& e)
    {
        std::cerr << "Error: " << e.what() << ".\n";
        return 1;
    }

    std::cout << "Content: " << buffer << std::endl;

    curl::global::cleanup();
}
```


### License ###
[Same as libcurl](http://curl.haxx.se/docs/copyright.html)

### To-Do ###
* Write a documentation
* Add template specializations for curl::form, curl::header and std::string for the curl::X::set_opt<T>() methods
