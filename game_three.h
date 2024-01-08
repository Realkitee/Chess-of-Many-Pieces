#define _CRT_SECURE_NO_WARNINGS 1	
#define ROW_COLUMN 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ��ʼ�����̺���������
void InitializeChessboard(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// ������庯��������
void PlayerMove(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// �������庯��������
void ComputerMove(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// ��ӡ���̺���������
void PrintChessboard(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// �ж�����Ƿ�Ӯ����������
int IsPlayerWin(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// �жϵ����Ƿ�Ӯ����������
int IsComputerWin(char Chessboard[ROW_COLUMN][ROW_COLUMN]);
// �ж��Ƿ�ƽ�ֺ���������
int IsDraw(char Chessboard[ROW_COLUMN][ROW_COLUMN]);