//============================================================================
// Name        : CIRCLE
// Author      : Ilya Okulov
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================
#include <iostream>
#include <memory>
#include <cmath>
#include <algorithm>
#include <SDL2/SDL.h>


constexpr double Pi = acos(-1.);
#ifdef _WIN32
#include <SDL2/SDL_main.h>
#endif
constexpr int WIDTH = 1366, HEIGHT = 768;
int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	auto win = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
						"Circle Bresenham",
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
						WIDTH, HEIGHT,
						SDL_WINDOW_SHOWN),
			SDL_DestroyWindow);

	if (win == nullptr) {
		std::cerr << "При создании окна произошла ошибка: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	auto ren = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(win.get(), -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);

	if (ren == nullptr) {
		std::cerr << "При создании renderer-а произошла ошибка: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	SDL_Event event;

	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) return 0;
		}

		SDL_SetRenderDrawColor(ren.get(), 255, 255, 255, 255);
		SDL_RenderClear(ren.get());
		SDL_SetRenderDrawColor(ren.get(), 0, 0, 0, 155);

//Построение окружности алгоритмом Брезенхема
		int r=250; //радиус
		int X1=WIDTH/2; //координаты центра по X
		int Y1=HEIGHT/2; //координаты центра по Y
		int x = 0; //начальная точка для рисование по X
		int y = r; //начальная точка для рисования по y
	    int delta = 1 - 2 * r; //значение дельты
		int error = 0; //первоначальное значение ошибки
		while (y >= 0){ //цикл while для рисования
			SDL_RenderDrawPoint(ren.get(), X1 + x, Y1 + y); //рисование первой точки
			SDL_RenderDrawPoint(ren.get(), X1 + x, Y1 - y); //рисование второй точки
			SDL_RenderDrawPoint(ren.get(), X1 - x, Y1 + y); //рисование третей точки
			SDL_RenderDrawPoint(ren.get(), X1 - x, Y1 - y); //рисование четвертой точки
			error = 2 * (delta + y) - 1; //нахождение ошибки, котороая означает вертикальное расстояние между текущим значением y и точным значением y для текущего x
			//Далее идет сравнение дельты и ошибки
			if ((delta < 0) && (error <= 0)){
				delta += 2 * ++x + 1;
				continue;}
			if ((delta > 0) && (error > 0)){
				delta -= 2 * --y + 1;
				continue;}
			delta += 2 * (++x - --y);
		}
		SDL_RenderPresent(ren.get());
	}
	return 0;

}
