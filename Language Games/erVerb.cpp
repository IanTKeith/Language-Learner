#include <exception>
#include "erVerb.hpp"

namespace Français {
	const std::wstring conjugationRules[NUM_TENSES][NUM_PERSONS][NUM_PLURALITIES] = {
		{
			{
				L"e", //Present First Person Singular
				L"ons" //Present First Person Plural 
			},
			{
				L"es", //Present Second Person Singular
				L"ez" //Present Second Person Plural
			},
			{
				L"e", //Present Third Person Singular
				L"ent" //Present Third Person Plural
			},
		},
		{
			{
				L"", //xxx First Person Singular
				L"" //xxx First Person Plural 
			},
			{
				L"", //xxx Second Person Singular
				L"" //xxx Second Person Plural
			},
			{
				L"", //xxx Third Person Singular
				L"" //xxx Third Person Plural
			},
		},
		{
			{
				L"", //xxx First Person Singular
				L"" //xxx First Person Plural 
			},
			{
				L"", //xxx Second Person Singular
				L"" //xxx Second Person Plural
			},
			{
				L"", //xxx Third Person Singular
				L"" //xxx Third Person Plural
			},
		},
		{
			{
				L"", //xxx First Person Singular
				L"" //xxx First Person Plural 
			},
			{
				L"", //xxx Second Person Singular
				L"" //xxx Second Person Plural
			},
			{
				L"", //xxx Third Person Singular
				L"" //xxx Third Person Plural
			},
		},
		{
			{
				L"", //xxx First Person Singular
				L"" //xxx First Person Plural 
			},
			{
				L"", //xxx Second Person Singular
				L"" //xxx Second Person Plural
			},
			{
				L"", //xxx Third Person Singular
				L"" //xxx Third Person Plural
			},
		},
		{
			{
				L"", //xxx First Person Singular
				L"" //xxx First Person Plural 
			},
			{
				L"", //xxx Second Person Singular
				L"" //xxx Second Person Plural
			},
			{
				L"", //xxx Third Person Singular
				L"" //xxx Third Person Plural
			},
		},
		{
			{
				L"", //xxx First Person Singular
				L"" //xxx First Person Plural 
			},
			{
				L"", //xxx Second Person Singular
				L"" //xxx Second Person Plural
			},
			{
				L"", //xxx Third Person Singular
				L"" //xxx Third Person Plural
			},
		},
		{
			{
				L"", //xxx First Person Singular
				L"" //xxx First Person Plural 
			},
			{
				L"", //xxx Second Person Singular
				L"" //xxx Second Person Plural
			},
			{
				L"", //xxx Third Person Singular
				L"" //xxx Third Person Plural
			},
		}
	};

	std::wstring ErVerb::conjugation(
		Tense tense,
		Person person,
		Plurality plurality
	) const {
		return _stem + conjugationRules[tense][person][plurality];
	}

	ErVerb::ErVerb(std::wstring const& verb, bool willContract) :
		Verb(verb.substr(0, verb.size() - 2), L"er", willContract) {}

	ErVerb::ErVerb(std::wfstream& fin) {
		if (fin.is_open() && !fin.eof()) {
			std::wstring c, v;
			fin >> v >> c;
			*this = ErVerb(v, c == L"true");
		}
		else throw std::exception("ErVerb could not be read.");
	}
}