#include <iostream>
#include <random>

void seriesGameMode(int range) {
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

		if (playerMove == 1) {
			if (playerMove == computerMove) {
				std::cout << "\nYour move was Rock.\n";
				std::cout << "Computer Move was Rock.\n";
				std::cout << "This round is a draw.\n";
				drawCount++;
			}
			else if (computerMove == 2) {
				std::cout << "\nYour move was Rock.\n";
				std::cout << "Computer move was Paper.\n";
				std::cout << "You lose this round.\n";
				loseCount++;
			}
			else if (computerMove == 3) {
				std::cout << "\nYour move was Rock.\n";
				std::cout << "Computer move was Scissors.\n";
				std::cout << "You win this round.\n";
				winCount++;
			}
		} else if (playerMove == 2){
			if (playerMove == computerMove) {
				std::cout << "\nYour Move was Paper.\n";
				std::cout << "Computer move was Paper.\n";
				std::cout << "This round is a draw.\n";
				drawCount++;
			}
			else if (computerMove == 1) {
				std::cout << "\nYour move was Paper.\n";
				std::cout << "Computer move was Rock.\n";
				std::cout << "You win this round.\n";
				winCount++;
			}
			else if (computerMove == 3) {
				std::cout << "\nYour move was Paper.\n";
				std::cout << "Computer move was Scissors.\n";
				std::cout << "You lose this round.\n";
				loseCount++;
			}
		}
		else if (playerMove == 3) {
			if (playerMove == computerMove) {
				std::cout << "\nYour move was Scissors.\n";
				std::cout << "Computer move was Scissors.\n";
				std::cout << "This round is a draw";
				drawCount++;
			}
			else if (computerMove == 1) {
				std::cout << "\nYour move was Scissors.\n";
				std::cout << "Computer move was Rock.\n";
				std::cout << "You lose this round.\n";
				loseCount++;
			}
			else if (computerMove == 2) {
				std::cout << "\nYour move was Scissors.\n";
				std::cout << "Computer move was Paper.\n";
				std::cout << "You win this round.\n";
				winCount++;
			}
		}
		
		std::cout << "\n Press Enter to continue to the next round";
		std::cin.get();

	}

	//score check after the total rounds completed
	std::system("cls");
	std::cout << "\n---------------Game Over---------------\n\n";
	std::cout << "Draw: " << drawCount << std::endl;
	std::cout << "Lose: " << loseCount << std::endl;
	std::cout << "Win : " << winCount << std::endl;
	std::cout << "\n--------------------------------------------\n";

	std::cout << "\nPress Enter to continue";
	std::cin.ignore(1000, '\n');
	std::cin.get();
}

void endlessGameMode();

int main (){
	std::system("cls");
	int choice;
	do {
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


	} while (choice != 5);

}