#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "colors.h"

const char *format_bytes(long long bytes) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB"};
    size_t i = 0;
    double val = static_cast<double>(bytes);
    while (val >= 1024.0 && i < sizeof(units) / sizeof(units[0])) {
        val /= 1024.0;
        i++;
    }

    static char buf[32];
    sprintf(buf, "%.2f %s", val, units[i]);
    return buf;
}

void ram() {
    std::cout << " " << MAGENTA << "ram" << RESET << " ";

    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp == nullptr) {
        std::cerr << "Failed to open /proc/meminfo\n";
        exit(1);
    }

    long long total_mem = 0,
              free_mem = 0,
              used_mem = 0;

    char line[256];
    while (fgets(line, sizeof(line), fp) != nullptr) {
        if (sscanf(line, "MemTotal: %lld kB", &total_mem) == 1) {
            total_mem *= 1024;
        } else if (sscanf(line, "MemAvailable: %lld kB", &free_mem) == 1) {
            free_mem *= 1024;
        }
    }

    used_mem = total_mem - free_mem;

    std::string str_usedmem = format_bytes(used_mem);
    std::string str_totalmem = format_bytes(total_mem);

    std::cout << str_usedmem << " / " << str_totalmem << std::endl;
}

