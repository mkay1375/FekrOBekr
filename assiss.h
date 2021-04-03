#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <windows.h>
#include <iostream>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void showcursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 20;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(int x, int y) 
{ 
	CursorPosition.X = x; // Locates column
	CursorPosition.Y = y; // Locates Row
	SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

void SetColor(int ForgC)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
                    //We use csbi for the wAttributes word.
	if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
	                //Mask out all but the background attribute, and add in the forgournd color
	    wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
	    SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
	
	/* Colors:
	Name         | Value
	             |
	Black        |   0
	Blue         |   1
	Green        |   2
	Cyan         |   3
	Red          |   4
	Magenta      |   5
	Brown        |   6
	Light Gray   |   7
	Dark Gray    |   8
	Light Blue   |   9
	Light Green  |   10
	Light Cyan   |   11
	Light Red    |   12
	Light Magenta|   13
	Yellow       |   14
	White        |   15
	*/
}

// -------------------------------------------------- String Area: --------------------------------------------------

int getlen(char *str)
{
	for(unsigned short int i = 0; i < 65535; i++)
		if (*(str + i) == '\0')
			return i;
}

void strcpy(char *dest, char *source)
{
		for(unsigned short int i = 0; i < 65535; i++)
		{
			*(dest + i) = *(source + i);
			if (*(source + i) == '\0') return;
		}
}

int strcmp(char s1[], char s2[])
{
	int i = 0;
	while (true)
	{
		if ( s2[i] > s1[i] )
			return 1;
		
		if ( s2[i] < s1[i] )
			return -1;
			
		if ( s1[i] == s2[i] && s1[i] == '\0' )
			return 0; 
		i++;
	}
}

// -------------------------------------------------- End String --------------------------------------------------

// ----------------------------------------------------------------------------------------------------------------

void drawrec(int x, int y, int width, int height, char text[])
{
	int x2, y2;
	gotoxy(x,y);
	
	putchar(201);
	for(x2 = 1; x2 < width - 2 + 1; x2++)
	{
		gotoxy(x + x2, y);
		putchar(205);
	}
	gotoxy(x + x2, y);
	putchar(187);
	
	for(y2 = 1; y2 < height - 2 + 1; y2++)
	{
		gotoxy(x + x2, y + y2);
		putchar(186);
	}
	gotoxy(x + x2, y + y2);
	putchar(188);
	
	x2--;
	for(x2; 0 < x2; x2--)
	{
		gotoxy(x + x2, y + y2);
		putchar(205);
	}
	gotoxy(x + x2, y + y2);
	putchar(200);
	
	y2--;
	for(y2; 0 < y2; y2--)
	{
		gotoxy(x + x2, y + y2);
		putchar(186);
	}
	
	// Write Text
	int x0 = x + 2, y0 = y + height / 2;
	int textlen = getlen(text);
	if (textlen < width - 4)
	{
		x0 = x + 2 + (width - 4 - textlen) / 2;
	}
	gotoxy(x0, y0);
	for(int i = 0; i < width - 4 && text[i] != '\0'; i++)
		putchar(text[i]);
}

void _drawrec(int x, int y, int width, int height, char text[], unsigned int _sleep_)
{
	int x2, y2;
	gotoxy(x,y);
	
	putchar(201);
	for(x2 = 1; x2 < width - 2 + 1; x2++)
	{
		gotoxy(x + x2, y);
		putchar(205);
		_sleep(_sleep_);
	}
	gotoxy(x + x2, y);
	putchar(187);
	
	for(y2 = 1; y2 < height - 2 + 1; y2++)
	{
		gotoxy(x + x2, y + y2);
		putchar(186);
		_sleep(_sleep_);
	}
	gotoxy(x + x2, y + y2);
	putchar(188);
	
	x2--;
	for(x2; 0 < x2; x2--)
	{
		gotoxy(x + x2, y + y2);
		putchar(205);
		_sleep(_sleep_);
	}
	gotoxy(x + x2, y + y2);
	putchar(200);
	
	y2--;
	for(y2; 0 < y2; y2--)
	{
		gotoxy(x + x2, y + y2);
		putchar(186);
		_sleep(_sleep_);
	}
	
	// Write Text
	int x0 = x + 2, y0 = y + height / 2;
	int textlen = getlen(text);
	if (textlen < width - 4)
	{
		x0 = x + 2 + (width - 4 - textlen) / 2;
	}
	gotoxy(x0, y0);
	for(int i = 0; i < width - 4 && text[i] != '\0'; i++)
		putchar(text[i]);
}

int middle(int width, int widthofitem)
{
	if (widthofitem > width) return 0;
	return (width - widthofitem) / 2;
}

int char_to_int(char temp[10])
{
	int count = 0;
	for(count; temp[count] != '\0'; count++);
	
	int number = 0;
	for(int i = 0; i < count; i++)
	{
		number *= 10;
		number += temp[i] - 48;
	}

	return number;
}

