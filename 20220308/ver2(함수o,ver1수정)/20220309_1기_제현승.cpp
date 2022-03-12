#include <stdio.h>
#include <math.h>

void init_err(int band, int register_val_err ,char register_band[5]);
void init_mul(int band, int register_mul, char register_band[5]);
void init_color(int band, int register_val,char register_band[5]);

int main(void)
{
	char register_band[5] = {'-',};


	int register_val = 0;
	int register_val_tmp = 0;
	int register_val_err = 0;
	int register_val_check = 1;

	int register_mul = 0;//배수
	

	int num_digit = 0;

	printf("저항 값을 입력하시오 입력: ");
	scanf("%d", &register_val);

	register_val_tmp = register_val;
	while (register_val != 0)
	{
		num_digit++;
		register_val = register_val / 10;
	}
	register_val = register_val_tmp;
	//printf("%d\n",num_digit); //자릿 수 확인

	for (int i = 0; i < num_digit-2; i++) //4band 
	{
		register_mul++;

		if (register_val % 10 != 0)//0이 아니면 오차범위가 적용되었다고 판단
			register_val_check = 0;

		register_val = register_val / 10;
	}

	


	register_val_err = register_val_tmp - register_val*pow(10.0, register_mul);
	//printf("%d\n", register_val_err);
	register_val_err = (register_val_err /( register_val*pow(10.0, register_mul))) * 100;

	//printf("%d",register_val_err);

	//오차 색상 입력
	//정수형 입력이라 오차 범위가 소수점인 색은 제외(정수 오차) -> 그래서 예외가 발생할수 있음
	if (register_val_check == 0)
	{
		init_err(4, register_val_err, register_band);
	}
	else // 오차 없음, 오차 허용 범위가 가장 적은 회색 지정
	{
		register_band[3] = 'g';
	}
	/*
	switch (register_val_err) //오차 색상 입력
	{//정수형 입력이라 배수가 소수점인 금, 은은 제외
	case 1:
		register_4band[3] = 'b';
		break;
	case 2:
		register_4band[3] = 'r';
		break;
	case 3:
		register_4band[3] = 'o';
		break;
	case 4:
		register_4band[3] = 'y';
		break;
	case 5:
		register_4band[3] = 'G';
		break;
	case 10:
		register_4band[3] = 's';
		break;
	default:
		printf("정수형 저항값을 입력해주세요.");
		break;
	}
	*/
	
	//배수 입력
	init_mul(4,register_mul,register_band);
	
	//색깔코드 결정
	init_color(4,register_val,register_band);

	printf("4색 저항의 색상 코드:");
	for (int i = 0; i < 4; i++)
	{
		printf("%c ", register_band[i]);
	}
	printf("\n");

	//5band시작
	register_val = register_val_tmp;
	register_mul = 0;
	for (int i = 0; i < num_digit - 3; i++) //5band 
	{
		register_mul++;

		if (register_val % 10 != 0)
			register_val_check = 0;

		register_val = register_val / 10;
	}




	register_val_err = register_val_tmp - register_val*pow(10.0, register_mul);
	//printf("%d\n", register_val_err);
	register_val_err = (register_val_err / (register_val*pow(10.0, register_mul))) * 100;

	//printf("%d", register_val_err);

	//오차 색상 입력
	//정수형 입력이라 오차 범위가 소수점인 색은 제외(정수 오차) -> 그래서 예외가 발생할수 있음
	if (register_val_check == 0)
	{
		init_err(5, register_val_err, register_band);
	}
	else // 오차 없음, 오차 허용 범위가 가장 적은 회색 지정
	{
		register_band[4] = 'g';
	}
	
	//배수 입력
	init_mul(5,register_mul,register_band);

	//색깔코드 결정
	init_color(5, register_val, register_band);


	printf("5색 저항의 색상 코드:");
	for (int i = 0; i < 5; i++)
	{
		printf("%c ", register_band[i]);
	}
	printf("\n");

}


void init_err(int band, int register_val_err, char register_band[5])
{
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

void init_mul(int band, int register_mul, char register_band[5])
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

void init_color(int band, int register_val, char register_band[5])
{
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