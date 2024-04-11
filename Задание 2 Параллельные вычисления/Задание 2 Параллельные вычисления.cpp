// Задание 2 Параллельные вычисления.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
}

