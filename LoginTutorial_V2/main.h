#define CURL_STATICLIB
#pragma comment (lib, "curl/libcurl_a_debug.lib")

#include <iostream>
#include "curl/curl.h"

std::string LoginOrSignup(std::string uname, std::string pass, bool opt);