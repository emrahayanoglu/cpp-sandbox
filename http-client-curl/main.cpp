#include <iostream>
#include <curl/curl.h>
#include "picojson.h"

#define MAX_BUF 65535

using namespace std;

static char wr_buf[MAX_BUF];
static int wr_index = 0;

size_t handle_response(void *buffer, size_t size, size_t nmemb, void *userp) {
    size_t segsize = size * nmemb;

    if ((wr_index + segsize) > MAX_BUF) {
        *(int *)userp = 1;
        return 0;
    }

    memcpy((void *)&wr_buf[wr_index], buffer, (size_t)segsize);

    wr_index += segsize;

    wr_buf[wr_index] = '\0';
    return segsize;
}

int main() {
    CURL *curl;
    CURLcode ret;
    char error[256];

    curl = curl_easy_init();
    if (curl == NULL) {
        fprintf(stderr, "curl_easy_init");
    }

    curl_easy_setopt(curl, CURLOPT_URL, "http://time.jsontest.com/");
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, handle_response);

    ret = curl_easy_perform(curl);
    if (ret != CURLE_OK) {
        wcout << error << endl;
    } else {
        picojson::value v;
        std::string err;
        char *json = wr_buf;
        picojson::parse(v, json, json + strlen(json), &err);
        picojson::object &o = v.get<picojson::object>();
        cout << "time: " << o["time"] << endl;
    }

    curl_easy_cleanup(curl);

    return ret;
}