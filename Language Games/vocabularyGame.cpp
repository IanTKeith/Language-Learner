#include <vector>
#include <string>
#include <fstream>

#include "util.hpp"
#include "vocabularyGame.hpp"
#include "console.hpp"

#define VOCABULARY_FILE "vocabulary.txt"

namespace Français {
	void VocabularyGame::play() {
		std::vector<std::pair<std::wstring, std::wstring>> translations = {};
		std::wfstream fin(VOCABULARY_FILE);

		if (!fin.is_open());
		else {

			for (std::wstring line;
				!fin.eof();
				translations.push_back(std::pair<std::wstring, std::wstring>(
					(Utility::trim(line), line.substr(0, line.find(L'|'))),
					line.substr(line.find(L'|') + 1))
				)) std::getline(fin, line);
			fin.close();
		}
		
		for (auto const& translation : translations) 
			Console::printLn(L"Word: " + translation.first + L" Translation: " + translation.second);
	}

	void VocabularyGame::cleanUp() {
		Console::clear();
	}

}
