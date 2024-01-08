#define _CRT_SECURE_NO_WARNINGS 1	

# include "game_three.h"

// ��ʼ�����̵ĺ���
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

// �������ĺ���
void PlayerMove(char Chessboard[ROW_COLUMN][ROW_COLUMN])
{
	do 
	{
		int a = 0;
		int b = 0;
		printf("�����ѡ��λ������(��:1 1) >");
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
				printf("��λ���������ӣ�������ѡ��λ��\n");
			}
		}
	} while (1);	
}
// ��������ĺ���
void ComputerMove(char Chessboard[ROW_COLUMN][ROW_COLUMN]) 
{
	printf("��������\n");
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

// ��ӡ���̵ĺ���
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
// �ж�����Ƿ�Ӯ�ĺ���
// 0 ���Ӯ��1 ���δӮ����Ϸ����
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
// �жϵ����Ƿ�Ӯ�ĺ���
// 0 ����Ӯ��1 ����δӮ����Ϸ����
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
// �ж��Ƿ�ƽ��
// 0 ƽ�֣�1 ��Ϸ����
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
