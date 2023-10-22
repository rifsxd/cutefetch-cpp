#include <iostream>
#include <string>
#include <cstdlib>
#include <unistd.h>
#include <pwd.h>

#include "colors.h"
#include "hostname.h"

std::string whoami() {
    struct passwd *passwd = getpwuid(getuid());
    return passwd->pw_name;
}

void header() {
    std::string username = whoami();
    std::string hostname = get_hostname();

    std::cout << " " << CYAN << username << BLUE << "@" << MAGENTA << hostname << RESET << std::endl;
}
