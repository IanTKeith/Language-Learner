#pragma once

#include <string>

class Console {
	static void initializeConsole();

	public:
		enum Color
		{
			WHITE = 15,
			RED = 12,
			GREEN= 10
		};

		static void print(std::wstring const&);
		static void print(std::wstring const&, Color);
		static void printLn(std::wstring const&);
		static void printLn(std::wstring const&, Color);
		static void readLn(std::wstring&);
		static void readNum(int&);
		static void readNum(unsigned int&);
		static void readNum(short&);
		static void readNum(unsigned short&);
		static void clear();
		static void wait();
};