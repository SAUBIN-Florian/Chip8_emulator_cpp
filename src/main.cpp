#include <cstdio>

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_events.h>

#include "./chip8.h"

static const int WIDTH = 512;
static const int HEIGHT = 256;

int main() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
		fprintf(stderr, "Can't initialize SDL2...\n");
		return -1;
	}

	SDL_Window* window = SDL_CreateWindow("Emulator Chip-8", 0, 0, WIDTH, HEIGHT, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

	//Chip8 initialization
	Chip8 chip8{};

	bool is_running = true;
	while (is_running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) is_running = false;
		}

		chip8.emulate_cycle();
		SDL_RenderClear(renderer);

		
		SDL_RenderPresent(renderer);
	}


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
