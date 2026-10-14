CXX= clang++
CXXFLAGS= -Wall -Wextra -Wpedantic -std=c++20 `pkg-config --cflags sdl2`
LIBS= `pkg-config --libs sdl2`
SRC= ./src/main.cpp
OUT= ./build/emu_chip8

compile:
	@$(CXX) $(CXXFLAGS) -o $(OUT) $(SRC) $(LIBS)

run: compile
	@$(OUT)
