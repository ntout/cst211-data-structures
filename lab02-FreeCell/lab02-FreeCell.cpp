
#include "pch.h"
#include "deck.hpp"

#include <fcntl.h>
#include <io.h>
#include <cstdio>
#include <sstream>



int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	deck d;
	d.shuffle();


	for (auto i{0}; i < 8; ++i)
	{
		d.get_card(i).display_top_card();
	}
	std::wcout << L"\n";
	for (auto i{ 0 }; i < 8; ++i)
	{
		d.get_card(i).display_r2_card();
	}
	std::wcout << L"\n";

	for (auto i{ 8 }; i < 16; ++i)
	{
		d.get_card(i).display_top_card();
	}
	std::wcout << L"\n";
	for (auto i{ 8 }; i < 16; ++i)
	{
		d.get_card(i).display_r2_card();
	}
	std::wcout << L"\n";

	return 0;	
}
