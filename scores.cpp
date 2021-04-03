struct scr {
	char name[30];
	int score;
};

int loadscore(scr scores[10])
{
	for (int i = 0; i < 10; i++)
	{
		strcpy(scores[i].name, "<No Name>");
		scores[i].score = 0;
	}
	
	FILE *fp;
	fp = fopen("scores", "rt");
	
	
	int L = 0;
	if (fp != 0)
	{
		char tline[45];
		
		for (int j = 0; j < 10 & !feof(fp); j++)
		{
			fgets(tline, 45, fp);
			
			int i = 0;
			for(i; tline[i] != 1; i++)
				scores[L].name[i] = tline[i];
				
			scores[L].name[i] = '\0';
			
			char tscore[10];
			i++;
			int n = 0;
			for(i, n; tline[i] != '\n'; i++, n++)
				tscore[n] = tline[i];
				
			tscore[n] = '\0';
			
			scores[L].score = char_to_int(tscore);
			
			L++;
		}
	}
	fclose(fp);
	return L;
}

void savescore(char name[30], int score)
{
	struct scr scores[10];
	loadscore(scores);
	
	FILE *fp;
	fp = fopen("scores", "wt");
	
	int plus = 0;
	for(int i = 0; i < 10; i++)
	{
		if (score > scores[i].score && plus == 0)
		{
			char temp[45];
			sprintf(temp, "%s%c%d\n", name, 1, score);
			fputs(temp, fp);
			
			plus--;
		}
		else
		{
			char temp[45];
			sprintf(temp, "%s%c%d\n", scores[i + plus].name, 1, scores[i + plus].score);
			fputs(temp, fp);
		}
	}
	fclose(fp);
	return;
}
