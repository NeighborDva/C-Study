#include <stdio.h>
#include <math.h>

int init_num(int i, char color[], double color_value[]); //����
int init_mul(int i, char color[], double color_value[]); //���
int init_err(int i, char color[], double color_value[]); // ����

int main(void)
{
	int band_type = 0;
	char color[5];
	double color_value[5];
	double resistance_max = 0.0;
	double resistance_min = 0.0;

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
		resistance_min = (color_value[0] * 10 + color_value[1])*color_value[2] * (1 - color_value[3]);
	}
	else
	{
		resistance_max = (color_value[0] * 100 + color_value[1] * 10 + color_value[2])*color_value[3] * (1 + color_value[4]);
		resistance_min = (color_value[0] * 100 + color_value[1] * 10 + color_value[2])*color_value[3] * (1 - color_value[4]);
	}

	printf("������ �ִ밪�� %lf �̰� �ּҰ��� %lf �Դϴ�.\n", resistance_max, resistance_min); //�� ����

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