#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>
#include <sys/utsname.h>

#include "colors.h"

std::string catch_kerver() {
    struct utsname buffer;

    errno = 0;
    if (uname(&buffer) != 0) {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    return buffer.release;
}

void kernel() {
    std::string kernel_version = catch_kerver();
    std::cout << " " << BLUE << "ker" << RESET << " " << kernel_version << std::endl;
}

