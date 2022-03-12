#include <stdio.h>
#include <io.h>
int main(void)
{
	int i,j, num1,num2; //�ݺ��� ����i,j  �Է��� ����(num1)�� �о���� ����Ʈ �����͸� �ϳ��� ���ڷ� �о���� ���� ����(num2)
	int num_byte[4] = { 0, };//�Է��� ���� �� ����Ʈ���� ������ �迭

	printf("������ ������ �Է��Ͻÿ�. ����:");
	scanf("%d",&num1); //������ 4����Ʈ ���� ->int,long

	//4����Ʈ ������ ����-> 32��Ʈ, 8��Ʈ�� 1����Ʈ
	//�Է��� 4����Ʈ ���� �� �� ����Ʈ ������ �о�帲
	num_byte[0] = (num1 & 0xff000000) >> 24;
	num_byte[1] = (num1 & 0x00ff0000) >> 16;
	num_byte[2] = (num1 & 0x0000ff00) >> 8;
	num_byte[3] = (num1 & 0x000000ff);
			
	for (int i = 0; i < 4; i++)
	{//4����Ʈ ���� �� ����Ʈ�� �и��Ǿ����� Ȯ��
		printf("%x\n", num_byte[i]);

	}

	//���� ���� �κ�
	FILE *fp = NULL;

	fp = fopen("Je2.txt", "w");
	if (fp == NULL)
	{
		printf("���� ���� ����\n");
	}
	else
	{
		printf("���� ���� ����\n");
	}
	//�� �����(MSB->LSB)
	for ( i = 0; i < 4; i++)
	{
		fprintf(fp, "%x ", num_byte[i]);
	}
	fprintf(fp, "\n");
	//��Ʋ �����(LSB->MSB)
	for (i = 3; i >=0; i--)
	{
		fprintf(fp, "%x ", num_byte[i]);
	}
	fclose(fp);

	//�б� �߰�- 0311����
	fp = fopen("Je2.txt", "r");
	for ( i = 0; i < 2; i++)//while�� ������ !feof(fp)�� ���� ������ �о���ϼ� ���� but �� ���Ͽ� ���� �ٸ� ������� ����Ǿ� �־� for�� ���
	{
		fscanf(fp, "%x %x %x %x", &num_byte[0], &num_byte[1], &num_byte[2], &num_byte[3]);

		if (i == 0)
		{
			printf("�� �����(MSB->LSB)���� �б�\n");
			for (j= 0; j < 4; j++)
			{
				printf("%x ", num_byte[j]);
			}
			printf("\n");
			num2 = num_byte[0] * 16777216 + num_byte[1] * 65536 + num_byte[2] * 256 + num_byte[3]; //�򿣵�� 2^24, 2^16, 2^8, 2^0, �ϳ��� ����Ʈ�� �ɰ��� 4����Ʈ ������ �о���̴� ��(�򿣵��)
			printf("�� �����(MSB->LSB)���� �б� ���:%d\n\n", num2);
		}
		else
		{
			printf("��Ʋ �����(LSB->MSB)���� �б�\n");
			for (j = 0; j < 4; j++)
			{
				printf("%x ", num_byte[j]);
			}
			printf("\n");
			num2 = num_byte[0] + num_byte[1]*256 + num_byte[2] * 65536 + num_byte[3] * 16777216;//��Ʋ ����� 2^24, 2^16, 2^8, 2^0 �ϳ��� ����Ʈ�� �ɰ��� 4����Ʈ ������ �о���̴� ��(��Ʋ �����)
			printf("��Ʋ �����(LSB->MSB)���� �б� ���:%d\n\n", num2);
		}
		}


	fclose(fp);
	return 0;
}
/*   �ڷ��� ũ��Ȯ��

printf("char: %d, short: %d, int: %d, long: %d, long long: %d\n",
sizeof(char),        // 1: sizeof�� char �ڷ����� ũ�⸦ ����
sizeof(short),       // 2: sizeof�� short �ڷ����� ũ�⸦ ����
sizeof(int),         // 4: sizeof�� int �ڷ����� ũ�⸦ ����
sizeof(long),        // 4: sizeof�� long �ڷ����� ũ�⸦ ����
sizeof(long long)    // 8: sizeof�� long long �ڷ����� ũ�⸦ ����
);

return 0;

*/

/*
int num = 0;
FILE *fp = NULL;

fp = fopen("test.txt", "w");
if (fp == NULL)
{
printf("���� ���� ����\n");
}
else
{
printf("���� ���� ����\n");
}
//fwrite(buffer,sizeof(int), 1,fp);

fclose(fp);
*/