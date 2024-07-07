#pragma once

#include "IGame.hpp"

namespace Français {
	class VocabularyGame : public IGame {
	public:
		void play() override;
		void cleanUp() override;
	};
}