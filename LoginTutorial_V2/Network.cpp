#include "main.h"


static int writerFunction(char* data, size_t size, size_t nmemb, std::string *writerData){
	if (writerData == NULL)
		return 0;
	writerData->append(data, size * nmemb);

	return size * nmemb;
}


std::string LoginOrSignup(std::string uname, std::string pass, bool opt) {

	//POST //

	CURL* curl = nullptr;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl) {
		if (opt){
			curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/files/login.php");
		}else {
			curl_easy_setopt(curl, CURLOPT_URL, "http://localhost/files/signup.php");
		}
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "username=" + uname + "&password=" + pass);

		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
			return "-";
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();


	// READ //

	std::string response;
	std::string path = "";
	if (opt) {
		path = "http://localhost/files/login.php?username=" + uname + "&password=" + pass;
	}
	else {
		path = "http://localhost/files/signup.php?username=" + uname + "&password=" + pass;
	}

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, path);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writerFunction);
		CURLcode code = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();

	return response;
}