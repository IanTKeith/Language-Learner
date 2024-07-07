#include <fcntl.h>
#include <io.h>
#include <codecvt>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "console.hpp"

#define outConsole std::wcout
#define inConsole std::wcin


void Console::initializeConsole() {
	static bool isNotInitialized = true;
	if (isNotInitialized) {
		_setmode(_fileno(stdout), _O_U16TEXT);
		_setmode(_fileno(stdin), _O_U16TEXT);
		isNotInitialized = false;
	}
}

void Console::print(std::wstring const& text) {
	initializeConsole();
	outConsole << text;
}

void Console::print(std::wstring const& text, Console::Color color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	print(text);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Console::Color::WHITE);
}

void Console::printLn(std::wstring const& text) {
	print(text + L"\n");
}

void Console::printLn(std::wstring const& text, Console::Color color) {
	print(text + L"\n", color);
}

void Console::readLn(std::wstring& destination) {
	initializeConsole();
	std::getline(inConsole, destination);
}

void Console::readNum(int& num) {
	initializeConsole();
	inConsole >> num;
}

void Console::readNum(unsigned int& num) {
	initializeConsole(); 
	std::wstring temp;
	readLn(temp);
	num = std::stoi(temp);
}

void Console::readNum(short& num) {
	initializeConsole(); 
	inConsole >> num;
}

void Console::readNum(unsigned short& num) {
	initializeConsole(); 
	inConsole >> num;
}

void Console::wait() {
	std::wstring temp;
	readLn(temp);
}

void Console::clear() {
#if defined _WIN32
	system("cls");
	//clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
	//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
	system("clear");
#endif
}