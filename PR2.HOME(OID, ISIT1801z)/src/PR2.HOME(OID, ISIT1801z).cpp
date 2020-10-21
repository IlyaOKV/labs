//============================================================================
// Name        : HOME
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

constexpr int WIDTH = 1366, HEIGHT = 768; //���������� ������� ����

int main(int, char**)
{
//������������� SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	auto win = std::shared_ptr<SDL_Window>( //SDL ��������� win � ��� ����������� �������������
//�������� ����
			SDL_CreateWindow(
						"Home... Sweet home", //��������� ����
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, //������������ ���� �� ��������
						WIDTH, HEIGHT, //�������, ������� �������� ����������� ������
						SDL_WINDOW_SHOWN), //����� ��������, �������� ����
			SDL_DestroyWindow); //���������� ����

//������������� ������ �������� ���� ��� ������ ����������f ����������� SDL
	if (win == nullptr) {
		std::cerr << "��� �������� ���� ��������� ������: " <<
				SDL_GetError() << std::endl;
		return 1; //���������� ��������� ��������
	}

//������������� �������� ����������
	auto ren = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(win.get(), -1, //1-������ ������ ��������� �� window (win), 2-����� ���������� (-1-��-���������)
					SDL_RENDERER_ACCELERATED | // ������������� ����������� ���������. |-��������� ���, �����������
					SDL_RENDERER_PRESENTVSYNC), // ������������� � ����������� ������
			SDL_DestroyRenderer); //����������� �������

//������������� ������ �������� ������� ��� ������ ����������f ����������� SDL
	if (ren == nullptr) {
		std::cerr << "��� �������� renderer-� ��������� ������: " <<
				SDL_GetError() << std::endl;
		return 1; //���������� ��������� ��������
	}

	SDL_Event event; //���������� �������

//����������� ����, ���������� ������� ���� ��� ����
	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) return 0;
		}

		SDL_SetRenderDrawColor(ren.get(), 0, 48, 64, 255); //������� ����� ����
		SDL_RenderClear(ren.get()); //������� ����
//�����
		SDL_SetRenderDrawColor(ren.get(), 0, 0, 115, 255);
		SDL_Rect r;
				    r.x = 350;
				    r.y = 350;
				    r.w = 251;
				    r.h = 201;
	    SDL_RenderFillRect(ren.get(), &r);
		SDL_SetRenderDrawColor(ren.get(), 255, 255, 255, 255);
		SDL_RenderDrawLine(ren.get(), 350, 350, 600, 350);
		SDL_RenderDrawLine(ren.get(), 600, 550, 350, 550);
		SDL_RenderDrawLine(ren.get(), 350, 550, 350, 350);
		SDL_RenderDrawLine(ren.get(), 600, 550, 600, 350);
		SDL_RenderDrawLine(ren.get(), 600, 350, 700, 250);
		SDL_RenderDrawLine(ren.get(), 700, 250, 700, 450);
		SDL_RenderDrawLine(ren.get(), 700, 450, 600, 550);
//�����
		SDL_RenderDrawLine(ren.get(), 350, 350, 475, 200);
		SDL_RenderDrawLine(ren.get(), 475, 200, 600, 350);
		SDL_RenderDrawLine(ren.get(), 475, 200, 600, 110);
		SDL_RenderDrawLine(ren.get(), 600, 110, 700, 250);
//����
		SDL_RenderDrawLine(ren.get(), 395, 395, 555, 395);
		SDL_RenderDrawLine(ren.get(), 555, 395, 555, 505);
		SDL_RenderDrawLine(ren.get(), 555, 505, 395, 505);
		SDL_RenderDrawLine(ren.get(), 395, 505, 395, 395);
		SDL_RenderDrawLine(ren.get(), 395, 505, 395, 395);
		SDL_RenderDrawLine(ren.get(), 395, 450, 555, 450);
		SDL_RenderDrawLine(ren.get(), 395, 450, 555, 450);
		SDL_RenderDrawLine(ren.get(), 475, 395, 475, 505);
//�����
		SDL_RenderDrawLine(ren.get(), 640, 510, 640, 390);
		SDL_RenderDrawLine(ren.get(), 640, 390, 670, 360);
		SDL_RenderDrawLine(ren.get(), 670, 360, 670, 480);
//�����
		SDL_RenderDrawLine(ren.get(), 550, 250, 550, 200);
		SDL_RenderDrawLine(ren.get(), 550, 200, 570, 200);
		SDL_RenderDrawLine(ren.get(), 570, 200, 570, 270);
		SDL_RenderPresent(ren.get()); //�� ������� ������ � ������ (��������� ������ �����)
	}
	return 0;
}
