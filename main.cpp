#include <iostream>
#include <chrono>
#include <thread>
#include "tictactoe.hpp"
#include "colours.hpp"

namespace main_funcs {
	int choice;

	std::optional<int> greeting() {
		std::cout << "::::::::: TicTacToe :::::::::\n"
							<< "Options:\n"
							<< ansic::green << "1. Play\n" << ansic::reset
							<< ansic::red << "2. Exit\n" << ansic::reset
							<< "\nOption: ";
		std::cin >> choice;

		switch(choice) {
			case 1:
				Tic::play_game();
				break;

			case 2:
				std::cout << "\nExiting";
				std::this_thread::sleep_for(std::chrono::seconds(2));
				return 0;

			default:
				std::cout << ansic::red << "\nInvalid choice!\n" << ansic::reset;
			}
		}
};

int main() {
	main_funcs::greeting();
	return 0;
}
