#define _CRT_SECURE_NO_WARNINGS 1	


# include "game_three.h"

void ModeThree()
{
	int a = 1;
	int b = 1;
	int c = 1;
	char Chessboard[ROW_COLUMN][ROW_COLUMN] = { 0 };
	printf("\n--------- ��Ϸ��ʼ ---------\n");	
	// ��ʼ������
	InitializeChessboard(Chessboard);
	while (1) 
	{
		// �������
		PlayerMove(Chessboard);
		// ��ӡ����
		PrintChessboard(Chessboard);
		// �ж�����Ƿ�Ӯ
		a = IsPlayerWin(Chessboard);
		if (a == 0)
		{
			printf("��ϲ���ʤ��\n");
			break;
		}
		//�ж��Ƿ�ƽ��
		c = IsDraw(Chessboard);
		if (c == 0)
		{
			printf("ƽ��\n");
			break;
		}
		// ��������
		ComputerMove(Chessboard);
		// ��ӡ����
		PrintChessboard(Chessboard);
		// �жϵ����Ƿ�Ӯ
		b = IsComputerWin(Chessboard);
		if (b == 0)
		{
			printf("���ź�������ʤ��\n");
			break;
		}
		//�ж��Ƿ�ƽ��
		c = IsDraw(Chessboard);
		if (c == 0)
		{
			printf("ƽ��\n");
			break;
		}
	}
}