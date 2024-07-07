#pragma once
#include <string>

namespace Français {
	class Word {
		public:
			virtual std::wstring const& text() const = 0;
			virtual bool willContract() const = 0;
	};
}