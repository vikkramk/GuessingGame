
/*Guessing Game*/

//Libraries
#include <iostream>
#include <ctime>
#include <cstdlib>

//Main Function
int main() {

	//Declarations
	int target, guess, guesses;
	char answer;
	bool playing = true, valid = false;
	
	//Set random number generator seed based on time
	srand(time(NULL));
	
	//Main game loop
	while (playing) {

		//Generate number for the round, reset counters
		target = rand() % 101;
		guesses = 0;

		//Prompt user
		std::cout << "I'm thinking of a number from 0-100, inclusive.\n";

		//Guessing loop, exit when number is guessed, otherwise tell user if too high or low
		do {
			//Loop until proper input type given
			valid = false;
			while (!valid) {
				std::cout << "Try to guess it:";
				std::cin >> guess;
				if (!std::cin ){
					std::cout << "Please. You're wasting everybody's time.\n";
					std::cin.clear();
					std::cin.ignore(1000, '\n');
				}
				else
					valid = true;
			}

			if (guess < target)
				std::cout << "Too low. ";
			else if (guess > target)
				std::cout << "Too high. ";

			guesses++;
		} while(guess != target);
		
		//Inform user of success, tell how many guesses
		std::cout << "Correct! Guessed after " << guesses << " tries\n";

		//Ask to restart, if not, set variable to exit game loop
		std::cout << "Play again? (y/n)";
		//Loop until proper input type given
		valid = false;
		while (!valid) {
			std::cin >> answer;
			if (!std::cin || (answer != 'y' && answer != 'n')) {
				std::cout << "Just type 'y' or 'n':";
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
			else
				valid = true;
		}

		if (answer != 'y')
			playing = false;
	}


	//Exit without error
	return 0;
}
