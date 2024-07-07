#include "noun.hpp"

namespace Français {
	Noun::Noun(
		std::wstring const& w,
		bool wc,
		Gender g,
		Plurality pl,
		Person pe
	) : _word(w),
		_willContract(wc),
		_gender(g),
		_plurality(pl),
		_person(pe)
	{}

	std::wstring const& Noun::text() const {
		return _word;
	}

	bool Noun::willContract() const {
		return _willContract;
	}

	Plurality Noun::plurality() const {
		return _plurality;
	}

	Gender Noun::gender() const {
		return _gender;
	}
	
	Person Noun::person() const {
		return _person;
	}
}