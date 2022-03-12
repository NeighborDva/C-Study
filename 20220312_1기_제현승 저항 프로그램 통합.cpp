#include <stdio.h>
#include <math.h>

/*
������ ������ ������ �Է��ϸ� ���� ���� �� �� �ְ�, ���� ���װ��� � ���� ������ �� �� �ִ��� �˷��ִ� ���α׷� �Դϴ�. 
������ ���� �Է��ϸ� �ش� ������ ������ ����� �ִ� �ּ��� ���� ���� ����Ͽ� ����ϰ� 
*/
 

//

int register_val = 0; //scanf�� ���� �� �Է¹޴� ����, but ���⿡���� ���� ������ ���� ���װ���� �̿��Ͽ� �ʱ�ȭ

int init_num(int i, char color[], double color_value[]); //����
int init_mul(int i, char color[], double color_value[]); //���
int init_err(int i, char color[], double color_value[]); // ����

void color_code(int value);
void init_err2(int band, int register_val_err, char register_band[5]); //������
void init_mul2(int band, int register_mul, char register_band[5]);//���
void init_color2(int band, int register_val, int register_mul, char register_band[5]);//����




int main(void)
{
	//���� ���� �Է��ؼ� ���װ� ����ϴ� ���α׷����� ���Ǵ� ������
	int band_type = 0; //4�� �������� 5���������� �Ǵ�
	char color[5]; //�Է��� �÷� ���ڸ� ������ �ִ� char�迭
	double color_value[5]; //�� �÷��� �ش��ϴ� ���� ���� �� �ֵ��� �ϴ� �迭
	double resistance_max = 0.0; // ���� �������� �� ���� �� �ִ� �ִ� ���� ��
	double resistance_min = 0.0; // ���� �������� �� ���� �� �ִ� �ּ� ���� ��

	

	///���� ���� �Է��Ͽ� ���� �� ���ϴ� �ڵ�κ�
	printf("4�� �������� 5������ ���� �����Ͻÿ�. ����: ");
	scanf("%d", &band_type);
	while (getchar() != '\n');//���๮�� ����
	for (int i = 0; i < band_type; i++)
	{
		//printf("%d \n",i); //����Ŭ �Ǵ�
	again:
		printf("%d��° ���� �Է��Ͻÿ�. �Է�: ", i + 1);
		scanf("%c", &color[i]);
		while (getchar() != '\n');//���๮�� ����
		//���� ������ ������ ���ȴ�� �ۼ�



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

	printf("������ �ִ밪�� %lf �̰� �ּҰ��� %lf �Դϴ�.\n\n", resistance_max, resistance_min); //�� ����

	/////////////////////////

	//printf("%d\n", register_val);//���� ���� register_val Ȯ��


	///�Էµ� ���� ������ ������ ���� �ڵ� ���ϴ� �κ� , ���� ���� �ִ� �ּ� ���� �� �Է½��� ���� �ڵ� �� ���� ������ ���� �� �ԷµǾ� �����ڵ� ����
	//������ ������� ���� ���Ǿ� ����  ������ ���� ���� ������ �����ǰ� ��
	
	printf("���� �ִ밪\n");
	color_code(resistance_max);
	printf("\n\n");
	printf("���� �⺻��\n");
	color_code(register_val);
	printf("\n\n");
	printf("���� �ּҰ�\n");
	color_code(resistance_min);
	printf("\n\n");
	return 0;
}

int init_num(int i, char color[], double color_value[])
{
	int result = 1;
	switch (color[i])
	{
	case 'B'://����
		color_value[i] = 0;
		break;
	case 'b'://����
		color_value[i] = 1;
		break;
	case 'r'://����
		color_value[i] = 2;
		break;
	case 'o'://��Ȳ
		color_value[i] = 3;
		break;
	case 'y'://���
		color_value[i] = 4;
		break;
	case 'g'://�ʷ�
		color_value[i] = 5;
		break;
	case 'u'://û��
		color_value[i] = 6;
		break;
	case 'v'://�����
		color_value[i] = 7;
		break;
	case 's'://ȸ��
		color_value[i] = 8;
		break;
	case 'w'://���
		color_value[i] = 9;
		break;
	default:
		printf("���׿� �´� ���� �Է����ּ���\n");
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
	case 'B'://����
		color_value[i] = pow(10.0, 0);
		break;
	case 'b'://����
		color_value[i] = pow(10.0, 1);
		break;
	case 'r'://����
		color_value[i] = pow(10.0, 2);
		break;
	case 'o'://��Ȳ
		color_value[i] = pow(10.0, 3);
		break;
	case 'y'://���
		color_value[i] = pow(10.0, 4);
		break;
	case 'g'://�ʷ�
		color_value[i] = pow(10.0, 5);
		break;
	case 'u'://û��
		color_value[i] = pow(10.0, 6);
		break;
	case 'v'://�����
		color_value[i] = pow(10.0, 7);
		break;
	case 's'://ȸ��
		color_value[i] = pow(10.0, 8);
		break;
	case 'w'://���
		color_value[i] = pow(10.0, 9);
		break;
	case 'G'://�ݻ�
		color_value[i] = pow(10.0, -1);
		break;
	case 'S'://����
		color_value[i] = pow(10.0, -2);
		break;
	default:
		printf("���׿� �´� ���� �Է����ּ���\n");
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
	case 'b'://����
		color_value[i] = 0.01;
		break;
	case 'r'://����
		color_value[i] = 0.02;
		break;
	case 'g'://�ʷ�
		color_value[i] = 0.005;
		break;
	case 'u'://û��
		color_value[i] = 0.0025;
		break;
	case 'v'://�����
		color_value[i] = 0.001;
		break;
	case 's'://ȸ��
		color_value[i] = 0.0005;
		break;
	case 'G'://�ݻ�
		color_value[i] = 0.05;
		break;
	case 'S'://����
		color_value[i] = 0.1;
		break;
	default:
		printf("���׿� �´� ���� �Է����ּ���\n");
		result = 0;
		break;
	}

	return result;
}

void color_code(int value)
{
	//���� �� ���� �����ڵ� �Ǵ�
	char register_band[5] = { '-', }; // ���� ���� �ԷµǾ��� �� ��� �� � ������ �������� ���� ���ڸ� �����ϴ� �迭

	
	int register_val2 = 0; //���� ��꿡 ���Ǵ� ���� �� ����
	int register_val_tmp = 0; //���� ���� ����� �� ������ �̿�Ǳ� ������ ������ ���� ������ ���� �ʿ� 
	int register_val_err = 0; //���� ����
	int register_val_check = 1; //���� ���� �Ǵ��� ���� ����

	int register_mul = 0;//���


	int num_digit = 0; //���װ� �ڸ� �� �Ǵ��� ���� ��
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
		num_digit++; // ���� ���� �� �̹Ƿ� ���� �ڸ����� +1 �Ǿ����

	}

	register_val2 = register_val_tmp;
	//printf("%d\n",num_digit); //�ڸ� �� Ȯ��

	for (int i = 0; i < num_digit - 2; i++) //4band 
	{
		register_mul++; // �츮�� �Է��� ������ ���� �𸣴� ��� �̷��� �ϸ� ������ ������ �˰� ������ min���� ���� ��� ����Ͽ� +1�Ѵ�.

		if (register_val2 % 10 != 0)//0�� �ƴϸ� ���������� ����Ǿ��ٰ� �Ǵ�
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

	//���� ���� �Է�
	//������ �Է��̶� ���� ������ �Ҽ����� ���� ����(���� ����) -> �׷��� ���ܰ� �߻��Ҽ� ����

	if (register_val_check == 0 || (register_val2 <register_val))
	{
		init_err2(4, register_val_err, register_band);
	}
	else // ���� ����, ���� ��� ������ ���� ���� ȸ�� ����
	{
		register_band[3] = 'g';
	}
	//��� �Է�
	init_mul2(4, register_mul, register_band);

	//�����ڵ� ����
	init_color2(4, register_val, register_mul, register_band);

	printf("4�� ������ ���� �ڵ�:");
	for (int i = 0; i < 4; i++)
	{
		printf("%c ", register_band[i]);
	}
	printf("\n");

	//5band����
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

	//���� ���� �Է�
	//������ �Է��̶� ���� ������ �Ҽ����� ���� ����(���� ����) -> �׷��� ���ܰ� �߻��Ҽ� ����
	if (register_val_check == 0 || (register_val2 <register_val))
	{
		init_err2(5, register_val_err, register_band);
	}
	else // ���� ����, ���� ��� ������ ���� ���� ȸ�� ����
	{
		register_band[4] = 'g';
	}

	//��� �Է�
	init_mul2(5, register_mul, register_band);

	//�����ڵ� ����
	init_color2(5, register_val, register_mul, register_band);


	printf("5�� ������ ���� �ڵ�:");
	for (int i = 0; i < 5; i++)
	{
		printf("%c ", register_band[i]);
	}
	printf("\n");
}

void init_err2(int band, int register_val_err, char register_band[5])
{
	if (register_val_err < 0) //-�� ������ ������ �� ����� ����� �����ϱ� ���ؼ�
	{
		register_val_err = -register_val_err;
	}

	if (band == 4) //4�� 
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
			register_band[3] = 'G';//�ݻ�
		}
		else if (register_val_err <= 10)
		{
			register_band[3] = 's';
		}
		else
		{
			printf("���Ǵ� ���� ������ �ƴմϴ�.\n");
		}
	}
	else // 5��
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
			register_band[4] = 'G';//�ݻ�
		}
		else if (register_val_err <= 10)
		{
			register_band[4] = 's';
		}
		else
		{
			printf("���Ǵ� ���� ������ �ƴմϴ�.\n");
		}
	}
}

void init_mul2(int band, int register_mul, char register_band[5])
{
	if (band == 4){//4��
		switch (register_mul) //��� ���� �Է�
		{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
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
			register_band[2] = 'n'; //�ʷ�
			break;
		case 6:
			register_band[2] = 'b';
			break;
		case 7:
			register_band[2] = 'v';
			break;
		case 8:
			register_band[2] = 'g'; //ȸ��
			break;
		case 9:
			register_band[2] = 'w';
			break;
		default:
			printf("������ ���װ��� �Է����ּ���.");
			break;
		}
		//printf("%d\n",register_mul); ���Ȯ��
	}
	else//5��
	{
		switch (register_mul) //��� ���� �Է�
		{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
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
			register_band[3] = 'n';//�ʷ�
			break;
		case 6:
			register_band[3] = 'b';
			break;
		case 7:
			register_band[3] = 'v';
			break;
		case 8:
			register_band[3] = 'g';//ȸ��
			break;
		case 9:
			register_band[3] = 'w';
			break;
		default:
			printf("������ ���װ��� �Է����ּ���.");
			break;
		}
		//printf("%d\n",register_mul); ���Ȯ��
	}
}

void init_color2(int band, int register_val, int register_mul, char register_band[5])
{
	int num = 0;
	num = (int)pow(10.0,register_mul);
	//printf("%d \n", num);
	register_val = register_val / num;
	//printf("%d \n", register_val);
	if (band == 4){//4��
		switch (register_val % 10)
		{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
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
			register_band[1] = 'n'; //�ʷϻ�
			break;
		case 6:
			register_band[1] = 'b';
			break;
		case 7:
			register_band[1] = 'v';
			break;
		case 8:
			register_band[1] = 'g';//ȸ��
			break;
		case 9:
			register_band[1] = 'w';
			break;
		default:
			printf("���� ������ ������ �ƴմϴ�.");
			break;
		}
		//printf("%d \n",register_val);
		register_val = register_val / 10;
		switch (register_val % 10)//
		{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
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
			register_band[0] = 'n';//�ʷϻ�
			break;
		case 6:
			register_band[0] = 'b';
			break;
		case 7:
			register_band[0] = 'v';
			break;
		case 8:
			register_band[0] = 'g';//ȸ��
			break;
		case 9:
			register_band[0] = 'w';
			break;
		default:
			printf("���� ������ ������ �ƴմϴ�.");
			break;
		}
	}
	else //5��
	{
		//printf("%d \n", register_val);
		switch (register_val % 10)//
		{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
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
			register_band[2] = 'n';//�ʷ�
			break;
		case 6:
			register_band[2] = 'b';
			break;
		case 7:
			register_band[2] = 'v';
			break;
		case 8:
			register_band[2] = 'g';// ȸ��
			break;
		case 9:
			register_band[2] = 'w';
			break;
		default:
			printf("���� ������ ������ �ƴմϴ�.");
			break;
		}

		register_val = register_val / 10;
		switch (register_val % 10)//
		{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
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
			register_band[1] = 'n';//�ʷ�
			break;
		case 6:
			register_band[1] = 'b';
			break;
		case 7:
			register_band[1] = 'v';
			break;
		case 8:
			register_band[1] = 'g'; //ȸ��
			break;
		case 9:
			register_band[1] = 'w';
			break;
		default:
			printf("���� ������ ������ �ƴմϴ�.");
			break;
		}

		register_val = register_val / 10;
		switch (register_val % 10)//
		{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
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
			register_band[0] = 'n';//�ʷ�
			break;
		case 6:
			register_band[0] = 'b';
			break;
		case 7:
			register_band[0] = 'v';
			break;
		case 8:
			register_band[0] = 'g';//ȸ��
			break;
		case 9:
			register_band[0] = 'w';
			break;
		default:
			printf("���� ������ ������ �ƴմϴ�.");
			break;
		}
	}
}