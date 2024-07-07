#include <fstream>
#include <concepts>
#include <memory>
#include <queue>
#include <tuple>

#include "conjugationGame.hpp"
#include "console.hpp"
#include "util.hpp"

#define SUBJECT_FILE "subjects.txt"
#define ER_VERB_FILE "erVerbs.txt"
#define IR_VERB_FILE "irVerbs.txt"
#define RE_VERB_FILE "reVerbs.txt"

namespace Français {
	using std::wstring, std::vector;

	struct Configuration {
		bool useEr, useIr, useRe;
	};

	wstring ConjugationGame::formPhrase(
		Noun const& subject,
		Verb const& verb,
		Tense tense
	) const {
		if (subject.text() == L"Je" && verb.willContract())
			return L"J'" + verb.conjugation(Tense::PRÉSENT, Person::FIRST, Plurality::SINGULAR);
		else return subject.text() + L" " +
			verb.conjugation(Tense::PRÉSENT, subject.person(), subject.plurality());
	}

	Noun ConjugationGame::parseNoun(wstring const& n) const {
#define updateBoundaries() start += entryLength + 1; entryLength = (n.find('|', start) - start);
		size_t entryLength, start = 0;
		wstring word = n.substr(0, entryLength = n.find(L'|'));

		updateBoundaries();

		Gender gender = parseGender(n.substr(start, entryLength));

		updateBoundaries();

		Plurality plurality = parsePlurality(n.substr(start, entryLength));

		updateBoundaries();

		Person person = parsePerson(n.substr(start, entryLength));
		return { word, false, gender, plurality, person };
	}

	template<typename type>
	void readFromFile(
		vector<std::shared_ptr<Verb>>& verbList,
		std::string const& fileName
	) {
		std::wfstream fin(fileName);
		if (!fin.is_open());
		else for (; !fin.eof(); verbList.push_back(std::make_shared<type>(fin)));
		fin.close();
	}

	void ConjugationGame::readSubjectsFromFile(
		vector<Noun>& nounList,
		std::string const& fileName
	) const {
		std::wfstream fin(fileName);
		if (!fin.is_open());
		else {
			for (
				wstring n;
				!fin.eof();
				nounList.push_back(parseNoun(n))
				) std::getline(fin, n);
			fin.close();
		}
	}

	bool ConjugationGame::conductRound(Noun s, Verb const& v, Tense t) const {
		bool isAnswerCorrect = false;
		auto expected = formPhrase(s, v, PRÉSENT);
		wstring response,
				prompt = L"(présent) " + s.text() + L" " + v.text();
		Console::printLn(prompt);
		Console::readLn(response);
		Console::clear();

		if (_wcsicmp(Utility::trim(response).c_str(), expected.c_str()) == 0) {
			Console::printLn(L"Correct: " + response, Console::GREEN);
			isAnswerCorrect = true;
		}
		else {
			Console::printLn(L"Your answer:    " + response, Console::RED);
			Console::printLn(L"Correct answer: " + expected, Console::RED);
		}
		Console::wait();
		return isAnswerCorrect;
	}

	Configuration getConfig() {
		Configuration config;
		std::wstring resp;
		Console::printLn(L"Include -Er? (Y/N)");
		Console::readLn(resp);
		config.useEr = _wcsicmp(Utility::trim(resp).c_str(), L"Y") == 0;
		Console::printLn(L"Include -Ir? (Y/N)");
		Console::readLn(resp);
		config.useIr = _wcsicmp(Utility::trim(resp).c_str(), L"Y") == 0;
		Console::printLn(L"Incldue -Re? (Y/N)");
		Console::readLn(resp);
		config.useRe = _wcsicmp(Utility::trim(resp).c_str(), L"Y") == 0;

		Console::clear();

		return config;
	}

	void ConjugationGame::play() {

		vector<Noun> subjects;
		vector<std::shared_ptr<Verb>> verbs;
		Configuration config = getConfig();

		if (config.useEr) readFromFile<ErVerb>(verbs, ER_VERB_FILE);
		if (config.useIr) readFromFile<IrVerb>(verbs, IR_VERB_FILE);
		if (config.useRe) readFromFile<ReVerb>(verbs, RE_VERB_FILE);
		if (verbs.empty()) {
			Console::printLn(L"Game can not be conducted because no verbs were selected");
			return;
		}
		readSubjectsFromFile(subjects, SUBJECT_FILE);

		unsigned int total = 0, correctCount = 0;
		std::queue<std::tuple<Français::Noun, Verb const&, Français::Tense>> missed;

		for (; total < 20; ++total, Console::clear()) {
			auto s = Utility::getRandomElement(subjects);
			auto v = Utility::getRandomElement(verbs);

			if (conductRound(s, *v, PRÉSENT)) ++correctCount;
			else missed.push({ s, *v, PRÉSENT });
		}
		Console::printLn(
			L"You scored a " +
			std::to_wstring(correctCount) +
			L"/" +
			std::to_wstring(total)
		);
		
		Console::wait();

		if (total != correctCount) {
			Console::printLn(L"Let's review what you missed!");
			Console::wait();
		}

		while (!missed.empty()) {
			Console::clear();
			auto round = missed.front();
			if (!conductRound(std::get<0>(round), std::get<1>(round), std::get<2>(round)))
				missed.push(round);
			missed.pop();
		}
	}

	void ConjugationGame::cleanUp() {
		Console::clear();
	}
}