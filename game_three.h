#define _CRT_SECURE_NO_WARNINGS 1	
#define ROW_COLUMN 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 初始化棋盘函数的声明
void InitializeChessboard(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// 玩家下棋函数的声明
void PlayerMove(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// 电脑下棋函数的声明
void ComputerMove(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// 打印棋盘函数的声明
void PrintChessboard(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// 判断玩家是否赢函数的声明
int IsPlayerWin(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// 判断电脑是否赢函数的声明
int IsComputerWin(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// 判断是否平局函数的声明
int IsDraw(char Chessboard[ROW_COLUMN][ROW_COLUMN]);