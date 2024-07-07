#include <exception>
#include "irVerb.hpp"

namespace Français {
	const std::wstring conjugationRules[NUM_TENSES][NUM_PERSONS][NUM_PLURALITIES] = {
		{
			{
				L"is", //Present First Person Singular
				L"issons" //Present First Person Plural 
			},
			{
				L"is", //Present Second Person Singular
				L"issez" //Present Second Person Plural
			},
			{
				L"it", //Present Third Person Singular
				L"issent" //Present Third Person Plural
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

	std::wstring IrVerb::conjugation(
		Tense tense,
		Person person,
		Plurality plurality
	) const {
		return _stem + conjugationRules[tense][person][plurality];
	}

	IrVerb::IrVerb(std::wstring const& verb, bool willContract) :
		Verb(verb.substr(0, verb.size() - 2), L"ir", willContract) {}

	IrVerb::IrVerb(std::wfstream& fin) {
		if (fin.is_open() && !fin.eof()) {
			std::wstring c, v;
			fin >> v >> c;
			*this = IrVerb(v, c == L"true");
		}
		else throw std::exception("IrVerb could not be read.");
	}
}