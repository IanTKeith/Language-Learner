#pragma once

#include <vector>
#pragma once

#include "IGame.hpp"
#include "erVerb.hpp"
#include "irVerb.hpp"
#include "reVerb.hpp"
#include "noun.hpp"

namespace Français {
	class ConjugationGame : public IGame {
		public:
			void play() override;
			void cleanUp() override;
		private:
			std::wstring formPhrase(Noun const&, Verb const&, Tense) const;
			void readSubjectsFromFile(std::vector<Noun>&, std::string const&) const;
			Noun parseNoun(std::wstring const& n) const;
			bool conductRound(Noun s, Verb const& v, Tense t) const;
	};
}