#include <stdio.h>
#include <math.h>

int init_num(int i, char color[], double color_value[]); //숫자
int init_mul(int i, char color[], double color_value[]); //배수
int init_err(int i, char color[], double color_value[]); // 오차

int main(void)
{
	int band_type = 0;
	char color[5];
	double color_value[5];
	double resistance_max = 0.0;
	double resistance_min = 0.0;

	printf("4색 저항인지 5색저항 인지 선택하시오. 선택: ");
	scanf("%d", &band_type);
	while (getchar() != '\n');//개행문자 제거
	for (int i = 0; i < band_type; i++)
	{
		//printf("%d \n",i); //사이클 판단
	again:
		printf("%d번째 색을 입력하시오. 입력: ", i + 1);
		scanf("%c", &color[i]);
		while (getchar() != '\n');//개행문자 제거
		//색깔 값들은 교수님 교안대로 작성


		
		if (i < band_type - 2)
		{
			if (!init_num(i, color, color_value))
			{
				goto again;
			}
			
		}
		else if (i == band_type - 2)
		{
			if (!init_mul(i, color, color_value))
			{
				goto again;
			}
		}
		else
		{
			if (!init_err(i, color, color_value))
			{
				goto again;
			}
		}
	}

	if (band_type == 4){
		resistance_max = (color_value[0] * 10 + color_value[1])*color_value[2] * (1 + color_value[3]);
		resistance_min = (color_value[0] * 10 + color_value[1])*color_value[2] * (1 - color_value[3]);
	}
	else
	{
		resistance_max = (color_value[0] * 100 + color_value[1] * 10 + color_value[2])*color_value[3] * (1 + color_value[4]);
		resistance_min = (color_value[0] * 100 + color_value[1] * 10 + color_value[2])*color_value[3] * (1 - color_value[4]);
	}

	printf("저항의 최대값은 %lf 이고 최소값은 %lf 입니다.\n", resistance_max, resistance_min); //옴 단위

	return 0;
}

int init_num(int i, char color[], double color_value[])
{
	int result = 1;
	switch (color[i])
	{
	case 'B'://검정
		color_value[i] = 0;
		break;
	case 'b'://갈색
		color_value[i] = 1;
		break;
	case 'r'://빨강
		color_value[i] = 2;
		break;
	case 'o'://주황
		color_value[i] = 3;
		break;
	case 'y'://노랑
		color_value[i] = 4;
		break;
	case 'g'://초록
		color_value[i] = 5;
		break;
	case 'u'://청색
		color_value[i] = 6;
		break;
	case 'v'://보라색
		color_value[i] = 7;
		break;
	case 's'://회색
		color_value[i] = 8;
		break;
	case 'w'://흰색
		color_value[i] = 9;
		break;
	default:
		printf("저항에 맞는 색을 입력해주세요\n");
		result = 0;
		break;
	}

	return result;
}

int init_mul(int i, char color[], double color_value[])
{
	int result = 1;
	switch (color[i])
	{
	case 'B'://검정
		color_value[i] = pow(10.0, 0);
		break;
	case 'b'://갈색
		color_value[i] = pow(10.0, 1);
		break;
	case 'r'://빨강
		color_value[i] = pow(10.0, 2);
		break;
	case 'o'://주황
		color_value[i] = pow(10.0, 3);
		break;
	case 'y'://노랑
		color_value[i] = pow(10.0, 4);
		break;
	case 'g'://초록
		color_value[i] = pow(10.0, 5);
		break;
	case 'u'://청색
		color_value[i] = pow(10.0, 6);
		break;
	case 'v'://보라색
		color_value[i] = pow(10.0, 7);
		break;
	case 's'://회색
		color_value[i] = pow(10.0, 8);
		break;
	case 'w'://흰색
		color_value[i] = pow(10.0, 9);
		break;
	case 'G'://금색
		color_value[i] = pow(10.0, -1);
		break;
	case 'S'://은색
		color_value[i] = pow(10.0, -2);
		break;
	default:
		printf("저항에 맞는 색을 입력해주세요\n");
		result = 0;
		break;
	}

	return result;
}

int init_err(int i, char color[], double color_value[])
{
	int result = 1;
	switch (color[i])
	{
	case 'b'://갈색
		color_value[i] = 0.01;
		break;
	case 'r'://빨강
		color_value[i] = 0.02;
		break;
	case 'g'://초록
		color_value[i] = 0.005;
		break;
	case 'u'://청색
		color_value[i] = 0.0025;
		break;
	case 'v'://보라색
		color_value[i] = 0.001;
		break;
	case 's'://회색
		color_value[i] = 0.0005;
		break;
	case 'G'://금색
		color_value[i] = 0.05;
		break;
	case 'S'://은색
		color_value[i] = 0.1;
		break;
	default:
		printf("저항에 맞는 색을 입력해주세요\n");
		result = 0;
		break;
	}

	return result;
}