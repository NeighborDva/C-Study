#include <stdio.h>
#include <math.h>

int main(void)
{
	char register_4band[4];
	char register_5band[5];


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

		if (register_val % 10 != 0)
			register_val_check = 0;

		register_val = register_val / 10;
	}

	


	register_val_err = register_val_tmp - register_val*pow(10.0, register_mul);
	//printf("%d\n", register_val_err);
	register_val_err = (register_val_err /( register_val*pow(10.0, register_mul))) * 100;

	//printf("%d",register_val_err);

	//���� ���� �Է�
	//������ �Է��̶� ���� ������ �Ҽ����� ���� ����(���� ����) -> �׷��� ���ܰ� �߻��Ҽ� ����
	if(register_val_err<=1)
		register_4band[3] = 'b';
	else if (register_val_err<=2)
	{
		register_4band[3] = 'r';
	}
	else if (register_val_err <= 3)
	{
		register_4band[3] = 'o';
	}
	else if (register_val_err <= 4)
	{
		register_4band[3] = 'y';
	}
	else if (register_val_err <= 5)
	{
		register_4band[3] = 'G';
	}
	else if (register_val_err <= 10)
	{
		register_4band[3] = 's';
	}
	else
	{
		printf("���Ǵ� ���� ������ �ƴմϴ�.\n");
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
	

	switch (register_mul) //��� ���� �Է�
	{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
	case 0:
		register_4band[2] = 'B';
		break;
	case 1:
		register_4band[2] = 'b';
		break;
	case 2:
		register_4band[2] = 'r';
		break;
	case 3:
		register_4band[2] = 'o';
		break;
	case 4:
		register_4band[2] = 'y';
		break;
	case 5:
		register_4band[2] = 'g';
		break;
	case 6:
		register_4band[2] = 'b';
		break;
	case 7:
		register_4band[2] = 'v';
		break;
	case 8:
		register_4band[2] = 'g';
		break;
	case 9:
		register_4band[2] = 'w';
		break;
	default:
		printf("������ ���װ��� �Է����ּ���.");
		break;
	}
	//printf("%d\n",register_mul); ���Ȯ��


	switch (register_val % 10)//
	{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
	case 0:
		register_4band[1] = 'B';
		break;
	case 1:
		register_4band[1] = 'b';
		break;
	case 2:
		register_4band[1] = 'r';
		break;
	case 3:
		register_4band[1] = 'o';
		break;
	case 4:
		register_4band[1] = 'y';
		break;
	case 5:
		register_4band[1] = 'g';
		break;
	case 6:
		register_4band[1] = 'b';
		break;
	case 7:
		register_4band[1] = 'v';
		break;
	case 8:
		register_4band[1] = 'g';
		break;
	case 9:
		register_4band[1] = 'w';
		break;
	default:
		printf("���� ������ ������ �ƴմϴ�.");
		break;
	}

	register_val = register_val / 10;
	switch (register_val % 10)//
	{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
	case 0:
		register_4band[0] = 'B';
		break;
	case 1:
		register_4band[0] = 'b';
		break;
	case 2:
		register_4band[0] = 'r';
		break;
	case 3:
		register_4band[0] = 'o';
		break;
	case 4:
		register_4band[0] = 'y';
		break;
	case 5:
		register_4band[0] = 'g';
		break;
	case 6:
		register_4band[0] = 'b';
		break;
	case 7:
		register_4band[0] = 'v';
		break;
	case 8:
		register_4band[0] = 'g';
		break;
	case 9:
		register_4band[0] = 'w';
		break;
	default:
		printf("���� ������ ������ �ƴմϴ�.");
		break;
	}

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
	if (register_val_err <= 1)
		register_5band[4] = 'b';
	else if (register_val_err <= 2)
	{
		register_5band[4] = 'r';
	}
	else if (register_val_err <= 3)
	{
		register_5band[4] = 'o';
	}
	else if (register_val_err <= 4)
	{
		register_5band[4] = 'y';
	}
	else if (register_val_err <= 5)
	{
		register_5band[4] = 'G';
	}
	else if (register_val_err <= 10)
	{
		register_5band[4] = 's';
	}
	else
	{
		printf("���Ǵ� ���� ������ �ƴմϴ�.\n");
	}
	

	switch (register_mul) //��� ���� �Է�
	{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
	case 0:
		register_5band[3] = 'B';
		break;
	case 1:
		register_5band[3] = 'b';
		break;
	case 2:
		register_5band[3] = 'r';
		break;
	case 3:
		register_5band[3] = 'o';
		break;
	case 4:
		register_5band[3] = 'y';
		break;
	case 5:
		register_5band[3] = 'g';
		break;
	case 6:
		register_5band[3] = 'b';
		break;
	case 7:
		register_5band[3] = 'v';
		break;
	case 8:
		register_5band[3] = 'g';
		break;
	case 9:
		register_5band[3] = 'w';
		break;
	default:
		printf("������ ���װ��� �Է����ּ���.");
		break;
	}
	//printf("%d\n",register_mul); ���Ȯ��


	switch (register_val % 10)//
	{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
	case 0:
		register_5band[2] = 'B';
		break;
	case 1:
		register_5band[2] = 'b';
		break;
	case 2:
		register_5band[2] = 'r';
		break;
	case 3:
		register_5band[2] = 'o';
		break;
	case 4:
		register_5band[2] = 'y';
		break;
	case 5:
		register_5band[2] = 'g';
		break;
	case 6:
		register_5band[2] = 'b';
		break;
	case 7:
		register_5band[2] = 'v';
		break;
	case 8:
		register_5band[2] = 'g';
		break;
	case 9:
		register_5band[2] = 'w';
		break;
	default:
		printf("���� ������ ������ �ƴմϴ�.");
		break;
	}

	register_val = register_val / 10;
	switch (register_val % 10)//
	{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
	case 0:
		register_5band[1] = 'B';
		break;
	case 1:
		register_5band[1] = 'b';
		break;
	case 2:
		register_5band[1] = 'r';
		break;
	case 3:
		register_5band[1] = 'o';
		break;
	case 4:
		register_5band[1] = 'y';
		break;
	case 5:
		register_5band[1] = 'g';
		break;
	case 6:
		register_5band[1] = 'b';
		break;
	case 7:
		register_5band[1] = 'v';
		break;
	case 8:
		register_5band[1] = 'g';
		break;
	case 9:
		register_5band[1] = 'w';
		break;
	default:
		printf("���� ������ ������ �ƴմϴ�.");
		break;
	}

	register_val = register_val / 10;
	switch (register_val % 10)//
	{//������ �Է��̶� ����� �Ҽ����� ��, ���� ����
	case 0:
		register_5band[0] = 'B';
		break;
	case 1:
		register_5band[0] = 'b';
		break;
	case 2:
		register_5band[0] = 'r';
		break;
	case 3:
		register_5band[0] = 'o';
		break;
	case 4:
		register_5band[0] = 'y';
		break;
	case 5:
		register_5band[0] = 'g';
		break;
	case 6:
		register_5band[0] = 'b';
		break;
	case 7:
		register_5band[0] = 'v';
		break;
	case 8:
		register_5band[0] = 'g';
		break;
	case 9:
		register_5band[0] = 'w';
		break;
	default:
		printf("���� ������ ������ �ƴմϴ�.");
		break;
	}


	printf("4�� ������ ���� �ڵ�:");
	for (int i = 0; i < 4; i++)
	{
		printf("%c ",register_4band[i]);
	}
	printf("\n");

	printf("5�� ������ ���� �ڵ�:");
	for (int i = 0; i < 5; i++)
	{
		printf("%c ", register_5band[i]);
	}
	printf("\n");

}

