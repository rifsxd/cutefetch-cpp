#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>

#include "colors.h"
#include "hostname.h"

#define DEFAULT_HOSTNAME "localhost"

std::string get_hostname() {
    char hostname[1024];
    gethostname(hostname, 1023);
    return std::string(hostname);
}

void hostname() {
    std::string host = get_hostname();
    std::cout << " " << CYAN << "hs" << RESET << " " << host << std::endl;
}

