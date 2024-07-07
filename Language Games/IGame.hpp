#pragma once

class IGame {
	public:
		virtual void play() = 0;
		virtual void cleanUp() = 0;
};