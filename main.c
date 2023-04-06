

#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#include "chip8.h"
extern int should_quit;

int main(int argc, char** argv) {
    if (argc != 2) {
        error("usage: emulator rom.ch8");
        return 1;
    }

    puts("[PENDING] Initializing CHIP-8 arch...");
    initialise();
    puts("[OK] Done!");

    char* rom_filename = argv[1];
    printf("[PENDING] Loading rom %s...\n", rom_filename);

    int error = loadrom(rom_filename);
    if(error) {
        if (error == -1) {
            error("[FAILED] fread() failure: the return value was not equal to the rom file size.");
        } else {
            perror("Error while loading rom");
        }
        return 1;
    }

    puts("[OK] Rom loaded successfully!");

    init_display();
    puts("[OK] Display successfully initialized.");

    while (!should_quit) {
        emulate();
        sdl_ehandler(keypad);

        if (drawflag) {
            draw(graphics);
        }

        //delay to emulate chip-8's clock speed.
        usleep(1500);
    }

    stop_display();
    return 0;
}