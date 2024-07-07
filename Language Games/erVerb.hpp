#pragma once
#include <fstream>
#include "verb.hpp"

namespace Français {
	class ErVerb : public Verb {
		public:
			std::wstring conjugation(Tense, Person, Plurality) const override;
			ErVerb(std::wstring const&, bool);
			ErVerb(std::wfstream&);
	};
}