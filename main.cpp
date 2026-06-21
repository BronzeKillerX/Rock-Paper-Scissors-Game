#include <iostream>
#include <random>

int main (){
	//Rock-Paper-Scissors-Game
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution distr(1, 3);

}