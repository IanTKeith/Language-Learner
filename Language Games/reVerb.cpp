#include <exception>
#include "reVerb.hpp"

namespace Français {
	const std::wstring conjugationRules[NUM_TENSES][NUM_PERSONS][NUM_PLURALITIES] = {
		{
			{
				L"s", //Present First Person Singular
				L"ons" //Present First Person Plural 
			},
			{
				L"s", //Present Second Person Singular
				L"ez" //Present Second Person Plural
			},
			{
				L"", //Present Third Person Singular
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

	std::wstring ReVerb::conjugation(
		Tense tense,
		Person person,
		Plurality plurality
	) const {
		if (tense == PRÉSENT &&
			person == THIRD &&
			plurality == SINGULAR &&
			_stem.back() != L'd'
		) return _stem + L"t";
		else return _stem + conjugationRules[tense][person][plurality];
	}

	ReVerb::ReVerb(std::wstring const& verb, bool willContract) :
		Verb(verb.substr(0, verb.size() - 2), L"re", willContract) {}

	ReVerb::ReVerb(std::wfstream& fin) {
		if (fin.is_open() && !fin.eof()) {
			std::wstring c, v;
			fin >> v >> c;
			*this = ReVerb(v, c == L"true");
		}
		else throw std::exception("ReVerb could not be read.");
	}
}