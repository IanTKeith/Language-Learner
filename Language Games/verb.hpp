#pragma once

#include <string>
#include <iostream>
#include "word.hpp"
#include "grammaireFrançaise.hpp"

namespace Français {
	class Verb : public Word {
		public:
			std::wstring const& text() const override;
			virtual std::wstring conjugation(Tense, Person, Plurality) const = 0;
			bool willContract() const override;
		protected:
			Verb();
			Verb(std::wstring const& _stem, std::wstring const& _ending, bool _willContract);
			std::wstring _stem;
			std::wstring _ending;
			std::wstring _word;
			bool _willContract;
	};
}