#include <stdio.h>
#include <math.h>

/*
선택한 저항의 색갈을 입력하면 저항 값을 알 수 있고, 계산된 저항값이 어떤 색의 저항이 될 수 있는지 알려주는 프로그램 입니다. 
저항의 색을 입력하면 해당 저항의 오차가 적용된 최대 최소의 저항 값을 계산하여 출력하고 
*/
 

//

int register_val = 0; //scanf로 저항 값 입력받는 변수, but 여기에서는 저항 유형에 따른 저항계산을 이용하여 초기화

int init_num(int i, char color[], double color_value[]); //숫자
int init_mul(int i, char color[], double color_value[]); //배수
int init_err(int i, char color[], double color_value[]); // 오차

void color_code(int value);
void init_err2(int band, int register_val_err, char register_band[5]); //오차율
void init_mul2(int band, int register_mul, char register_band[5]);//배수
void init_color2(int band, int register_val, int register_mul, char register_band[5]);//색상




int main(void)
{
	//저항 색상 입력해서 저항값 계산하는 프로그램에서 사용되는 변수들
	int band_type = 0; //4색 저항인지 5색저항인지 판단
	char color[5]; //입력한 컬러 문자를 가지고 있는 char배열
	double color_value[5]; //각 컬러에 해당하는 값을 가질 수 있도록 하는 배열
	double resistance_max = 0.0; // 오차 적용했을 때 가질 수 있는 최대 저항 값
	double resistance_min = 0.0; // 오차 적용했을 때 가질 수 있는 최소 저항 값

	

	///저항 색상 입력하여 저항 값 구하는 코드부분
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
		register_val = (int)((color_value[0] * 10 + color_value[1])*color_value[2]);
		resistance_min = (color_value[0] * 10 + color_value[1])*color_value[2] * (1 - color_value[3]);
	}
	else
	{
		resistance_max = (color_value[0] * 100 + color_value[1] * 10 + color_value[2])*color_value[3] * (1 + color_value[4]);
		register_val =  (int)((color_value[0] * 100 + color_value[1] * 10 + color_value[2])*color_value[3]);
		resistance_min = (color_value[0] * 100 + color_value[1] * 10 + color_value[2])*color_value[3] * (1 - color_value[4]);
	}

	printf("저항의 최대값은 %lf 이고 최소값은 %lf 입니다.\n\n", resistance_max, resistance_min); //옴 단위

	/////////////////////////

	//printf("%d\n", register_val);//오차 없는 register_val 확인


	///입력된 저항 값으로 저항의 색상 코드 구하는 부분 , 오차 적용 최대 최소 저항 값 입력시의 색상 코드 및 오차 미적용 저항 값 입력되어 색상코드 산출
	//오차가 미적용된 값이 계산되어 들어가면  오차가 가장 작은 색으로 설정되게 함
	
	printf("저항 최대값\n");
	color_code(resistance_max);
	printf("\n\n");
	printf("저항 기본값\n");
	color_code(register_val);
	printf("\n\n");
	printf("저항 최소값\n");
	color_code(resistance_min);
	printf("\n\n");
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

void color_code(int value)
{
	//저항 값 으로 색상코드 판단
	char register_band[5] = { '-', }; // 저항 값이 입력되었을 때 계산 후 어떤 색상을 가지는지 관련 문자를 보관하는 배열

	
	int register_val2 = 0; //저항 계산에 사용되는 저항 값 변수
	int register_val_tmp = 0; //저항 값은 계산할 때 여러번 이용되기 때문에 원래의 값을 보관할 변수 필요 
	int register_val_err = 0; //오차 변수
	int register_val_check = 1; //오차 여부 판단을 위한 변수

	int register_mul = 0;//배수


	int num_digit = 0; //저항값 자리 수 판단을 위한 것
	/////

	register_val2 = (int)value;
	register_val_tmp = register_val2;



	while (register_val2 != 0)
	{
		num_digit++;
		register_val2 = register_val2 / 10;
	}
	register_val2 = register_val_tmp;
	if (register_val2<register_val)
	{
		num_digit++; // 오차 적용 후 이므로 실제 자리수는 +1 되어야함

	}

	register_val2 = register_val_tmp;
	//printf("%d\n",num_digit); //자릿 수 확인

	for (int i = 0; i < num_digit - 2; i++) //4band 
	{
		register_mul++; // 우리가 입력한 저항의 값이 모르는 경우 이렇게 하면 되지만 지금은 알고 있으니 min으로 했을 경우 대비하여 +1한다.

		if (register_val2 % 10 != 0)//0이 아니면 오차범위가 적용되었다고 판단
			register_val_check = 0;

		register_val2 = register_val2 / 10;
	}

	register_val2 = register_val_tmp;

	//register_val_err = register_val_tmp - register_val*pow(10.0, register_mul);
	register_val_err = register_val2 - register_val;
	//printf("%d\n", register_val_err);
	register_val_err = ((double)(register_val_err) / register_val) * 100;
	//printf("%d\n", register_val_err);
	//printf("%d",register_val_err);

	//오차 색상 입력
	//정수형 입력이라 오차 범위가 소수점인 색은 제외(정수 오차) -> 그래서 예외가 발생할수 있음

	if (register_val_check == 0 || (register_val2 <register_val))
	{
		init_err2(4, register_val_err, register_band);
	}
	else // 오차 없음, 오차 허용 범위가 가장 적은 회색 지정
	{
		register_band[3] = 'g';
	}
	//배수 입력
	init_mul2(4, register_mul, register_band);

	//색깔코드 결정
	init_color2(4, register_val, register_mul, register_band);

	printf("4색 저항의 색상 코드:");
	for (int i = 0; i < 4; i++)
	{
		printf("%c ", register_band[i]);
	}
	printf("\n");

	//5band시작
	register_val2 = register_val_tmp;
	register_mul = 0;
	for (int i = 0; i < num_digit - 3; i++) //5band 
	{
		register_mul++;

		if (register_val % 10 != 0)
			register_val_check = 0;

		register_val2 = register_val2 / 10;
	}

	register_val2 = register_val_tmp;


	register_val_err = register_val2 - register_val;
	//printf("%d\n", register_val_err);
	register_val_err = ((double)(register_val_err) / register_val) * 100;

	//printf("%d", register_val_err);

	//오차 색상 입력
	//정수형 입력이라 오차 범위가 소수점인 색은 제외(정수 오차) -> 그래서 예외가 발생할수 있음
	if (register_val_check == 0 || (register_val2 <register_val))
	{
		init_err2(5, register_val_err, register_band);
	}
	else // 오차 없음, 오차 허용 범위가 가장 적은 회색 지정
	{
		register_band[4] = 'g';
	}

	//배수 입력
	init_mul2(5, register_mul, register_band);

	//색깔코드 결정
	init_color2(5, register_val, register_mul, register_band);


	printf("5색 저항의 색상 코드:");
	for (int i = 0; i < 5; i++)
	{
		printf("%c ", register_band[i]);
	}
	printf("\n");
}

void init_err2(int band, int register_val_err, char register_band[5])
{
	if (register_val_err < 0) //-의 오차가 나왔을 때 계산을 제대로 적용하기 위해서
	{
		register_val_err = -register_val_err;
	}

	if (band == 4) //4색 
	{
		if (register_val_err <= 1)
			register_band[3] = 'b';
		else if (register_val_err <= 2)
		{
			register_band[3] = 'r';
		}
		else if (register_val_err <= 3)
		{
			register_band[3] = 'o';
		}
		else if (register_val_err <= 4)
		{
			register_band[3] = 'y';
		}
		else if (register_val_err <= 5)
		{
			register_band[3] = 'G';//금색
		}
		else if (register_val_err <= 10)
		{
			register_band[3] = 's';
		}
		else
		{
			printf("허용되는 오차 범위가 아닙니다.\n");
		}
	}
	else // 5색
	{
		if (register_val_err <= 1)
			register_band[4] = 'b';
		else if (register_val_err <= 2)
		{
			register_band[4] = 'r';
		}
		else if (register_val_err <= 3)
		{
			register_band[4] = 'o';
		}
		else if (register_val_err <= 4)
		{
			register_band[4] = 'y';
		}
		else if (register_val_err <= 5)
		{
			register_band[4] = 'G';//금색
		}
		else if (register_val_err <= 10)
		{
			register_band[4] = 's';
		}
		else
		{
			printf("허용되는 오차 범위가 아닙니다.\n");
		}
	}
}

void init_mul2(int band, int register_mul, char register_band[5])
{
	if (band == 4){//4색
		switch (register_mul) //배수 색상 입력
		{//정수형 입력이라 배수가 소수점인 금, 은은 제외
		case 0:
			register_band[2] = 'B';
			break;
		case 1:
			register_band[2] = 'b';
			break;
		case 2:
			register_band[2] = 'r';
			break;
		case 3:
			register_band[2] = 'o';
			break;
		case 4:
			register_band[2] = 'y';
			break;
		case 5:
			register_band[2] = 'n'; //초록
			break;
		case 6:
			register_band[2] = 'b';
			break;
		case 7:
			register_band[2] = 'v';
			break;
		case 8:
			register_band[2] = 'g'; //회색
			break;
		case 9:
			register_band[2] = 'w';
			break;
		default:
			printf("정수형 저항값을 입력해주세요.");
			break;
		}
		//printf("%d\n",register_mul); 배수확인
	}
	else//5색
	{
		switch (register_mul) //배수 색상 입력
		{//정수형 입력이라 배수가 소수점인 금, 은은 제외
		case 0:
			register_band[3] = 'B';
			break;
		case 1:
			register_band[3] = 'b';
			break;
		case 2:
			register_band[3] = 'r';
			break;
		case 3:
			register_band[3] = 'o';
			break;
		case 4:
			register_band[3] = 'y';
			break;
		case 5:
			register_band[3] = 'n';//초록
			break;
		case 6:
			register_band[3] = 'b';
			break;
		case 7:
			register_band[3] = 'v';
			break;
		case 8:
			register_band[3] = 'g';//회색
			break;
		case 9:
			register_band[3] = 'w';
			break;
		default:
			printf("정수형 저항값을 입력해주세요.");
			break;
		}
		//printf("%d\n",register_mul); 배수확인
	}
}

void init_color2(int band, int register_val, int register_mul, char register_band[5])
{
	int num = 0;
	num = (int)pow(10.0,register_mul);
	//printf("%d \n", num);
	register_val = register_val / num;
	//printf("%d \n", register_val);
	if (band == 4){//4색
		switch (register_val % 10)
		{//정수형 입력이라 배수가 소수점인 금, 은은 제외
		case 0:
			register_band[1] = 'B';
			break;
		case 1:
			register_band[1] = 'b';
			break;
		case 2:
			register_band[1] = 'r';
			break;
		case 3:
			register_band[1] = 'o';
			break;
		case 4:
			register_band[1] = 'y';
			break;
		case 5:
			register_band[1] = 'n'; //초록색
			break;
		case 6:
			register_band[1] = 'b';
			break;
		case 7:
			register_band[1] = 'v';
			break;
		case 8:
			register_band[1] = 'g';//회색
			break;
		case 9:
			register_band[1] = 'w';
			break;
		default:
			printf("저항 색상의 범위가 아닙니다.");
			break;
		}
		//printf("%d \n",register_val);
		register_val = register_val / 10;
		switch (register_val % 10)//
		{//정수형 입력이라 배수가 소수점인 금, 은은 제외
		case 0:
			register_band[0] = 'B';
			break;
		case 1:
			register_band[0] = 'b';
			break;
		case 2:
			register_band[0] = 'r';
			break;
		case 3:
			register_band[0] = 'o';
			break;
		case 4:
			register_band[0] = 'y';
			break;
		case 5:
			register_band[0] = 'n';//초록색
			break;
		case 6:
			register_band[0] = 'b';
			break;
		case 7:
			register_band[0] = 'v';
			break;
		case 8:
			register_band[0] = 'g';//회색
			break;
		case 9:
			register_band[0] = 'w';
			break;
		default:
			printf("저항 색상의 범위가 아닙니다.");
			break;
		}
	}
	else //5색
	{
		//printf("%d \n", register_val);
		switch (register_val % 10)//
		{//정수형 입력이라 배수가 소수점인 금, 은은 제외
		case 0:
			register_band[2] = 'B';
			break;
		case 1:
			register_band[2] = 'b';
			break;
		case 2:
			register_band[2] = 'r';
			break;
		case 3:
			register_band[2] = 'o';
			break;
		case 4:
			register_band[2] = 'y';
			break;
		case 5:
			register_band[2] = 'n';//초록
			break;
		case 6:
			register_band[2] = 'b';
			break;
		case 7:
			register_band[2] = 'v';
			break;
		case 8:
			register_band[2] = 'g';// 회색
			break;
		case 9:
			register_band[2] = 'w';
			break;
		default:
			printf("저항 색상의 범위가 아닙니다.");
			break;
		}

		register_val = register_val / 10;
		switch (register_val % 10)//
		{//정수형 입력이라 배수가 소수점인 금, 은은 제외
		case 0:
			register_band[1] = 'B';
			break;
		case 1:
			register_band[1] = 'b';
			break;
		case 2:
			register_band[1] = 'r';
			break;
		case 3:
			register_band[1] = 'o';
			break;
		case 4:
			register_band[1] = 'y';
			break;
		case 5:
			register_band[1] = 'n';//초록
			break;
		case 6:
			register_band[1] = 'b';
			break;
		case 7:
			register_band[1] = 'v';
			break;
		case 8:
			register_band[1] = 'g'; //회색
			break;
		case 9:
			register_band[1] = 'w';
			break;
		default:
			printf("저항 색상의 범위가 아닙니다.");
			break;
		}

		register_val = register_val / 10;
		switch (register_val % 10)//
		{//정수형 입력이라 배수가 소수점인 금, 은은 제외
		case 0:
			register_band[0] = 'B';
			break;
		case 1:
			register_band[0] = 'b';
			break;
		case 2:
			register_band[0] = 'r';
			break;
		case 3:
			register_band[0] = 'o';
			break;
		case 4:
			register_band[0] = 'y';
			break;
		case 5:
			register_band[0] = 'n';//초록
			break;
		case 6:
			register_band[0] = 'b';
			break;
		case 7:
			register_band[0] = 'v';
			break;
		case 8:
			register_band[0] = 'g';//회색
			break;
		case 9:
			register_band[0] = 'w';
			break;
		default:
			printf("저항 색상의 범위가 아닙니다.");
			break;
		}
	}
}