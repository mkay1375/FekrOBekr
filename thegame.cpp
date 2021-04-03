bool sleep_thread(int _time_, bool *stop, bool *pause, bool *_continue_)
{
	for(int i = 0; i < _time_; i++)
	{
		sleep(0);
		if (*pause) *_continue_ = true;
		while(*pause);
		if (*stop) 
		{
			*_continue_ = true;
			return true;
		}
		*_continue_ = false;
		
		if (i % 50 == 0) _sleep(40);
		
	}
	return false;
}

void finish(bool win, int score, int numofnums, int chances)
{
	int width = 47, height = 30;
	int x0 = 21 + middle(71, width);
	int y0 = middle(40, height);
	
	if (win) SetColor(10);
	else SetColor(4);
	
	_drawrec(x0, y0, width, height, "", 10);
	
	for(int y = 0; y < height - 2; y++)
	{
		gotoxy(x0 + 1, y0 + 1 + y);
		for(int x = 0; x < width - 2; x++)
		{
			putchar(' ');
		}
	}
	
	char items[28][45];
	
	if (win)
	{
		char c_score[45];
		sprintf(c_score, "#%d", score);
		
		strcpy(items[0], "#-- Congratulations!!! --");
		strcpy(items[1], "#---- You Have Won!! ----");
		strcpy(items[2], "#------------------------");
		strcpy(items[3], " ");
		strcpy(items[4], "#Your Score:");
		strcpy(items[5], c_score);
		strcpy(items[6], "#Enter Your Name:");
		strcpy(items[7], ":                ");
		strcpy(items[8], "/end");
		
		showcursor();
		
		mymenu(x0 + 1, y0 + 1, items, 6, 1, true);
		
		char name[30];
		name[0] = '\0';
		
		fflush(stdin);
		gets(name);
		if (name[0] == '\0')
			strcpy(name, "Player");
		
		name[24] = '\0';
		
		if ('a' <= name[0] && name[0] <= 'z')
			name[0] -= 32;
			
		savescore(name, score);
		
		hidecursor();
		
		char c_name[45];
		sprintf(c_name, "#%s", name);
		c_name[44] = '\0';
		
		strcpy(items[6], "#Your Name:");
		strcpy(items[7], c_name);
	}
	else
	{
		strcpy(items[0], " ");
		strcpy(items[1], " ");
		strcpy(items[2], "#That wasn't your time :(");
		strcpy(items[3], "#But Try Again ;)");
		strcpy(items[4], " ");
		strcpy(items[5], " ");
		strcpy(items[6], " ");
		strcpy(items[7], " ");
	}
	
	strcpy(items[8], " ");
	strcpy(items[9], "Play Again");
	strcpy(items[10], " ");
	strcpy(items[11], "Back to Menu");
	strcpy(items[12], "/end");
	
	switch(mymenu(x0 + 1, y0 + 1, items, 6, 1, false))
	{
		case 1:
			return startagain(numofnums, chances);
		case 2:
			return run();
	}
}

void sidebar()
{
	SetColor(15);
	char side[] = "    ¦¦¦¦¦¦¦¦¦      ¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦  ¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦           ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦  ¦¦¦¦¦¦¦¦¦¦¦¦¦                   Fekr    o    Bekr-----------------                                                                    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦";
	
	for(int x = 0; x < 17; x++)
	{
		for(int y = 0; y < 30; y++)
		{
			gotoxy(x + 2, y + 1);
			
			int i = y * 17 + x;
			if (side[i] == '¦')
				putchar(219);
			else
				putchar(side[i]);
		}
	}
	
	int t = 0;
	char time[13 + 1];
	sprintf(time, "Time:%8d", t);
	drawrec(2, 12, 17, 3, time);
	
	drawrec(2, 32, 17, 7, "");
	gotoxy(3, 33);
	printf(" Press");
	gotoxy(3, 34);
	printf(" Escape");
	gotoxy(3, 35);
	printf(" To Leave");
	gotoxy(3, 36);
	printf(" The Current");
	gotoxy(3, 37);
	printf(" Game");
	
	return;
}

bool start_timer = false;
bool timer_stop = false;
bool timer_pause = false;
bool can_i_continue_timer = false;
int _time = 0;
void *thread_timer(void *arg)
{
	while(!start_timer);
	long int begtime = time(0);
	
	while(!timer_stop)
	{
		gotoxy(4, 13);
		
		_time = time(0) - begtime;
		printf("Time:%8d", _time);
		
		if (sleep_thread(100, &timer_stop, &timer_pause, &can_i_continue_timer))
			return 0;
	}
	
	can_i_continue_timer = true;
	return 0;
}

int leavegame()
{
	char items[28][45];
	
	strcpy(items[0], "#Current Game is Ended!");
	strcpy(items[1], "#What do you want to do next?");
	strcpy(items[2], " ");
	strcpy(items[3], "Restart");
	strcpy(items[4], " ");
	strcpy(items[5], "Leave");
	strcpy(items[6], "/end");
	
	int width = 47, height = 30;
	int x0 = 21 + middle(71, width);
	int y0 = middle(40, height);
	
	SetColor(15);
	drawrec(x0, y0, width, height, "");
	
	for(int y = 0; y < height - 2; y++)
	{
		gotoxy(x0 + 1, y0 + 1 + y);
		for(int x = 0; x < width - 2; x++)
		{
			putchar(' ');
		}
	}
	
	return mymenu(x0 + 1, y0 + 1, items, 9, 1, false);
}
void startgame(int numofnums, int chances)
{
	system("cls");
	int x0 = 21 + middle(71, numofnums * 6 - 1);
	
	sidebar();
	
	int *answer = (int *) malloc (sizeof(int) * numofnums);
	int random = rand() % 10;
	
	SetColor(15);
	for(int x = 0; x < numofnums; x++) // Draws ? Boxes
	{
		for(int i = 0; i < x; i++)
		{
			if (random == *(answer + i))
			{
				random = rand() % 10;
				i = -1;
			}
		}
		*(answer + x) = random; 
//		char temp[2];
//		sprintf(temp, "%d", answer[x]);
		drawrec(x0 + x * 6, 0, 5, 3, "?");
	}
	
	start_timer = false;
	timer_stop = false;
	timer_pause = false;
	can_i_continue_timer = false;
	_time = 0;
	pthread_t ptimer;
	pthread_create(&ptimer, NULL, thread_timer, NULL);
	
	char (*user_input)[2];
	user_input = (char (*)[2]) malloc (sizeof(char) * numofnums * 2);
	
	int y = 3;
	for(int i; i < chances; i++)
	{
		SetColor(15);
		for(int x = 0; x < numofnums; x++) // Draws what user enters
		{
			char c[2];
			c[0] = getch();
			c[1] = '\0';
			start_timer = true;
			
			while (true) // Get char
			{
				if ('0' <= c[0] && c[0] <= '9')
					break;
				else if (c[0] == 27) // PAUSE
				{
					timer_stop = true;
					while(!can_i_continue_timer);
					
					switch (leavegame())
					{
						case 1:
							return startagain(numofnums, chances);
						case 2:
							return run();
					}
				}
				c[0] = getch();
			}
			
			user_input[x][0] = c[0];
			user_input[x][1] = '\0';
			
			timer_pause = true;
			while(!can_i_continue_timer);
			
			drawrec(x0 + x * 6, y, 5, 3, c);
			
			timer_pause = false;
		}
		
		int correct = 0;
		for(int check = 0; check < numofnums; check++) // Checks the user inputs
		{
			timer_pause = true;
			while(!can_i_continue_timer);
			
			SetColor(12);
			if (user_input[check][0] - 48 == answer[check])
			{
				correct++;
				SetColor(10);
			}
			else
			{
				for(int n = 0; n < numofnums; n++)
					if (user_input[check][0] - 48 == answer[n])
						SetColor(14);
			}
			
			drawrec(x0 + check * 6, y, 5, 3, user_input[check]);
			
			timer_pause = false;
		}
		if (correct == numofnums)
		{
			timer_stop = true;
			while(!can_i_continue_timer);
			
			if (_time > 1000) _time = 1000;
			int score = numofnums * 800 + (13 - chances) * 200 + (13 - i) * 300 + (1000 - _time) * 4;
			return finish(true, score, numofnums, chances);
		}
		y += 3;
	}
	timer_stop = true;
	while(!can_i_continue_timer);
	
	return finish(false, 0, numofnums, chances);
}
