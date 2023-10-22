#include <iostream>
#include <cstring>

void prbannerrow(int row);
char (*get_banner())[50];

void header(void);
void os(void);
void kernel(void);
void ram(void);
void hostname(void);
void disk(void);

void display_colorpalette(void);

int main() {
    char (*banner)[50] = get_banner();
    size_t max_len = 0;
    for (int i = 0; i < 3; i++)
        if (strlen(banner[i]) > max_len)
            max_len = strlen(banner[i]);
    
    std::cout << "\n";

    
    header();

    // rendering the aligned functions relative to the banner size.
    #define ALIGNED_SIZE 3
    void (*aligneds[ALIGNED_SIZE])() = {os, kernel, hostname};
    for (int i = 0; i < ALIGNED_SIZE; i++) {
        // prbannerrow(i);
        aligneds[i]();
    }

    // rendering the misaligned ones
    #define MISALIGNED_SIZE 2

    void (*misaligneds[MISALIGNED_SIZE])() = {ram, disk};
    for (int i = 0; i < MISALIGNED_SIZE; i++) {
        misaligneds[i]();
    }
    
    std::cout << " ";
    display_colorpalette();
    
    std::cout << "\n";

    return 0;
}
