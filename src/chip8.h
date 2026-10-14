#pragma once

#include <cstdio>
#include <ios>
#include <cstdint>
#include <cstring>

// Opcode functions declarations
// src: https://chip8.gulrak.net/
void OP_0nnn();
void OP_00E0(uint8_t* gfx, uint16_t* pc, bool* flag);
void OP_00EE(uint16_t* stack, uint16_t* pc, uint8_t* sp);
void OP_1nnn(uint16_t* opcode, uint16_t* pc);
void OP_2nnn(uint16_t* opcode, uint16_t* stack, uint16_t* pc, uint8_t* sp);
void OP_3xnn(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_4xnn(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_5xy0(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_6xnn(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_7xnn(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_8xy0(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_8xy1(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_8xy2(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_8xy3(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_8xy4(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_8xy5(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_8xy6(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_8xy7(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_8xyE(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_9xy0(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_Annn(uint16_t* opcode, uint16_t* i, uint16_t* pc);
void OP_Bnnn(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_Cxnn(uint16_t* opcode, uint16_t* v, uint16_t* pc);
void OP_Dxyn(uint16_t* opcode, uint8_t* gfx, uint8_t* memory, uint16_t* v, uint16_t* pc, uint16_t* i, bool* flag);
void OP_Ex9E(uint16_t* opcode, uint16_t* v, uint16_t* key, uint16_t* pc);
void OP_ExA1(uint16_t* opcode, uint16_t* v, uint16_t* key, uint16_t* pc);
void OP_Fx07(uint16_t* opcode, uint16_t* v, uint8_t* delay, uint16_t* pc);
void OP_Fx0A(uint16_t* opcode, uint16_t* v, uint16_t* key, uint16_t* pc);
void OP_Fx15(uint16_t* opcode, uint16_t* v, uint8_t* delay, uint16_t* pc);
void OP_Fx18(uint16_t* opcode, uint16_t* v, uint8_t* sound, uint16_t* pc);
void OP_Fx1E(uint16_t* opcode, uint16_t* v, uint16_t* i, uint16_t* pc);
void OP_Fx29(uint16_t* opcode, uint16_t* v, uint16_t* i, uint16_t* pc);
void OP_Fx33(uint16_t* opcode, uint16_t* v, uint8_t* memory, uint16_t* i, uint16_t* pc);
void OP_Fx55(uint16_t* opcode, uint16_t* v, uint8_t* memory, uint16_t* i, uint16_t* pc);
void OP_Fx65(uint16_t* opcode, uint16_t* v, uint8_t* memory, uint16_t* i, uint16_t* pc);

static uint8_t FONTSET[80] = { 
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
	// src: https://www.cs.columbia.edu/~sedwards/classes/2016/4840-spring/designs/Chip8.pdf
	// note: they are some cryptic names (i, pc...) because I followed the base architecture (^ see src ^)
	uint16_t opcode;
	uint8_t  memory[4096];
	uint8_t  v[16];		   //Registers 0 to F
	uint16_t i;            //Index Register
	uint16_t pc;           //Program Counter
	uint8_t  gfx[64*32];   //Pixels array
	uint8_t  delay_timer;
	uint8_t  sound_timer;
	uint16_t stack[16];
	uint8_t  sp;		   //Stack Pointer
	uint8_t  key[16];
	bool     draw_flag;

	explicit Chip8() {
		opcode = 0x0000;
		memset(memory, 0, 4096);
		memset(v, 0, 16);
		i = 0;
		pc = 0x200;
		memset(gfx, 0, 64*32);
		delay_timer = 0;
		sound_timer = 0;
		memset(stack, 0, 16);
		sp = 0;
		draw_flag = true;
	}

	void emulate_cycle() {
		opcode = memory[pc] << 8 | memory[pc + 1];

		switch (opcode & 0xF000) {
		case 0xA000:
			OP_Annn(&opcode, &i, &pc);
			break;

		default:
			printf("Don't recognize opcode 0x%X\n", opcode);
		}

		if (delay_timer > 0) --delay_timer;
		if (sound_timer == 1) {
			printf("BEEP!\n");
			--sound_timer;
		}
	}
};

// Opcode functions implementations
