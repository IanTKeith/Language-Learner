#pragma once

#include <string>

namespace Français {
#define NUM_TENSES 8
	enum Tense {
		PRÉSENT,
		IMPARFAIT,
		PASSÉ_ANTÉRIEUR,
		PASSÉ_COMPOSÉ,
		PASSÉ_SIMPLE,
		PLUS_QUE_PARFAIT,
		FUTUR,
		FUTUR_ANTÉRIEUR
	};

#define NUM_PERSONS 3
	enum Person {
		FIRST,
		SECOND,
		THIRD
	};

	Person parsePerson(std::wstring const&);

#define NUM_PLURALITIES 2
	enum Plurality {
		SINGULAR,
		PLURAL
	};

	Plurality parsePlurality(std::wstring const&);

#define NUM_GENDERS 2
	enum Gender {
		MASCULINE,
		FEMININE
	};

	Gender parseGender(std::wstring const&);
}