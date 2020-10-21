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
		std::cerr << "��� �������� ���� ��������� ������: " <<
				SDL_GetError() << std::endl;
		return 1;
	}

	auto ren = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(win.get(), -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC),
			SDL_DestroyRenderer);

	if (ren == nullptr) {
		std::cerr << "��� �������� renderer-� ��������� ������: " <<
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

//���������� ���������� ���������� ����������
		int r=250; //������
		int X1=WIDTH/2; //���������� ������ �� X
		int Y1=HEIGHT/2; //���������� ������ �� Y
		int x = 0; //��������� ����� ��� ��������� �� X
		int y = r; //��������� ����� ��� ��������� �� y
	    int delta = 1 - 2 * r; //�������� ������
		int error = 0; //�������������� �������� ������
		while (y >= 0){ //���� while ��� ���������
			SDL_RenderDrawPoint(ren.get(), X1 + x, Y1 + y); //��������� ������ �����
			SDL_RenderDrawPoint(ren.get(), X1 + x, Y1 - y); //��������� ������ �����
			SDL_RenderDrawPoint(ren.get(), X1 - x, Y1 + y); //��������� ������ �����
			SDL_RenderDrawPoint(ren.get(), X1 - x, Y1 - y); //��������� ��������� �����
			error = 2 * (delta + y) - 1; //���������� ������, �������� �������� ������������ ���������� ����� ������� ��������� y � ������ ��������� y ��� �������� x
			//����� ���� ��������� ������ � ������
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
