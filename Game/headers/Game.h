#pragma once
#include "Player.h"
#include "Menu.h"

class Game {

private:
	using Cords = std::pair<int, int>;
	std::unique_ptr<Player> plr1;
	std::unique_ptr<Player> plr2;
	int pol;		//Размер игрового поля
	bool gm_over = false;	//Проверка конца игры
	//bool input_navy = false;	//Способ расстановки кораблей
							//true-ручной, false- автоматический
	bool multplr=false;		//true-два игрока, false- один игрок

public:
	//Конструктор (задает способ расстановки и размер поля)
	Game(); 
	//Запуск игры
	void play();
	//Автоматический расчет координат
	inline int autoSet(int p)const;
	//Проверка выхода за границу поля
	bool outOfBounds(Cords& crd, int& _dir, int& _deck);
	//Вывод  ироков на экран
	void mapPol();
	//Проверка наличия кораблей
	bool isOver();
	//Расстановка флота
	void setNavy(std::unique_ptr<Player>& pl, bool st);
	//Ввод координат
	Cords&& setMove(const std::unique_ptr<Player>& pl)const {
		Cords crd;
		int count = 0;
		for (;;) {
			//Проверка сделанного хода
			std::cout << "Введите координаты (x ,y) через пробел: "
				<< std::endl;
			std::cout << "x,y: ";
			std::cin >> crd.first >> crd.second;
			if (crd.first <= 0 || crd.second <= 0 || crd.first > pol || crd.second > pol) {
				system("cls");
				std::cout << "Выход за пределы поля! Попробуйте снова"
					<< std::endl;
				continue;
			}
			count = ((crd.second - 1) * static_cast<int>(pol) + crd.first) - 1;
			if (pl->isRepeat(crd,pol)) {
				system("cls");
				std::cout << "По данной позиции ранее уже был сделан выстрел." <<
					std::endl;
				std::cout << "Повторите ввод." << std::endl;
				continue;
			}
			else
				return std::move (crd);
		}
	}
};

