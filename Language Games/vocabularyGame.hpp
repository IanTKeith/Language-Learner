#pragma once

#include "IGame.hpp"

namespace Fran�ais {
	class VocabularyGame : public IGame {
	public:
		void play() override;
		void cleanUp() override;
	};
}