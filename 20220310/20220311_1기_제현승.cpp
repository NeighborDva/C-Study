#include <stdio.h>
#include <io.h>
int main(void)
{
	int i, num;
	int num_byte[4] = { 0, };//�Է��� ���� �� ����Ʈ���� ������ �迭

	printf("������ ������ �Է��Ͻÿ�. ����:");
	scanf("%d",&num); //������ 4����Ʈ ���� ->int,long

	//4����Ʈ ������ ����-> 32��Ʈ, 8��Ʈ�� 1����Ʈ
	//�Է��� 4����Ʈ ���� �� �� ����Ʈ ������ �о�帲
	num_byte[0] = (num & 0xff000000) >> 24;
	num_byte[1] = (num & 0x00ff0000) >> 16;
	num_byte[2] = (num & 0x0000ff00) >> 8;
	num_byte[3] = (num & 0x000000ff);
			
	for (int i = 0; i < 4; i++)
	{//4����Ʈ ���� �� ����Ʈ�� �и��Ǿ����� Ȯ��
		printf("%x\n", num_byte[i]);

	}

	//���� ���� �κ�
	FILE *fp = NULL;

	fp = fopen("Je.txt", "w");
	if (fp == NULL)
	{
		printf("���� ���� ����\n");
	}
	else
	{
		printf("���� ���� ����\n");
	}
	fprintf(fp, "�� �����(MSB->LSB)\n");
	for ( i = 0; i < 4; i++)
	{
		fprintf(fp, "%x ", num_byte[i]);
	}
	fprintf(fp, "\n");
	fprintf(fp, "��Ʋ �����(LSB->MSB)\n");
	for (i = 3; i >=0; i--)
	{
		fprintf(fp, "%x ", num_byte[i]);
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