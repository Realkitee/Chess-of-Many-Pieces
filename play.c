#define _CRT_SECURE_NO_WARNINGS 1	

# include <stdio.h>
void ModeThree();

int main()
{
	do 
	{
		int input = 0;
		printf("--------------------------\n");
		printf("--------- 0.Exit ---------\n");
		printf("--------- 1.Play ---------\n");
		printf("--------------------------\n");
		printf("请选择(0/1) >");
		scanf("%d", &input);
		if (input == 0) 
		{
			break;
		}
		else 
		{
			printf("\n三子棋模式 >");
			ModeThree();
		}

	} 
	while (1);

	return 0;
}
