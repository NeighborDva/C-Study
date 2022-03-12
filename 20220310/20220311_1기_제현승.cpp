#include <stdio.h>
#include <io.h>
int main(void)
{
	int i, num;
	int num_byte[4] = { 0, };//입력한 정수 한 바이트단위 구분할 배열

	printf("저장할 정수를 입력하시오. 정수:");
	scanf("%d",&num); //윈도우 4바이트 정수 ->int,long

	//4바이트 데이터 저장-> 32비트, 8비트당 1바이트
	//입력한 4바이트 정수 값 한 바이트 단위로 읽어드림
	num_byte[0] = (num & 0xff000000) >> 24;
	num_byte[1] = (num & 0x00ff0000) >> 16;
	num_byte[2] = (num & 0x0000ff00) >> 8;
	num_byte[3] = (num & 0x000000ff);
			
	for (int i = 0; i < 4; i++)
	{//4바이트 정수 한 바이트씩 분리되었는지 확인
		printf("%x\n", num_byte[i]);

	}

	//파일 저장 부분
	FILE *fp = NULL;

	fp = fopen("Je.txt", "w");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
	}
	else
	{
		printf("파일 열기 성공\n");
	}
	fprintf(fp, "빅 엔디안(MSB->LSB)\n");
	for ( i = 0; i < 4; i++)
	{
		fprintf(fp, "%x ", num_byte[i]);
	}
	fprintf(fp, "\n");
	fprintf(fp, "리틀 엔디안(LSB->MSB)\n");
	for (i = 3; i >=0; i--)
	{
		fprintf(fp, "%x ", num_byte[i]);
	}

	fclose(fp);
	return 0;
}
/*   자료형 크기확인

printf("char: %d, short: %d, int: %d, long: %d, long long: %d\n",
sizeof(char),        // 1: sizeof로 char 자료형의 크기를 구함
sizeof(short),       // 2: sizeof로 short 자료형의 크기를 구함
sizeof(int),         // 4: sizeof로 int 자료형의 크기를 구함
sizeof(long),        // 4: sizeof로 long 자료형의 크기를 구함
sizeof(long long)    // 8: sizeof로 long long 자료형의 크기를 구함
);

return 0;

*/

/*
int num = 0;
FILE *fp = NULL;

fp = fopen("test.txt", "w");
if (fp == NULL)
{
printf("파일 열기 실패\n");
}
else
{
printf("파일 열기 성공\n");
}
//fwrite(buffer,sizeof(int), 1,fp);

fclose(fp);
*/