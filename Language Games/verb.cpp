#include "verb.hpp"

namespace Français {
	Verb::Verb(
		std::wstring const& _stem,
		std::wstring const& _ending,
		bool willContract
	) : _stem(_stem),
		_ending(_ending),
		_word(_stem + _ending),
		_willContract(willContract)
	{}

	Verb::Verb() : _stem(L""), _ending(L""), _word(L""), _willContract(false) {}

	std::wstring const& Verb::text() const {
		return _word;
	}

	bool Verb::willContract() const {
		return _willContract;
	}
}