#include "grammaireFrançaise.hpp"
#include <stdexcept>

namespace Français {

	Person parsePerson(std::wstring const& p) {
		if (p == L"first") return Person::FIRST;
		else if (p == L"second") return Person::SECOND;
		else if (p == L"third") return Person::THIRD;
		else throw std::invalid_argument("The argument can not be converted to a Français::Person.");
	}

	Plurality parsePlurality(std::wstring const& p) {
		if (p == L"singular") return Plurality::SINGULAR;
		else if (p == L"plural") return Plurality::PLURAL;
		else throw std::invalid_argument("The argument can not be converted to a Français::Plurality.");
	}

	Gender parseGender(std::wstring const& p) {
		if (p == L"masculine") return Gender::MASCULINE;
		else if (p == L"feminine") return Gender::FEMININE;
		else throw std::invalid_argument("The argument can not be converted to a Français::Gender.");
	}
}