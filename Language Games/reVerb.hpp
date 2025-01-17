#pragma once
#include <fstream>
#include "verb.hpp"

namespace Fran�ais {
	class ReVerb : public Verb {
	public:
		std::wstring conjugation(Tense, Person, Plurality) const override;
		ReVerb(std::wstring const&, bool);
		ReVerb(std::wfstream&);
	};
}