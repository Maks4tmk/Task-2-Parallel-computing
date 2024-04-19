// Задание 2 Параллельные вычисления.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

void sum_vec(std::vector<int> Vector1, std::vector<int> Vector2) {
	for (int i = 0; i < Vector1.size(); i++) {
		int sum =+ Vector1[i] + Vector2[i];
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;

	std::cout << "\t\t1'000" << "\t        10'000" << "\t       100'000" << "\t     1'000'000" << "\n";
	std::cout << "-------------------------------------------------------------------------" << std::endl;

	std::vector<int> Threads{1, 2, 4, 8, 16};
	std::vector<int> Size_v{1'000, 10'000, 100'000, 1'000'000};

	std::vector<int> v1;
	std::vector<int> v2;

	for(auto& c_Thread : Threads) {

		std::cout << c_Thread << " потоков ";

		for (auto& c_Vector : Size_v) {

			v1.resize(c_Vector, 2);
			v2.resize(c_Vector, 1);

			int size_Threads = static_cast<int> (c_Vector / c_Thread);
			std::vector<std::thread> th;

			auto start = std::chrono::high_resolution_clock::now();

			for (int i = 0; i < c_Thread; i++) {
				std::vector<int>n_v1;
				std::vector<int>n_v2;
				int r_bord = 0;

				if (i != c_Thread - 1) {
					r_bord = size_Threads * (i + 1);
				}
				else {
					r_bord = c_Vector;
				}

				for (int j = size_Threads * i; j < r_bord; j++) {
					n_v1.push_back(v1[j]);
					n_v2.push_back(v2[j]);
				}
				th.push_back(std::thread(sum_vec, n_v1, n_v2));
			}

			for (auto& it : th) {
				it.join();
			}

			auto stop = std::chrono::high_resolution_clock::now();

			std::chrono::duration<double, std::milli> time = stop - start;
			std::cout << "\t" << time.count() << "ms";
		}
		std::cout << std::endl;
	}
}

