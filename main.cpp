#include "assiss.h"
#include "scores.cpp"
#include "gui.cpp"
#include "thegame.cpp"

int main()
{
	hidecursor();
	srand(time(0));
	loading();
	run();
}
