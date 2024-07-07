#pragma once

#include <string>
#include "word.hpp"
#include "verb.hpp"
#include "grammaireFrançaise.hpp"

namespace Français {
	class Noun : public Word {
		public:
			std::wstring const& text() const override;
			bool willContract() const override;

			Plurality plurality() const;
			Gender gender() const;
			Person person() const;
			Noun(std::wstring const&, bool, Gender, Plurality, Person);
		private:
			std::wstring _word;
			bool _willContract;
			Gender _gender;
			Plurality _plurality;
			Person _person;
	};
}