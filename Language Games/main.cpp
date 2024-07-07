#include <memory>

#include "console.hpp"
#include "IGame.hpp"
#include "conjugationGame.hpp"
#include "vocabularyGame.hpp"

unsigned int pickGame() {
	Console::printLn(L"Choose your game (0 to quit):");
	Console::printLn(L"1) Conjugation Practice");
	Console::printLn(L"2) Vocabulary Practice");
	Console::print(L"Enter choice: ");
	unsigned int x;
	Console::readNum(x);
	return x;
}

int main() {
	std::unique_ptr<IGame> game;
	for (unsigned int userSelection; (userSelection = pickGame()) != 0; true) {
		switch (userSelection) {
			case 1: game = std::make_unique<Français::ConjugationGame>(); break;
			case 2: game = std::make_unique<Français::VocabularyGame>(); break;
		}
		game->play();
		game->cleanUp();
	}

	return 0;
}