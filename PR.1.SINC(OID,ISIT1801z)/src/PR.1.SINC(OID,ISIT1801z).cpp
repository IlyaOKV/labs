//============================================================================
// Name        : SINC
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
						"Sinc(x)",
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
		SDL_SetRenderDrawColor(ren.get(), 0, 0, 0, 0);

//вправо
		auto GetX = [&](double x) { return int((x+30)/60*WIDTH); }; //получение массива значений по x
		auto GetY = [&](double y) { return int((-y / 1 + 1) * (HEIGHT / 2)); };//получение массива значений по y
		for(double i = 0; i < 60; i += 0.002) {//построение точек циклом for
			double X = GetX(i); //координата по X
			double Y = GetY(sin(i)/i); //координата по Y
			SDL_RenderDrawPoint(ren.get(), X, Y); //само рисование точки с этими координатами
			}
//влево
		auto GetX2 = [&](double x) { return int((x+30)/60*WIDTH); };
	    auto GetY2 = [&](double y) { return int((-y / 1 + 1) * (HEIGHT / 2)); };
	    for(double i = 0; i > -60; i -= 0.002) {
	    	double X = GetX2(i);
	    	double Y = GetY2(sin(i)/i);
	    	SDL_RenderDrawPoint(ren.get(), X, Y);
	    	}
		SDL_RenderPresent(ren.get());
	}
	return 0;

}
