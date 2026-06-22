#include <iostream>
#include <random>

void seriesGameMode(int range) {

	std::string moves[] = { "Rock", "Paper", "Scissors" };

	std::random_device rd;
	std::mt19937 gen(rd());
	int drawCount = 0;
	int winCount = 0;
	int loseCount = 0;
	int playerMove;
	for (int i = 1; i <= range; i++) {
		std::system("cls");
		std::uniform_int_distribution<> distr(1, 3);
		std::cout << "==========================================\n";
		std::cout << "         Best of " << range << " Series   \n";
		std::cout << "==========================================\n\n";
		std::cout << "Round " << i << " of " << range << " \n\n";
		std::cout << "Select your move:\n";
		std::cout << "1. Rock\n";
		std::cout << "2. Paper\n";
		std::cout << "3. Scissors\n";
		std::cout << "Enter your choice: ";

		while (!(std::cin >> playerMove) || (playerMove < 1 || playerMove > 3)) {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "\nThat is not a valid option... Try Again: ";
			}
			else {
				std::cout << "\nEnter a valid option:	";
			}
		}

		//checking move with computer and giving verdict win - draw - loss
		int computerMove = distr(gen);

		std::cout << "\nYour move was " << moves[playerMove - 1] << std::endl;
		std::cout << "Computer move was " << moves[computerMove - 1] << std::endl;

		if (playerMove == computerMove) {
			std::cout << "This round is a draw\n";
			drawCount++;
		}
		else if ((playerMove == 1 && computerMove == 3) || (playerMove == 2 && computerMove == 1) || (playerMove == 3 && computerMove == 2)) {
			std::cout << "You win this round\n";
			winCount++;
		}
		else
		{
			std::cout << "You lose this round\n";
			loseCount++;
		}
		
		std::cout << "\nPress Enter to continue to the next round";
		std::cin.ignore(1000, '\n');
		std::cin.get();

	}

	//score check after the total rounds completed
	std::system("cls");
	std::cout << "\n---------------Game Over---------------\n\n";
	std::cout << "Draw: " << drawCount << std::endl;
	std::cout << "Lose: " << loseCount << std::endl;
	std::cout << "Win : " << winCount << std::endl;

	if ((winCount > loseCount) && (winCount > drawCount)) {
		std::cout << "You win!!!";
	}
	else if ((drawCount > winCount) && (drawCount > loseCount)) {
		std::cout << "It was a draw!!!";
	}
	else {
		std::cout << "Computer wins!!!";
	}

	std::cout << "\n----------------------------------------\n";

	std::cout << "\nPress Enter to continue";
	std::cin.get();
}

void endlessGameMode() {
	std::string moves[] = { "Rock", "Paper", "Scissors" };
	char choice = ' ';
	int round = 1;
	int playerMove;
	int drawCount = 0;
	int winCount = 0;
	int loseCount = 0;
	std::random_device rd;
	std::mt19937 gen(rd());

	do {
		std::uniform_int_distribution<> distr(1, 3);
		std::system("cls");
		std::cout << "============================================\n";
		std::cout << "               Endless Mode                 \n";
		std::cout << "============================================\n";

		std::cout << "\n-------------Round " << round << "-------------\n";

		std::cout << "Select your move: \n";
		std::cout << "1. Rock\n";
		std::cout << "2. Paper\n";
		std::cout << "3. Scissors\n";
		std::cout << "Enter your option: ";

		while (!(std::cin >> playerMove) || playerMove < 1 || playerMove > 3) {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "\nThat is not a valid option. Try Again!!: ";
			}
			else
			{
				std::cout << "\nEnter valid option: ";
			}
		}

		//game logic check
		int computerMove = distr(gen);
		std::cout << "Your move was " << moves[playerMove - 1] << std::endl;
		std::cout << "Computer move was " << moves[computerMove - 1] << std::endl;

		if (playerMove == computerMove) {
			std::cout << "This round is a draw\n";
			drawCount++;
		}
		else if ((playerMove == 1 && computerMove == 3) || (playerMove == 2 && computerMove == 1) || (playerMove == 3 && computerMove == 2)) {
			std::cout << "You win this round\n";
			winCount++;
		}
		else
		{
			std::cout << "You lose this round\n";
			loseCount++;
		}

		std::cout << "\nDo you want to continue (y/n): ";

		while (!(std::cin >> choice) || (choice != 'y' && choice != 'n')) {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "\nEnter a valid option: ";
			}
			else {
				std::cout << "Enter a valid option: ";
			}
		}

		round++;

	} while (choice != 'n');

	std::cin.ignore(1000, '\n');

	std::system("cls");
	std::cout << "\n---------------Game Over---------------\n\n";
	std::cout << "Draw: " << drawCount << std::endl;
	std::cout << "Lose: " << loseCount << std::endl;
	std::cout << "Win : " << winCount << std::endl;

	if ((winCount > loseCount) && (winCount > drawCount)) {
		std::cout << "You win!!!";
	}
	else if ((drawCount > winCount) && (drawCount > loseCount)) {
		std::cout << "It was a draw!!!";
	}
	else {
		std::cout << "Computer wins!!!";
	}

	std::cout << "\n----------------------------------------\n";
	std::cout << "\nPress Enter to continue";
	std::cin.get();
}

int main (){
	int choice;
	do {
		std::system("cls");
		std::cout << "================================================\n";
		std::cout << "              Rock-Paper-Scissors               \n";
		std::cout << "================================================\n";

		std::cout << "\n--------------Select Your Mode------------------\n";
		std::cout << "\n1. Best of 3 series";
		std::cout << "\n2. Best of 5 series";
		std::cout << "\n3. Best of 10 series";
		std::cout << "\n4. Endless Mode";
		std::cout << "\n5. Exit";
		std::cout << "\nEnter your option: ";

		while (!(std::cin >> choice) || (choice < 1 || choice > 5)) {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "\nThat is not a valid option... Try Again: ";
			}
			else {
				std::cout << "\nEnter a valid option:	";
			}
		}

		if (choice == 1) {
			seriesGameMode(3);
		}
		else if (choice == 2) {
			seriesGameMode(5);
		}
		else if (choice == 3) {
			seriesGameMode(10);
		}
		else if (choice == 4) {
			endlessGameMode();
		}


	} while (choice != 5);

}