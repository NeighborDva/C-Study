#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define M 100

typedef struct{// 큐 구조체 선언
	char *arr;
	int read, write; //// 읽기, 쓰기 포인터 선언
}Ring_buffer;

void init_r_buf(Ring_buffer *r)
{
	r->arr = (char*)calloc(N, sizeof(char)); //링버퍼내 배열 동적할당
	r->read = r->write = 0; // 읽기, 쓰기 포인터 초기화
	printf("\n링 버퍼 생성. read : %d, write : %d\n", r->read, r->write);
}

void printRingbufferData(Ring_buffer *r) {
	printf("\n< Ring buffer r:%d w:%d > : ", r->read, r->write);
	//if (q->front == q->rear) return; //큐 공백판단
	int i;
	
	for (i = 0; i < N; i++)
		printf("arr[%d] = %c ", i,r->arr[i]);
	printf("\n");
}

void enringbuffer(Ring_buffer *r, char data)
{
	int i,j,k; //반복문(i,j) 배열 인자(k)로 활용
	int result; //strcmp 함수 실행결과 담는 변수
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
		printf("문자열:%s \n",check);
		result = strcmp("aMAP", check);
		printf("result = %d \n",result);
		if (result == 0)// aMAP문자열이 링버퍼내에 존재
		{
			printf("정답을 찾았습니다.!! \n");
			k = i;
			for (j = 0; j < 4; j++) //검색하고자 하는 문자열 만큼 반복하여 검색 되면 찾고자 하는 문자열의 글자수 만큼 반복
			{
				r->arr[k] = ' '; //char의 calloc은 ' ' 초기화 되어 이렇게 작성
				k = (k + 1) % N;
			}
			r->write = i;
			break;
		}
	}



}

int main(void)
{
	Ring_buffer r_buf; // 링 버퍼 생성
	char data; //입력받을 데이터 변수
	init_r_buf(&r_buf); // 링버퍼 초기화
	int i; // 반복문 변수i

	printRingbufferData(&r_buf);

	for ( i = 0; i < M; i++)
	{
		printf("링버퍼에 입력할 데이터를 입력하시요. 입력: ");
		scanf("%c",&data);
		while (getchar() != '\n');
		enringbuffer(&r_buf, data);
		printRingbufferData(&r_buf);
	}

	free(r_buf.arr);
	return 0;
}
/* 링버퍼(원형큐) 사용 x코드 -> 순환저장까지만 확인
int i; //반복문 변수
char *arr = (char*)calloc(N, sizeof(char)); //calloc은 malloc과 다르게 0(int)으로 초기화

//char는 ' ' 공백으로 초기화 되어 있음
for (i = 0; i < N; i++)
printf("arr[%d]=%c ", i, arr[i]);
printf("\n");


for (i = 0; i < M; i++){
printf("입력:");
scanf("%c", &arr[i%N]);
while (getchar() != '\n');
//링버퍼 순환 저장 확인
printf("arr[%d] = %c\n",i%5,arr[i%5]);
}

free(arr);
*/