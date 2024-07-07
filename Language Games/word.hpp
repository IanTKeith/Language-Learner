#pragma once
#include <string>

namespace Fran�ais {
	class Word {
		public:
			virtual std::wstring const& text() const = 0;
			virtual bool willContract() const = 0;
	};
}