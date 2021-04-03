void loading()
{
	system("cls");
	system("title Loading...");
	system("mode con lines=10");
	system("mode con cols=78");

	char load[] = "¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦        ¦¦        ¦¦       ¦¦¦¦      ¦¦   ¦¦¦¦  ¦¦        ¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦    ¦¦¦  ¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦  ¦  ¦¦  ¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦        ¦¦  ¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦  ¦¦  ¦  ¦¦  ¦¦    ¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦  ¦¦¦    ¦¦  ¦¦¦¦  ¦¦¦¦¦¦        ¦¦        ¦¦  ¦¦¦¦  ¦¦       ¦¦¦¦      ¦¦  ¦¦¦¦   ¦¦        ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦";
	
	SetColor(8);
	for(int x = 0; x < 74; x++)
	{
		for(int y = 0; y < 8; y++)
		{
			gotoxy(x + 2, y + 1);
			
			int i = y * 74 + x;
			if (load[i] == '¦')
				putchar(219);
			else
				putchar(load[i]);
		}
	}
	
	int *pause , psize = rand() % 11 + 5;
	pause = (int *) malloc (sizeof(int) * psize);
	for(int i = 0; i < psize; i++)
	{
		*(pause + i) = rand() % 74;
	}
	
	SetColor(15);
	for(int x = 0; x < 74; x++)
	{
		_sleep(10);
		for(int i = 0; i < psize; i++)
		{
			if (x == *(pause + i))
				_sleep(rand() % 700 + 100);
		}
		
		for(int y = 0; y < 8; y++)
		{
			gotoxy(x + 2, y + 1);
			
			int i = y * 74 + x;
			if (load[i] == '¦')
				putchar(219);
			else
				putchar(load[i]);
		}
		char title[25];
		sprintf(title, "title Loading... %%%d", (x * 100) / 73);
		system(title);
	}
	_sleep(500);
	
	char welcome[] = "¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦        ¦¦  ¦¦¦¦¦¦¦¦        ¦¦        ¦   ¦¦¦¦   ¦        ¦¦¦¦  ¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦    ¦¦    ¦  ¦¦¦¦¦¦¦¦¦¦  ¦¦  ¦¦  ¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦  ¦    ¦  ¦  ¦¦¦¦¦¦¦¦¦¦  ¦    ¦  ¦¦        ¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦  ¦¦  ¦¦  ¦        ¦¦¦¦    ¦¦    ¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦  ¦¦¦¦¦¦  ¦  ¦¦¦¦¦¦¦¦¦¦   ¦¦¦¦   ¦¦        ¦¦        ¦¦        ¦¦        ¦  ¦¦¦¦¦¦  ¦        ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦";
	
	system("title Welcome!");
	for(int x = 0; x < 74; x++)
	{
		for(int y = 0; y < 8; y++)
		{
			gotoxy(x + 2, y + 1);
			
			int i = y * 74 + x;
			if (welcome[i] == '¦')
			{
				SetColor(14);
				putchar(219);
			}
			else
			{
				SetColor(1);
				putchar(219);
			}
		}
	}
	sleep(2);
	return;
}

void goodbye()
{
	system("cls");
	system("title GoodBying...");
	system("mode con lines=10");
	system("mode con cols=78");
	
	char bye[] = "¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦  ¦¦¦¦  ¦¦        ¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦  ¦¦  ¦¦¦¦¦¦¦¦¦¦  ¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦        ¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦        ¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦  ¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦¦¦  ¦¦¦¦¦        ¦¦¦¦¦ ¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦";
	
	int colors[4];
	colors[0] = 15; colors[1] = 7; colors[2] = 8; colors[3] = 0;
	
	for(int n = 0; n < 4; n++)
	{
		SetColor(colors[n]);
		
		for(int x = 0; x < 74; x++)
		{
			for(int y = 0; y < 8; y++)
			{
				gotoxy(x + 2, y + 1);
				
				int i = y * 74 + x;
				if (bye[i] == '¦')
					putchar(219);
				else
					putchar(bye[i]);
			}
		}
		_sleep(1000);
	}
	exit(0);
}

bool can_i_continue = false;
bool thread_menuAnimation_pause = false;
bool thread_menuAnimation_stop = false;

bool sleep_for_thread(int _time_)
{
	for(int i = 0; i < _time_; i++)
	{
		sleep(0);
		if (thread_menuAnimation_stop) 
		{
			can_i_continue = true;
			return true;
		}
		if (thread_menuAnimation_pause) can_i_continue = true;
		while(thread_menuAnimation_pause);
		can_i_continue = false;
		
		if (i % 50 == 0) _sleep(40);
		
	}
	return false;
}

void *thread_menuAnimation(void *arg)
{
	char *up;
	up = (char *)arg;
	char eye[] = "¦¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦    ¦¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦¦¦    ¦¦¦¦";
	char blink[] = "¦¦¦¦¦¦¦¦¦¦¦¦            ¦¦¦¦¦¦¦¦¦¦¦¦¦¦        ¦¦¦¦¦¦¦¦¦¦¦¦¦¦";
	
	int i = 1;
	while(!thread_menuAnimation_stop)
	{
		int color = i;
		i++;
		if (i == 15) i = 1;
		
		SetColor(color);
		for(int x = 0; x < 90; x++) // Colorize title
		{
			for(int y = 0; y < 7; y++)
			{
				gotoxy(x + 2, y + 1);
				
				int i = y * 90 + x;
				if (up[i] != '¦')
				{
					putchar(219);
				}
			}
		}
		
		if (i % 5 == 0)
		{
			SetColor(15);
			for(int x = 0; x < 12; x++) // Blink
			{
				for(int y = 0; y < 5; y++)
				{
					gotoxy(x + 2 + 22, y + 9 + 3);
					
					int i = y * 12 + x;
					if (blink[i] == '¦')
						putchar(219);
					else
						putchar(blink[i]);
				}
			}
			
			_sleep(300);
			
			SetColor(15);
			for(int x = 0; x < 12; x++) // Eye
			{
				for(int y = 0; y < 5; y++)
				{
					gotoxy(x + 2 + 22, y + 9 + 3);
					
					int i = y * 12 + x;
					if (eye[i] == '¦')
						putchar(219);
					else
						putchar(eye[i]);
				}
			}
			gotoxy(0, 0);
			if (sleep_for_thread(600)) return 0;
		}
		else
		{
			gotoxy(0, 0);
			if (sleep_for_thread(1000)) return 0;
		}
	}
	
	can_i_continue = true;
	return 0;
}

int mymenu(int x0, int y0, char items[28][45], int enters_above, int preselected, bool acceptanything)
{
	do
	{
		thread_menuAnimation_pause = true;
		while(!can_i_continue);
		
		int y = 0, selected = 1, numofI = 0;
		for(int i = 0; i < 28; i++)
		{
			gotoxy(x0, y0 + i);
			printf("                                             ");
		} 
		
		for(y; y < enters_above; y++);
		
		for(int i = 0; items[i][0] != '/' && i < 28; i++)
		{
			if (items[i][0] == ' ')
			{
				y++;
			}
			else if (items[i][0] == ':')
			{
				gotoxy(x0 + middle(45, getlen(items[i]) - 1), y0 + y);
				y++;
			}
			else if (items[i][0] == '#')
			{
				SetColor(15);
				gotoxy(x0 + middle(45, getlen(items[i]) - 1), y0 + y);
				for(int j = 1; j < getlen(items[i]) && j < 45 + 1; j++)
					putchar(items[i][j]);
				y++;
			}
			else
			{
				SetColor(8);
				if (selected == preselected) SetColor(15);
				drawrec(x0 + middle(45, 23), y0 + y, 23, 3, items[i]);
				y += 3;
				selected++;
				numofI++;
			}
		}
		
		thread_menuAnimation_pause = false;
		
		if (!acceptanything)
		{
			gotoxy(0 ,0);
			char ch;
			ch = getch();
			if (ch == 13) return preselected;
			if (ch != -32) continue;
			
			ch = getch();
			if (ch == 80 ) // Down
				preselected++;
			if (ch == 72) // Up
				preselected--;
				
			if (preselected > numofI) preselected = 1;			
			if (preselected < 1) preselected = numofI;			
		}
		else
			return 0;
	} while(true);
}

int menu_main()
{
	char items[28][45];
	char temp[45];
	sprintf(temp, "#Use %c%c Keys to choose an item:", 24, 25);
	
	strcpy(items[0], temp);
	strcpy(items[1], "#------------------------------");
	strcpy(items[2], " ");
	strcpy(items[3], "Play the Game");
	strcpy(items[4], " ");
	strcpy(items[5], "View Scores");
	strcpy(items[6], " ");
	strcpy(items[7], "About");
	strcpy(items[8], " ");
	strcpy(items[9], "Exit");
	strcpy(items[10], "/end");
	
	return mymenu(46, 10, items, 4, 1, false);
}

int menu_selectdifficulty()
{
	char items[28][45];
	
	strcpy(items[0], "#Select Difficulty:");
	strcpy(items[1], "#------------------");
	strcpy(items[2], " ");
	strcpy(items[3], "Easy");
	strcpy(items[4], " ");
	strcpy(items[5], "Medium");
	strcpy(items[6], " ");
	strcpy(items[7], "Hard");
	strcpy(items[8], " ");
	strcpy(items[9], "Custom...");
	strcpy(items[10], " ");
	strcpy(items[11], "Back");
	strcpy(items[12], "/end");
	
	return mymenu(46, 10, items, 3, 1, false);
}

void menu_custom(int &numofnums, int &chances)
{
	thread_menuAnimation_pause = true;
	while(!can_i_continue);
	
	showcursor();
	char items[28][45];
	
	strcpy(items[0], "#Custom Mode:");
	strcpy(items[1], "#------------");
	strcpy(items[2], " ");
	strcpy(items[3], "#Number of Numbers you must guess: ");
	strcpy(items[4], "/end");
	
numofnums:
	mymenu(46, 10, items, 1, 1, true);
	thread_menuAnimation_pause = true;
	while(!can_i_continue);
	scanf("%d", &numofnums);
	
	if (!(4 <= numofnums && numofnums <= 10))
	{
		strcpy(items[2], "#The Number should be between 4 and 10!");
		goto numofnums;
	}
	strcpy(items[2], " ");
	
	char temp1[45];
	sprintf(temp1, "#Number of Numbers you must guess: %d", numofnums);
	strcpy(items[3], temp1);
	
	
	strcpy(items[4], "#Number of chances: ");
	strcpy(items[5], "/end");
	
chances:
	mymenu(46, 10, items, 1, 1, true);
	thread_menuAnimation_pause = true;
	while(!can_i_continue);
	scanf("%d", &chances);
	
	if (!(4 <= chances && chances <= 12))
	{
		strcpy(items[2], "#The Number should be between 4 and 12!");
		goto chances;
	}
	strcpy(items[2], " ");
	
	char temp2[45];
	sprintf(temp2, "#Number of chances: %d", chances);
	strcpy(items[4], temp2);
	
	hidecursor();
	thread_menuAnimation_pause = false;
	return;
}

void menu_scores()
{
	scr scores[10];
	loadscore(scores);
	
	char items[28][45];
	strcpy(items[0], "#Best Scores:");
	strcpy(items[1], "#    Name                      Score");
	strcpy(items[2], "#-----------------------------------");
	strcpy(items[3], " ");
	strcpy(items[14], " ");
	strcpy(items[15], "Back");
	strcpy(items[16], "/end");
	
	
	char space[25];
	int y = 4;
	for(int i = 0; i < 10; i++)
	{
		int n = 0;
		for(n; n < 25 - getlen(scores[i].name); n++)
			space[n] = ' ';
		space[n] = '\0';
		
		sprintf(items[y + i], "#%2d. %s%s%6d", i + 1, scores[i].name, space, scores[i].score);
	}
	
	mymenu(46, 10, items, 5, 1, false);
	return;
}

void startgame(int numofnums, int chances);
void startagain(int numofnums, int chances)
{
	return startgame(numofnums, chances);
}
void aboutpage();
void run()
{
	thread_menuAnimation_stop = false;
	can_i_continue = false;
	
	system("title Fekr o Bekr");
	system("mode con cols=94");
	system("mode con lines=40");
	
	char up[] = "¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦      ¦¦      ¦¦  ¦¦  ¦¦    ¦¦¦¦¦¦¦¦      ¦¦¦¦¦¦¦¦     ¦¦¦      ¦¦  ¦¦  ¦¦    ¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦  ¦¦¦  ¦  ¦¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦¦¦¦  ¦¦  ¦¦  ¦¦¦¦¦¦  ¦  ¦¦¦  ¦  ¦¦¦¦¦¦¦¦¦¦¦      ¦¦      ¦¦    ¦¦¦¦    ¦¦¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦¦¦¦     ¦¦¦      ¦¦    ¦¦¦¦    ¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦¦¦¦¦¦  ¦  ¦¦¦  ¦  ¦¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦¦¦¦  ¦¦  ¦¦  ¦¦¦¦¦¦  ¦  ¦¦¦  ¦  ¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦      ¦¦  ¦¦  ¦¦  ¦¦  ¦¦¦¦¦¦      ¦¦¦¦¦¦¦¦     ¦¦¦      ¦¦  ¦¦  ¦¦  ¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦";
	char face[] = "¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                   ¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦¦  ¦¦¦¦  ¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦    ¦¦¦¦¦¦¦¦¦¦¦    ¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦¦¦¦¦  ¦¦  ¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦    ¦¦¦¦¦¦¦¦¦¦¦    ¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦  ¦¦¦¦  ¦¦¦¦                         ¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦   ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦   ¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦                 ¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦                                   ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                     ¦¦¦¦    Hello! Welcome to Fekr o Bekr    ¦¦¦¦                                     ¦¦¦¦  I'm Mostafa, Hope you enjoy it!!!  ¦¦¦¦                                     ¦¦¦¦  You can talk to me via:            ¦¦¦¦                                     ¦¦¦¦         mkay1375@gmail.com          ¦¦¦¦                 ***                 ¦¦¦¦                                     ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦";
	
	SetColor(15);
	for(int x = 0; x < 90; x++) // Title Bar
	{
		for(int y = 0; y < 7; y++)
		{
			gotoxy(x + 2, y + 1);
			
			int i = y * 90 + x;
			if (up[i] == '¦')
				putchar(219);
		}
		_sleep(10);
	}
	
	_sleep(300);
	
	for(int x = 0; x < 41; x++) // Face
	{
		for(int y = 0; y < 30; y++)
		{
			gotoxy(x + 2, y + 9);
			
			int i = y * 41 + x;
			if (face[i] == '¦')
				putchar(219);
			else
				putchar(face[i]);
		}
		_sleep(10);
	}
	gotoxy(0,0);
	_sleep(300);
	
	_drawrec(45, 9, 47, 30, "", 10);

	pthread_t pth;
	pthread_create(&pth,NULL,thread_menuAnimation, up);
	
	while(true)
	{
		switch (menu_main())
		{
			case 1:
				
				switch (menu_selectdifficulty())
				{
					case 1:
						thread_menuAnimation_stop = true;
						while(!can_i_continue);
						return startgame(5, 7);
						
					case 2:
						thread_menuAnimation_stop = true;
						while(!can_i_continue);
						return startgame(7, 7);
						
					case 3:
						thread_menuAnimation_stop = true;
						while(!can_i_continue);
						return startgame(10, 8);
						
					case 4:
						int numofnums, chances;
						char range[7];
						menu_custom(numofnums, chances);
						thread_menuAnimation_stop = true;
						while(!can_i_continue);
						return startgame(numofnums, chances);
						
					case 5: 
						break;
				}
				
				break;
				
			case 2:
				menu_scores();
				break;
			
			case 3:
				thread_menuAnimation_stop = true;
				while(!can_i_continue);
				return aboutpage();
				
			case 4:
				thread_menuAnimation_stop = true;
				while(!can_i_continue);
				return goodbye();
		}
	}
}

void aboutpage()
{
	system("cls");
	
	char about[19][70];
	strcpy(about[0], "In the Name of God");
	strcpy(about[1], "Fekr o Bekr");
	strcpy(about[2], "");
	strcpy(about[3], "The Game:");
	strcpy(about[4], "A game witch you should find the given number by trying numbers.");
	strcpy(about[5], "You have chances based on the difficulty you have selected.");
	strcpy(about[6], "\0");
	strcpy(about[7], "Developing The Game:");
	strcpy(about[8], "This game took about 22 hours to complete with a total number of");
	strcpy(about[9], "about 1000 actual lines of code and 27000 characters.");
	strcpy(about[10], "Developing the game was finished in Bahman 8, 1394, 16:12.");
	strcpy(about[11], "");
	strcpy(about[12], "More:");
	strcpy(about[13], "Teacher: Master Khademi");
	strcpy(about[14], "Developer: Mostafa Kazemi");
	strcpy(about[15], "Email Address: mkay1375@gmail.com");
	strcpy(about[16], "University: University of Science and Culture");
	strcpy(about[17], "");
	strcpy(about[18], "Press A Key to Go Back");
	
	int y0 = middle(40, 19), y = 0;
	SetColor(15);
	for(int L = 0; L < 19; L++)
	{
		gotoxy(middle(94, getlen(about[L])), y0 + y);
		
		for(int i = 0; about[L][i] != '\0'; i++)
		{
			putchar(about[L][i]);
			_sleep(30);
		}
		
		if (L == 0 || L == 1 || L == 3 || L == 6 || L == 7 || L == 11 || L == 12 || L == 16)
			sleep(1);
		y++;
	}
	
	getch();
	return run();
}
