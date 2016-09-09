#include <iostream>
#include <ctime>
#include <cstdlib>

main() {
	int target, guess, guesses;
	char answer;
	bool playing = true;
	
	srand(time(NULL));
	
	while (playing) {

		target = rand() % 101;
		guesses = 0;

		std::cout << "I'm guessing a number from 0-100, inclusive.\nTry to guess it:";

		do {
			std::cin >> guess;
			if (guess < target)
				std::cout << "Too low. Guess again:";
			else if (guess > target)
				std::cout << "Too high. Guess again:";

			guesses++;
		} while(guess != target);
		
		std::cout << "Guessed after " << guesses << " tries\n";
		std::cout << "Play again? (y/n)";
		std::cin >> answer;
		if (answer != 'y')
			playing = false;
	}
}
