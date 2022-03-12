#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define M 100

typedef struct{// ť ����ü ����
	char *arr;
	int read, write; //// �б�, ���� ������ ����
}Ring_buffer;

void init_r_buf(Ring_buffer *r)
{
	r->arr = (char*)calloc(N, sizeof(char)); //�����۳� �迭 �����Ҵ�
	r->read = r->write = 0; // �б�, ���� ������ �ʱ�ȭ
	printf("\n�� ���� ����. read : %d, write : %d\n", r->read, r->write);
}

void printRingbufferData(Ring_buffer *r) {
	printf("\n< Ring buffer r:%d w:%d > : ", r->read, r->write);
	//if (q->front == q->rear) return; //ť �����Ǵ�
	int i;
	
	for (i = 0; i < N; i++)
		printf("arr[%d] = %c ", i,r->arr[i]);
	printf("\n");
}

void enringbuffer(Ring_buffer *r, char data)
{
	int i,j,k; //�ݺ���(i,j) �迭 ����(k)�� Ȱ��
	int result; //strcmp �Լ� ������ ��� ����
	char *check = (char*)calloc(N, sizeof(char));
	//char check[5] = { ' ', };

	printf("write: %d \n",r->write);
	r->arr[r->write] = data;
	r->write = (r->write + 1) % N;

	for (i = 0; i < N; i++)
	{
		k = i;
		for (j = 0; j < N-1; j++)
		{
			check[j] = r->arr[k];
			k = (k + 1) % N;
		}
		check[4] = '\0';
		printf("���ڿ�:%s \n",check);
		result = strcmp("aMAP", check);
		printf("result = %d \n",result);
		if (result == 0)// aMAP���ڿ��� �����۳��� ����
		{
			printf("������ ã�ҽ��ϴ�.!! \n");
			k = i;
			for (j = 0; j < 4; j++) //�˻��ϰ��� �ϴ� ���ڿ� ��ŭ �ݺ��Ͽ� �˻� �Ǹ� ã���� �ϴ� ���ڿ��� ���ڼ� ��ŭ �ݺ�
			{
				r->arr[k] = ' '; //char�� calloc�� ' ' �ʱ�ȭ �Ǿ� �̷��� �ۼ�
				k = (k + 1) % N;
			}
			r->write = i;
			break;
		}
	}



}

int main(void)
{
	Ring_buffer r_buf; // �� ���� ����
	char data; //�Է¹��� ������ ����
	init_r_buf(&r_buf); // ������ �ʱ�ȭ
	int i; // �ݺ��� ����i

	printRingbufferData(&r_buf);

	for ( i = 0; i < M; i++)
	{
		printf("�����ۿ� �Է��� �����͸� �Է��Ͻÿ�. �Է�: ");
		scanf("%c",&data);
		while (getchar() != '\n');
		enringbuffer(&r_buf, data);
		printRingbufferData(&r_buf);
	}

	free(r_buf.arr);
	return 0;
}
/* ������(����ť) ��� x�ڵ� -> ��ȯ��������� Ȯ��
int i; //�ݺ��� ����
char *arr = (char*)calloc(N, sizeof(char)); //calloc�� malloc�� �ٸ��� 0(int)���� �ʱ�ȭ

//char�� ' ' �������� �ʱ�ȭ �Ǿ� ����
for (i = 0; i < N; i++)
printf("arr[%d]=%c ", i, arr[i]);
printf("\n");


for (i = 0; i < M; i++){
printf("�Է�:");
scanf("%c", &arr[i%N]);
while (getchar() != '\n');
//������ ��ȯ ���� Ȯ��
printf("arr[%d] = %c\n",i%5,arr[i%5]);
}

free(arr);
*/