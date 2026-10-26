#pragma once

#include <iostream>
#include <array>
#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <ctime>


// Opcode functions declarations
// src: https://chip8.gulrak.net/
void OP_00E0(std::array<uint8_t, 64*32>& gfx, uint16_t& pc, bool& flag);
void OP_00EE(std::array<uint16_t, 16>& stack, uint16_t& pc, uint8_t& sp);
void OP_1nnn(uint16_t& opcode, uint16_t& pc);
void OP_2nnn(uint16_t& opcode, std::array<uint16_t, 16>& stack, uint16_t& pc, uint8_t& sp);
void OP_3xnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_4xnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_5xy0(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_6xnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_7xnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_8xy0(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_8xy1(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_8xy2(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_8xy3(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_8xy4(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_8xy5(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_8xy6(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_8xy7(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_8xyE(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_9xy0(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_Annn(uint16_t& opcode, uint16_t& i, uint16_t& pc);
void OP_Bnnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_Cxnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc);
void OP_Dxyn(uint16_t& opcode, 
			 std::array<uint8_t, 64*32>& gfx, 
			 std::array<uint8_t, 4096>& memory, 
			 std::array<uint8_t, 16>& v, 
			 uint16_t& pc, 
			 uint16_t& i, 
			 bool& flag);
void OP_Ex9E(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 16>& key, uint16_t& pc);
void OP_ExA1(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 16>& key, uint16_t& pc);
void OP_Fx07(uint16_t& opcode, std::array<uint8_t, 16>& v, uint8_t& delay, uint16_t& pc);
void OP_Fx0A(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 16>& key, uint16_t& pc);
void OP_Fx15(uint16_t& opcode, std::array<uint8_t, 16>& v, uint8_t& delay, uint16_t& pc);
void OP_Fx18(uint16_t& opcode, std::array<uint8_t, 16>& v, uint8_t& sound, uint16_t& pc);
void OP_Fx1E(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& i, uint16_t& pc);
void OP_Fx29(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& i, uint16_t& pc);
void OP_Fx33(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 4096>& memory, uint16_t& i, uint16_t& pc);
void OP_Fx55(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 4096>& memory, uint16_t& i, uint16_t& pc);
void OP_Fx65(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 4096>& memory, uint16_t& i, uint16_t& pc);

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
	uint16_t				    opcode;
	std::array<uint8_t, 4096>   memory;
	std::array<uint8_t, 16>     v;		   
	uint16_t				    i;            
	uint16_t				    pc;           
	std::array<uint8_t, 64*32>  gfx;   	
	uint8_t						delay_timer;
	uint8_t						sound_timer;
	std::array<uint16_t, 16>    stack;
	uint8_t						sp;
	std::array<uint8_t, 16>     key;
	bool						draw_flag;

	explicit Chip8() {
		opcode = 0x0000;
		i = 0;
		pc = 0x200;
		delay_timer = 0;
		sound_timer = 0;
		sp = 0;
		draw_flag = true;

		// init randomness for Cxnn opcode instruction
		srand(time(NULL));
	}

	void emulate_cycle() {
		opcode = memory[pc] << 8 | memory[pc + 1];

		switch (opcode & 0xF000) {
			case 0x0000:
				switch (opcode & 0x000F) {
					case 0x0000: OP_00E0(gfx, pc, draw_flag); break;
					case 0x000E: OP_00EE(stack, pc, sp); break;
				}
				break;
			case 0x1000: OP_1nnn(opcode, pc); break;
			case 0x2000: OP_2nnn(opcode, stack, pc, sp); break;
			case 0x3000: OP_3xnn(opcode, v, pc); break;
			case 0x4000: OP_4xnn(opcode, v, pc); break;
			case 0x5000: OP_5xy0(opcode, v, pc); break;
			case 0x6000: OP_6xnn(opcode, v, pc); break;
			case 0x7000: OP_7xnn(opcode, v, pc); break;
			case 0x8000: 
				switch (opcode & 0x000F) {
					case 0x0000: OP_8xy0(opcode, v, pc); break;
					case 0x0001: OP_8xy1(opcode, v, pc); break;
					case 0x0002: OP_8xy2(opcode, v, pc); break;
					case 0x0003: OP_8xy3(opcode, v, pc); break;
					case 0x0004: OP_8xy4(opcode, v, pc); break;
					case 0x0005: OP_8xy5(opcode, v, pc); break;
					case 0x0006: OP_8xy6(opcode, v, pc); break;
					case 0x0007: OP_8xy7(opcode, v, pc); break;
					case 0x000E: OP_8xyE(opcode, v, pc); break;
				}
				break;
			case 0x9000: OP_9xy0(opcode, v, pc); break;
			case 0xA000: OP_Annn(opcode, i, pc); break;
			case 0xB000: OP_Bnnn(opcode, v, pc); break;
			case 0xC000: OP_Cxnn(opcode, v, pc); break;
			case 0xD000: OP_Dxyn(opcode, gfx, memory, v, pc, i, draw_flag); break;
			case 0xE000: 
				switch (opcode & 0x00FF) {
					case 0X009E: OP_Ex9E(opcode, v, key, pc); break;
					case 0X00A1: OP_ExA1(opcode, v, key, pc); break;
				}
				break;
			case 0xF000:
				switch (opcode & 0x00FF) {
					case 0x0007: OP_Fx07(opcode, v, delay_timer, pc); break;
					case 0x000A: OP_Fx0A(opcode, v, key, pc); break;
					case 0x0015: OP_Fx15(opcode, v, delay_timer, pc); break;
					case 0x0018: OP_Fx18(opcode, v, sound_timer, pc); break;
					case 0x001E: OP_Fx1E(opcode, v, i, pc); break;
					case 0x0029: OP_Fx29(opcode, v, i, pc); break;
					case 0x0033: OP_Fx33(opcode, v, memory, i, pc); break;
					case 0x0055: OP_Fx55(opcode, v, memory, i, pc); break;
					case 0x0065: OP_Fx65(opcode, v, memory, i, pc); break;
				}
				break;
			default:
				std::cout << "Unknown opcode: 0x"  << std::hex << opcode << std::endl;
		}
	
		if (delay_timer > 0) --delay_timer;
		if (sound_timer == 1) --sound_timer;
	}

	// TODO: implement this later
	void debug_render() {}
	bool load_game(const char* filename) {}
};

// Opcode functions implementations
void OP_00E0(std::array<uint8_t, 64*32>& gfx, uint16_t& pc, bool& flag) {
	for (auto& px: gfx) {
		px = 0x0;
	}
	flag = true;
	pc += 2;
}

void OP_00EE(std::array<uint16_t, 16>& stack, uint16_t& pc, uint8_t& sp) {
	sp -= 1;
	pc = stack[(size_t)sp];
	pc += 2;
}

void OP_1nnn(uint16_t& opcode, uint16_t& pc) {
	pc = opcode & 0x0FFF;
}

void OP_2nnn(uint16_t& opcode, std::array<uint16_t, 16>& stack, uint16_t& pc, uint8_t& sp) {
	size_t idx = (size_t)sp;
	stack[idx] = pc;
	sp += 1;
	pc = opcode & 0x0FFF;
}

void OP_3xnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00FF) >> 4;

	if (v[idx0] == v[idx1]) {
		pc += 4;
	} else {
		pc += 2;
	}
}

void OP_4xnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00FF) >> 4;

	if (v[idx0] != v[idx1]) {
		pc += 4;
	} else {
		pc += 2;
	}
}

void OP_5xy0(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00F0) >> 4;

	if (v[idx0] == v[idx1]) {
		pc += 4;
	} else {
		pc += 2;
	}
}

void OP_6xnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx = (opcode & 0x00F0) >> 8;
	v[idx] = (opcode & 0x00FF);
	pc += 2;
}

void OP_7xnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx = (opcode & 0x00F0) >> 8;
	v[idx] += (opcode & 0x00FF);
	pc += 2;
}

void OP_8xy0(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00F0) >> 4;

	v[idx0] = v[idx1];
	pc += 2;
}

void OP_8xy1(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00F0) >> 4;

	v[idx0] |= v[idx1];
	pc += 2;
}

void OP_8xy2(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00F0) >> 4;

	v[idx0] &= v[idx1];
	pc += 2;
}

void OP_8xy3(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00F0) >> 4;

	v[idx0] ^= v[idx1];
	pc += 2;
}

void OP_8xy4(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00F0) >> 4;

	if (v[idx0] < v[idx1]) {
		v[0xF] = 0;
	} else {
		v[0xF] = 1;
	}

	v[idx0] += v[idx1];
	pc += 2;
}

void OP_8xy5(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00F0) >> 4;

	if (v[idx0] < v[idx1]) {
		v[0xF] = 1;
	} else {
		v[0xF] = 0;
	}

	v[idx0] -= v[idx1];
	pc += 2;
}

void OP_8xy6(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;
	v[0xF] = v[idx] & 0x1;
	v[idx] >>= 1;
	pc += 2;
}

void OP_8xy7(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00F0) >> 4;

	if (v[idx0] > v[idx1]) {
		v[0xF] = 0;
	} else {
		v[0xF] = 1;
	}

	v[idx0] = v[idx1] - v[idx0];
	pc += 2;
}

void OP_8xyE(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;
	v[0xF] = v[idx] >> 7;
	v[idx] <<= 1;
	pc += 2;
}

void OP_9xy0(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00F0) >> 4;

	if (v[idx0] != v[idx1]) {
		pc += 4;
	} else {
		pc += 2;
	}
}

void OP_Annn(uint16_t& opcode, uint16_t& i, uint16_t& pc) {
	i = opcode & 0x0FFF;
	pc += 2;
}

void OP_Bnnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	pc = (opcode & 0x0FFF) + v[0];
}

void OP_Cxnn(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;
	
	v[idx] = (rand() % 0xFF) & (opcode & 0x00FF);
	pc += 2;
}

void OP_Dxyn(uint16_t& opcode, 
			 std::array<uint8_t, 64*32>& gfx, 
			 std::array<uint8_t, 4096>& memory, 
			 std::array<uint8_t, 16>& v, 
			 uint16_t& pc, 
			 uint16_t& i, 
			 bool& flag)
{
	size_t idx0 = (opcode & 0x0F00) >> 8;
	size_t idx1 = (opcode & 0x00F0) >> 4;
	
	// x and y pixel coordinates
	uint16_t x = v[idx0];
	uint16_t y = v[idx1];
	// height and pixel value to be draw
	uint16_t h = opcode & 0x000F;
	uint16_t pixel = 0x00;

	v[0xF] = 0;
	for (size_t yline = 0; yline < h; yline++) {
		pixel = memory[i + yline];
		for (size_t xline = 0; xline < 8; xline++) {
			if ((pixel & (0x80 >> xline)) != 0) {
				if (gfx[(x + xline + ((y + yline) * 64)) != 0]) {
					v[0xF] = 1;
				}
				gfx[(x + xline + ((y + yline) * 64))] ^= 1;
			}
		}
	}

	flag = true;
	pc += 2;
}

void OP_Ex9E(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 16>& key, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;

	if (key[v[idx]] != 0) {
		pc += 4;
	} else {
		pc += 2;
	}
}

void OP_ExA1(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 16>& key, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;

	if (key[v[idx]] == 0) {
		pc += 4;
	} else {
		pc += 2;
	}
}

void OP_Fx07(uint16_t& opcode, std::array<uint8_t, 16>& v, uint8_t& delay, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;

	v[idx] = delay;
	pc += 2;
}

void OP_Fx0A(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 16>& key, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;
	
	bool key_input = false;

	for (size_t i = 0; i < 16; i++) {
		if (key[i] != 0) {
			v[idx] = i;
			key_input = true;
		}
	}

	// if key isn't recognized don't increment to the next instruction
	// and retry the function with the same instruction
	if (!key_input) return;
	pc += 2;
}

void OP_Fx15(uint16_t& opcode, std::array<uint8_t, 16>& v, uint8_t& delay, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;
	delay = v[idx];
	pc += 2;
}

void OP_Fx18(uint16_t& opcode, std::array<uint8_t, 16>& v, uint8_t& sound, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;
	sound = v[idx];
	pc += 2;
}

void OP_Fx1E(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& i, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;
	
	if (i + v[idx] > 0xFFF) {
		v[0xF] = 1;
	} else {
		v[0xF] = 0;
	}

	i += v[idx];
	pc += 2;
}

void OP_Fx29(uint16_t& opcode, std::array<uint8_t, 16>& v, uint16_t& i, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;
	i = v[idx] * 0x5;
	pc += 2;
}

void OP_Fx33(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 4096>& memory, uint16_t& i, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;
	memory[i] = v[idx] / 100;
	memory[i + 1] = (v[idx] / 10) % 10;
	memory[i + 2] = (v[idx] % 100) % 10;
	pc += 2;
}

void OP_Fx55(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 4096>& memory, uint16_t& i, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;

	for (size_t j = 0; j <= idx; j++) {
		memory[i + j] = v[j];
	}

	i += idx + 1;
	pc += 2;
}

void OP_Fx65(uint16_t& opcode, std::array<uint8_t, 16>& v, std::array<uint8_t, 4096>& memory, uint16_t& i, uint16_t& pc) {
	size_t idx = (opcode & 0x0F00) >> 8;

	for (size_t j = 0; j <= idx; j++) {
		v[j] = memory[i + j];
	}

	i += idx + 1;
	pc += 2;
}
