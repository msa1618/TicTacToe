#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <iostream>
#include <vector>
#include <algorithm>

namespace Tic {
	char player_char, opponent_char;
	int turns{0};
	bool game_ended{false};

	// Dynamically managed board and patterns
	std::vector<char> cells(9, ' ');
	const std::vector<std::vector<int>> winning_patterns{
		{0, 1, 2}, // Horizontal
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6}, // Vertical
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8}, // Diagonal
		{2, 4, 6}
	};

	// Clear the screen based on OS
	void clear_screen() {
		#ifdef WIN32
			std::system("cls");
		#else
			std::system("clear");
		#endif
	}

	void choose_characters() {
		std::cout << "X or O? (X for first, O for second): ";
		std::cin >> player_char;
		player_char = toupper(player_char);

		if (player_char != 'X' && player_char != 'O') {
			std::cout << "Invalid choice! Defaulting to X.\n";
			player_char = 'X';
		}
		opponent_char = (player_char == 'X') ? 'O' : 'X';
		clear_screen();
	}

	void draw_board() {
		for (int i = 0; i < 9; ++i) {
			std::cout << " " << cells[i] << " ";
			if (i % 3 != 2) std::cout << "|";
			if (i % 3 == 2 && i < 8) std::cout << "\n-----------\n";
		}
		std::cout << std::endl;
	}

	bool check_win(char current_char) {
		return std::any_of(winning_patterns.begin(), winning_patterns.end(), [&](const std::vector<int>& pattern) {
			return std::all_of(pattern.begin(), pattern.end(), [&](int index) {
				return cells[index] == current_char;
			});
		});
	}

	bool check_draw() {
		return std::none_of(cells.begin(), cells.end(), [](char cell) { return cell == ' '; });
	}

	// Handle player's turn
	void player_turn(char current_char) {
		int cell_choice;
		do {
			std::cout << "Player " << current_char << ", choose a cell (0-8): ";
			std::cin >> cell_choice;

			if (cell_choice < 0 || cell_choice >= 9 || cells[cell_choice] != ' ') {
				std::cout << "Invalid move, try again.\n";
			} else {
				break;
			}
		} while (true);

		cells[cell_choice] = current_char;
		clear_screen();
	}

	// Main game loop
	void play_game() {
		choose_characters();

		while (!game_ended && turns < 9) {
			draw_board();
			player_turn(turns % 2 == 0 ? player_char : opponent_char);

			char current_char = turns % 2 == 0 ? player_char : opponent_char;
			if (check_win(current_char)) {
				draw_board();
				std::cout << "Player " << current_char << " wins!\n";
				game_ended = true;
				break;
			}

			if (check_draw()) {
				draw_board();
				std::cout << "It's a draw!\n";
				game_ended = true;
				break;
			}

			++turns;
		}
	}
}

#endif // TICTACTOE_HPP
