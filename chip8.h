#ifndef CHIP8_H_
#define CHIP8_H_


unsigned short opcode;
unsigned char memory[4096];
unsigned char V[16];

unsigned short I;
unsigned short pc;
unsigned char graphics[64*32];
unsigned char delay;
unsigned char sound;
unsigned char sp;
unsigned char stack[16];
unsigned char fontset[80];
unsigned char drawflag;
unsigned char soundflag;
unsigned char keypad[16];

void initialise();
int loadrom(char* filename);
void emulate();


void init_display();
void draw(unsigned char* display);
void sdl_ehandler(unsigned char* keypad);
void stop_display();



#define error(...) fprintf(stderr, __VA_ARGS__) 

#endif