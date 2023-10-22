#include <iostream>
#include <cstdlib>
#include <sys/statvfs.h>

#include "colors.h"

const char *format_bytes(long long bytes);

void disk() {
    std::cout << " " << RED << "dsk" << RESET << " ";

    const char *mount_point = "/";
    struct statvfs fs_info;
    if (statvfs(mount_point, &fs_info) != 0) {
        std::cerr << "Failed to get file system info\n";
        exit(1);
    }

    long long block_size = fs_info.f_frsize;

    long long total_blocks = fs_info.f_blocks;
    long long free_blocks = fs_info.f_bfree;
    long long used_blocks = total_blocks - free_blocks;

    long long total_space = total_blocks * block_size;
    long long used_space = used_blocks * block_size;

    std::string strtotal = format_bytes(total_space);
    std::string strused = format_bytes(used_space);

    std::cout << strused << " / " << strtotal << std::endl;
}

