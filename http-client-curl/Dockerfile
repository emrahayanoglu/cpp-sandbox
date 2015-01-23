FROM saltstack/debian-7-minimal

RUN apt-get -y install\
    git \
    cmake make \
    clang libcurl4-openssl-dev \
        && apt-get clean

RUN cd /tmp && git clone https://github.com/ichigotake/cpp-sandbox

# TODO: install gcc-4.8
RUN cd /tmp/cpp-sandbox/http-client-curl && perl -i -ple 's/\-std\=c\+\+11//' CMakeLists.txt && cat CMakeLists.txt

RUN cd /tmp/cpp-sandbox/http-client-curl && mkdir build && cd build && cmake .. && make && ./http_client_curl
