#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "colors.h"

std::string get_pretty_name() {
    std::ifstream file("/etc/os-release");
    if (!file.is_open()) {
        std::cerr << "Error opening /etc/os-release\n";
        exit(1);
    }

    std::string osname;
    std::string line;
    std::string prefix = "PRETTY_NAME";

    while (std::getline(file, line)) {
        if (line.compare(0, prefix.length(), prefix) == 0) {
            size_t pos = line.find('"');
            if (pos != std::string::npos) {
                osname = line.substr(pos + 1, line.find_last_of('"') - pos - 1);
            } else {
                osname = "Cannot get os.";
            }
        }
    }

    return osname;
}

void os() {
    std::string osname = get_pretty_name();
    std::cout << " " << GREEN << "os" << RESET << " " << osname << std::endl;
}

