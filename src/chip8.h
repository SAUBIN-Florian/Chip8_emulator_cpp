#pragma once

#include <iostream>
#include <ios>
#include <cstdint>
#include <cstring>

//Register's opcode functions
//SRC: https://chip8.gulrak.net/
void OP_0nnn();
void OP_00E0();
void OP_00EE();
void OP_1nnn();
void OP_2nnn();
void OP_3xnn();
void OP_4xnn();
void OP_5xy0();
void OP_6xnn();
void OP_7xnn();
void OP_8xy0();
void OP_8xy1();
void OP_8xy2();
void OP_8xy3();
void OP_8xy4();
void OP_8xy5();
void OP_8xy6();
void OP_8xy7();
void OP_8xyE();
void OP_9xy0();
void OP_Annn(uint16_t* opcode, uint16_t* I, uint16_t* PC);
void OP_Bnnn();
void OP_Cxnn();
void OP_Dxyn();
void OP_Ex9E();
void OP_ExA1();
void OP_Fx07();
void OP_Fx0A();
void OP_Fx15();
void OP_Fx18();
void OP_Fx1E();
void OP_Fx29();
void OP_Fx33();
void OP_Fx55();
void OP_Fx65();

uint8_t fontset[80] = { 
	0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

struct Chip8 {
	//SRC: https://www.cs.columbia.edu/~sedwards/classes/2016/4840-spring/designs/Chip8.pdf
	uint16_t opcode;
	uint8_t  memory[4096];
	uint8_t  V[16];		   //Registers 0 to F
	uint16_t I;            //Index Register
	uint16_t PC;           //Program Counter
	uint8_t  gfx[64*32];   //Pixels array
	uint8_t  delay_timer;
	uint8_t  sound_timer;
	uint16_t stack[16];
	uint8_t  SP;		   //Stack Pointer
	uint8_t key[16];

	explicit Chip8() {
		opcode = 0x0000;
		memset(memory, 0, 4096);
		memset(V, 0, 16);
		I = 0;
		PC = 0x200;
		memset(gfx, 0, 64*32);
		delay_timer = 0;
		sound_timer = 0;
		memset(stack, 0, 16);
		SP = 0;
	}

	void emulate_cycle() {
		opcode = memory[PC] << 8 | memory[PC + 1];

		switch (opcode & 0xF000) {
		case 0xA000:
			OP_Annn(&opcode, &I, &PC);
			break;

		default:
			std::cout << "Unknown opcode: 0x" << std::hex << opcode << "\n";
		}

		if (delay_timer > 0) --delay_timer;
		if (sound_timer == 1) {
			std::cout << "BEEP!\n";
			--sound_timer;
		}
	}
};

