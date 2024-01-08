#define _CRT_SECURE_NO_WARNINGS 1	


# include "game_three.h"

void ModeThree()
{
	int a = 1;
	int b = 1;
	int c = 1;
	char Chessboard[ROW_COLUMN][ROW_COLUMN] = { 0 };
	printf("\n--------- 游戏开始 ---------\n");	
	// 初始化棋盘
	InitializeChessboard(Chessboard);
	while (1) 
	{
		// 玩家下棋
		PlayerMove(Chessboard);
		// 打印棋盘
		PrintChessboard(Chessboard);
		// 判断玩家是否赢
		a = IsPlayerWin(Chessboard);
		if (a == 0)
		{
			printf("恭喜玩家胜利\n");
			break;
		}
		//判断是否平局
		c = IsDraw(Chessboard);
		if (c == 0)
		{
			printf("平局\n");
			break;
		}
		// 电脑下棋
		ComputerMove(Chessboard);
		// 打印棋盘
		PrintChessboard(Chessboard);
		// 判断电脑是否赢
		b = IsComputerWin(Chessboard);
		if (b == 0)
		{
			printf("很遗憾，电脑胜利\n");
			break;
		}
		//判断是否平局
		c = IsDraw(Chessboard);
		if (c == 0)
		{
			printf("平局\n");
			break;
		}
	}
}