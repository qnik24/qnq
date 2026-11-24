#include "common/host.hpp"

int main(int argc, char** argv) {
    Host host;

    if(host.init())
        host.frame();
    else return 1;

    return 0;
}
