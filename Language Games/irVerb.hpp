#pragma once
#include <fstream>
#include "verb.hpp"

namespace Français {
	class IrVerb : public Verb {
	public:
		std::wstring conjugation(Tense, Person, Plurality) const override;
		IrVerb(std::wstring const&, bool);
		IrVerb(std::wfstream&);
	};
}