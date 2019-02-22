
#include "pch.h"
#include "deck.hpp"

#include <fcntl.h>
#include <io.h>
#include <cstdio>
#include <sstream>
#include "free_cell.hpp"


int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	deck d;
	d.load_hopper();
	d.shuffle();
	free_cell game;
	game.deal_cards(d);
	game.display_table();

	return 0;	
}
