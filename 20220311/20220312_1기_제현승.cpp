#include <stdio.h>
#include <io.h>
int main(void)
{
	int i,j, num1,num2; //반복문 변수i,j  입력할 정수(num1)및 읽어들인 바이트 데이터를 하나의 숫자로 읽어들일 숫자 변수(num2)
	int num_byte[4] = { 0, };//입력한 정수 한 바이트단위 구분할 배열

	printf("저장할 정수를 입력하시오. 정수:");
	scanf("%d",&num1); //윈도우 4바이트 정수 ->int,long

	//4바이트 데이터 저장-> 32비트, 8비트당 1바이트
	//입력한 4바이트 정수 값 한 바이트 단위로 읽어드림
	num_byte[0] = (num1 & 0xff000000) >> 24;
	num_byte[1] = (num1 & 0x00ff0000) >> 16;
	num_byte[2] = (num1 & 0x0000ff00) >> 8;
	num_byte[3] = (num1 & 0x000000ff);
			
	for (int i = 0; i < 4; i++)
	{//4바이트 정수 한 바이트씩 분리되었는지 확인
		printf("%x\n", num_byte[i]);

	}

	//파일 저장 부분
	FILE *fp = NULL;

	fp = fopen("Je2.txt", "w");
	if (fp == NULL)
	{
		printf("파일 열기 실패\n");
	}
	else
	{
		printf("파일 열기 성공\n");
	}
	//빅 엔디안(MSB->LSB)
	for ( i = 0; i < 4; i++)
	{
		fprintf(fp, "%x ", num_byte[i]);
	}
	fprintf(fp, "\n");
	//리틀 엔디안(LSB->MSB)
	for (i = 3; i >=0; i--)
	{
		fprintf(fp, "%x ", num_byte[i]);
	}
	fclose(fp);

	//읽기 추가- 0311과제
	fp = fopen("Je2.txt", "r");
	for ( i = 0; i < 2; i++)//while문 조건의 !feof(fp)로 파일 끝까지 읽어들일수 있음 but 한 파일에 각자 다른 방식으로 저장되어 있어 for문 사용
	{
		fscanf(fp, "%x %x %x %x", &num_byte[0], &num_byte[1], &num_byte[2], &num_byte[3]);

		if (i == 0)
		{
			printf("빅 엔디안(MSB->LSB)으로 읽기\n");
			for (j= 0; j < 4; j++)
			{
				printf("%x ", num_byte[j]);
			}
			printf("\n");
			num2 = num_byte[0] * 16777216 + num_byte[1] * 65536 + num_byte[2] * 256 + num_byte[3]; //빅엔디안 2^24, 2^16, 2^8, 2^0, 하나의 바이트로 쪼개진 4바이트 데이터 읽어들이는 법(빅엔디안)
			printf("빅 엔디안(MSB->LSB)으로 읽기 결과:%d\n\n", num2);
		}
		else
		{
			printf("리틀 엔디안(LSB->MSB)으로 읽기\n");
			for (j = 0; j < 4; j++)
			{
				printf("%x ", num_byte[j]);
			}
			printf("\n");
			num2 = num_byte[0] + num_byte[1]*256 + num_byte[2] * 65536 + num_byte[3] * 16777216;//리틀 엔디안 2^24, 2^16, 2^8, 2^0 하나의 바이트로 쪼개진 4바이트 데이터 읽어들이는 법(리틀 엔디안)
			printf("리틀 엔디안(LSB->MSB)으로 읽기 결과:%d\n\n", num2);
		}
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