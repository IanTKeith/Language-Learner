#pragma once

#include <string>

namespace Fran�ais {
#define NUM_TENSES 8
	enum Tense {
		PR�SENT,
		IMPARFAIT,
		PASS�_ANT�RIEUR,
		PASS�_COMPOS�,
		PASS�_SIMPLE,
		PLUS_QUE_PARFAIT,
		FUTUR,
		FUTUR_ANT�RIEUR
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