#define _CRT_SECURE_NO_WARNINGS 1	

# include "game_three.h"

// 初始化棋盘的函数
void InitializeChessboard(char Chessboard[ROW_COLUMN][ROW_COLUMN])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW_COLUMN; i++)
	{
		for (j = 0; j < ROW_COLUMN; j++)
		{
			Chessboard[i][j] = ' ';
		}
	}

	for (i = 0;i < 2 * ROW_COLUMN + 1;i++)
	{
		if (i % 2 == 0) 
		{
			for (j = 0;j < 2 * ROW_COLUMN + 1;j++)
				printf("-");
			printf("\n");
		}
		else 
		{
			for (j = 0;j < 2 * ROW_COLUMN + 1;j++)
			{
				if (j % 2 == 0)
					printf("|");
				else
					printf("%c", Chessboard[((i - 1) / 2)][((j - 1) / 2)]);				
			}
			printf("\n");
		}
	}
	printf("\n");
}

// 玩家下棋的函数
void PlayerMove(char Chessboard[ROW_COLUMN][ROW_COLUMN])
{
	do 
	{
		int a = 0;
		int b = 0;
		printf("玩家请选择位置下棋(如:1 1) >");
		scanf("%d %d", &a, &b);
		if (a <= ROW_COLUMN && b <= ROW_COLUMN && a>0 && b>0)
		{
			if (Chessboard[(a-1)][(b-1)] == ' ')
			{
				Chessboard[(a-1)][(b-1)] = '*';
				break;
			}
			else
			{
				printf("该位置已有棋子，请重新选择位置\n");
			}
		}
	} while (1);	
}
// 电脑下棋的函数
void ComputerMove(char Chessboard[ROW_COLUMN][ROW_COLUMN]) 
{
	printf("电脑下棋\n");
	do 
	{
		int a = 0;
		int b = 0;

		srand((unsigned int)time(NULL));
		a = rand() % ROW_COLUMN;
		b = rand() % ROW_COLUMN;
		if (Chessboard[a][b] == ' ')
		{
			Chessboard[a][b] = '#';
			break;
		}
	} 
	while (1);
}

// 打印棋盘的函数
void PrintChessboard(char Chessboard[ROW_COLUMN][ROW_COLUMN])
{
	int i = 0;
	int j = 0;
	for (i = 0;i < 2 * ROW_COLUMN + 1;i++)
	{
		if (i % 2 == 0)
		{
			for (j = 0;j < 2 * ROW_COLUMN + 1;j++)
				printf("-");
			printf("\n");
		}
		else
		{
			for (j = 0;j < 2 * ROW_COLUMN + 1;j++)
			{
				if (j % 2 == 0)
					printf("|");
				else
					printf("%c", Chessboard[((i - 1) / 2)][((j - 1) / 2)]);
			}
			printf("\n");
		}
	}
	printf("\n");
}
// 判断玩家是否赢的函数
// 0 玩家赢；1 玩家未赢，游戏继续
int IsPlayerWin(char Chessboard[ROW_COLUMN][ROW_COLUMN]) 
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0;i < ROW_COLUMN;i++) 
	{
		count = 0;
		for (j = 0;j < ROW_COLUMN;j++) 
		{			
			if (Chessboard[i][j] == '*')
				count = count + 1;
			if (count == ROW_COLUMN)
				return 0;
		}
	}
	count = 0;
	for (j = 0;j < ROW_COLUMN;j++)
	{
		count = 0;
		for (i = 0;i < ROW_COLUMN;i++)
		{
			if (Chessboard[i][j] == '*')
				count = count + 1;
			if (count == ROW_COLUMN)
				return 0;
		}
	}
	count = 0;
	for (i = 0;i < ROW_COLUMN;i++)
	{
		for (j = 0;j < ROW_COLUMN;j++)
		{
			if (Chessboard[i][j] == '*' && i==j)
				count = count + 1;
			if (count == ROW_COLUMN)
				return 0;
		}
	}
	count = 0;
	for (i = 0;i < ROW_COLUMN;i++)
	{
		for (j = 0;j < ROW_COLUMN;j++)
		{
			if (Chessboard[i][j] == '*' && (i + j) == (ROW_COLUMN - 1))
				count = count + 1;
			if (count == ROW_COLUMN)
				return 0;
		}
	}
	return 1;
}
// 判断电脑是否赢的函数
// 0 电脑赢；1 电脑未赢，游戏继续
int IsComputerWin(char Chessboard[ROW_COLUMN][ROW_COLUMN])
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0;i < ROW_COLUMN;i++)
	{
		count = 0;
		for (j = 0;j < ROW_COLUMN;j++)
		{
			if (Chessboard[i][j] == '#')
				count = count + 1;
			if (count == ROW_COLUMN)
				return 0;
		}
	}
	count = 0;
	for (j = 0;j < ROW_COLUMN;j++)
	{
		count = 0;
		for (i = 0;i < ROW_COLUMN;i++)
		{
			if (Chessboard[i][j] == '#')
				count = count + 1;
			if (count == ROW_COLUMN)
				return 0;
		}
	}
	count = 0;
	for (i = 0;i < ROW_COLUMN;i++)
	{
		for (j = 0;j < ROW_COLUMN;j++)
		{
			if (Chessboard[i][j] == '#' && i == j)
				count = count + 1;
			if (count == ROW_COLUMN)
				return 0;
		}
	}
	count = 0;
	for (i = 0;i < ROW_COLUMN;i++)
	{
		for (j = 0;j < ROW_COLUMN;j++)
		{
			if (Chessboard[i][j] == '#' && (i + j) == (ROW_COLUMN - 1))
				count = count + 1;
			if (count == ROW_COLUMN)
				return 0;
		}
	}
	return 1;
}
// 判断是否平局
// 0 平局；1 游戏继续
int IsDraw(char Chessboard[ROW_COLUMN][ROW_COLUMN]) 
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 0;i < ROW_COLUMN;i++)
	{
		for (j = 0;j < ROW_COLUMN;j++)
		{
			if (Chessboard[i][j] == ' ')
				count = count + 1;			
		}	
	}
	if (count == 0)
		return 0;
	return 1;
}
