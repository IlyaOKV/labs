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

constexpr int WIDTH = 1366, HEIGHT = 768; //переменные размера окна

int main(int, char**)
{
//Инициализация SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	auto win = std::shared_ptr<SDL_Window>( //SDL указатель win и его последующая инициализация
//Создание окна
			SDL_CreateWindow(
						"Home... Sweet home", //Заголовок окна
						SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, //Расположение окна по середине
						WIDTH, HEIGHT, //размеры, которые задаются переменными описан
						SDL_WINDOW_SHOWN), //После создания, показать окно
			SDL_DestroyWindow); //Разрушение окна

//Инициализация ошибки создания окна при помощи инструментf диагностики SDL
	if (win == nullptr) {
		std::cerr << "При создании окна произошла ошибка: " <<
				SDL_GetError() << std::endl;
		return 1; //завершение программы аварийно
	}

//Инициализация средства рендеринга
	auto ren = std::shared_ptr<SDL_Renderer>(
			SDL_CreateRenderer(win.get(), -1, //1-возвра сырого указателя на window (win), 2-номер видеокарты (-1-по-умолчанию)
					SDL_RENDERER_ACCELERATED | // использование аппаратного ускорения. |-побитовое или, объединение
					SDL_RENDERER_PRESENTVSYNC), // синхронизация с обновлением экрана
			SDL_DestroyRenderer); //уничтожение рендера

//Инициализация ошибки создания рендера при помощи инструментf диагностики SDL
	if (ren == nullptr) {
		std::cerr << "При создании renderer-а произошла ошибка: " <<
				SDL_GetError() << std::endl;
		return 1; //завершение программы аварийно
	}

	SDL_Event event; //переменная события

//бесконечный цикл, обрабывать событий пока они есть
	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) return 0;
		}

		SDL_SetRenderDrawColor(ren.get(), 0, 48, 64, 255); //задание цвета фона
		SDL_RenderClear(ren.get()); //очистка окна
//Стены
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
//Крыша
		SDL_RenderDrawLine(ren.get(), 350, 350, 475, 200);
		SDL_RenderDrawLine(ren.get(), 475, 200, 600, 350);
		SDL_RenderDrawLine(ren.get(), 475, 200, 600, 110);
		SDL_RenderDrawLine(ren.get(), 600, 110, 700, 250);
//Окно
		SDL_RenderDrawLine(ren.get(), 395, 395, 555, 395);
		SDL_RenderDrawLine(ren.get(), 555, 395, 555, 505);
		SDL_RenderDrawLine(ren.get(), 555, 505, 395, 505);
		SDL_RenderDrawLine(ren.get(), 395, 505, 395, 395);
		SDL_RenderDrawLine(ren.get(), 395, 505, 395, 395);
		SDL_RenderDrawLine(ren.get(), 395, 450, 555, 450);
		SDL_RenderDrawLine(ren.get(), 395, 450, 555, 450);
		SDL_RenderDrawLine(ren.get(), 475, 395, 475, 505);
//Дверь
		SDL_RenderDrawLine(ren.get(), 640, 510, 640, 390);
		SDL_RenderDrawLine(ren.get(), 640, 390, 670, 360);
		SDL_RenderDrawLine(ren.get(), 670, 360, 670, 480);
//Труба
		SDL_RenderDrawLine(ren.get(), 550, 250, 550, 200);
		SDL_RenderDrawLine(ren.get(), 550, 200, 570, 200);
		SDL_RenderDrawLine(ren.get(), 570, 200, 570, 270);
		SDL_RenderPresent(ren.get()); //из заднего буфера в видемы (исключаем разрыв кадра)
	}
	return 0;
}
