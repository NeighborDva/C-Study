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

	int register_mul = 0;//���
	

	int num_digit = 0;

	printf("���� ���� �Է��Ͻÿ� �Է�: ");
	scanf("%d", &register_val);

	register_val_tmp = register_val;
	while (register_val != 0)
	{
		num_digit++;
		register_val = register_val / 10;
	}
	register_val = register_val_tmp;
	//printf("%d\n",num_digit); //�ڸ� �� Ȯ��

	for (int i = 0; i < num_digit-2; i++) //4band 
	{
		register_mul++;

		if (register_val % 10 != 0)//0�� �ƴϸ� ���������� ����Ǿ��ٰ� �Ǵ�
			register_val_check = 0;

		register_val = register_val / 10;
	}

	


	register_val_err = register_val_tmp - register_val*pow(10.0, register_mul);
	//printf("%d\n", register_val_err);
	register_val_err = (register_val_err /( register_val*pow(10.0, register_mul))) * 100;

	//printf("%d",register_val_err);

	//���� ���� �Է�
	//������ �Է��̶� ���� ������ �Ҽ����� ���� ����(���� ����) -> �׷��� ���ܰ� �߻��Ҽ� ����
	if (register_val_check == 0)
	{
		init_err(4, register_val_err, register_band);
	}
	else // ���� ����, ���� ��� ������ ���� ���� ȸ�� ����
	{
		register_band[3] = 'g';
	}
	/*
	switch (register_val_err) //���� ���� �Է�
	{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
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
		printf("������ ���װ��� �Է����ּ���.");
		break;
	}
	*/
	
	//��� �Է�
	init_mul(4,register_mul,register_band);
	
	//�����ڵ� ����
	init_color(4,register_val,register_band);

	printf("4�� ������ ���� �ڵ�:");
	for (int i = 0; i < 4; i++)
	{
		printf("%c ", register_band[i]);
	}
	printf("\n");

	//5band����
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

	//���� ���� �Է�
	//������ �Է��̶� ���� ������ �Ҽ����� ���� ����(���� ����) -> �׷��� ���ܰ� �߻��Ҽ� ����
	if (register_val_check == 0)
	{
		init_err(5, register_val_err, register_band);
	}
	else // ���� ����, ���� ��� ������ ���� ���� ȸ�� ����
	{
		register_band[4] = 'g';
	}
	
	//��� �Է�
	init_mul(5,register_mul,register_band);

	//�����ڵ� ����
	init_color(5, register_val, register_band);


	printf("5�� ������ ���� �ڵ�:");
	for (int i = 0; i < 5; i++)
	{
		printf("%c ", register_band[i]);
	}
	printf("\n");

}


void init_err(int band, int register_val_err, char register_band[5])
{
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

void init_mul(int band, int register_mul, char register_band[5])
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

void init_color(int band, int register_val, char register_band[5])
{
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