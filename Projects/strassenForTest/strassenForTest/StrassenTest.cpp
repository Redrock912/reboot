#include <Windows.h>
#include<stdio.h>
#include <stdlib.h>
#include<time.h>
#include <iostream>
#define MAX_SIZE 10

class matrix
{
private:
	int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
	int n;
	long int start_time, end_time;
	void strassen(int n, int a1[][MAX_SIZE], int b1[][MAX_SIZE], int c1[][MAX_SIZE]);

public:
	void init();
	const void print(char *msg);
	const void print();
	void multiplication();
	void strassen_start();
};

void matrix::strassen_start()
{
	double start, stop, timer;
	start = clock();
	//수행시간을 구하기 위해 스타트에 시작 시간을 넣는다
	int i, j;
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		result[i][j] = 0;
	strassen(n, a, b, result);
	stop = clock();
	timer = ((double)(stop - start)) / CLK_TCK;
	printf("timer : \n", timer);
	//쉬트라센 함수를 호출후 계산을 마치고 돌아온 시간을 기록하여 수행시간을 계산하다.
}

void matrix::strassen(int n, int a1[][MAX_SIZE], int b1[][MAX_SIZE], int c1[][MAX_SIZE])
{
	int i, j;
	int m1[MAX_SIZE][MAX_SIZE], m2[MAX_SIZE][MAX_SIZE],
		m3[MAX_SIZE][MAX_SIZE], m4[MAX_SIZE][MAX_SIZE],
		m5[MAX_SIZE][MAX_SIZE], m6[MAX_SIZE][MAX_SIZE],
		m7[MAX_SIZE][MAX_SIZE];

	int temp1[MAX_SIZE][MAX_SIZE], temp2[MAX_SIZE][MAX_SIZE];
	int sm1, sm2, sm3, sm4, sm5, sm6, sm7;
	if (n <= 2)
	{
		sm1 = (a1[0][0] + a1[1][1])*(b1[0][0] + b1[1][1]);
		sm2 = (a1[1][0] + a1[1][1])*b1[0][0];
		sm3 = a1[0][0] * (b1[0][1] - b1[1][1]);
		sm4 = a1[1][1] * (b1[1][0] - b1[0][0]);
		sm5 = (a1[0][0] + a1[0][1])*b1[1][1];
		sm6 = (a1[1][0] - a1[0][0])*(b1[0][0] + b1[0][1]);
		sm7 = (a1[0][1] - a1[1][1])*(b1[1][0] + b1[1][1]);
		c1[0][0] = sm1 + sm4 - sm5 + sm7;
		c1[0][1] = sm3 + sm5;
		c1[1][0] = sm2 + sm4;
		c1[1][1] = sm1 + sm3 - sm2 + sm6;

	}
	else
	{
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp1[i][j] = a1[i][j] + a1[i + n / 2][j + n / 2];
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp2[i][j] = b1[i][j] + b1[i + n / 2][j + n / 2];
		strassen(n / 2, temp1, temp2, m1);
		/////////////////////
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp1[i][j] = a1[i + n / 2][j] + a1[i + n / 2][j + n / 2];
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp2[i][j] = b1[i][j];
		strassen(n / 2, temp1, temp2, m2);
		//////////////////////
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp1[i][j] = a1[i][j];
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp2[i][j] = b1[i][j + n / 2] - b1[i + n / 2][j + n / 2];
		strassen(n / 2, temp1, temp2, m3);
		//////////////////////
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp1[i][j] = a1[i + n / 2][j + n / 2];
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp2[i][j] = b1[i + n / 2][j] - b1[i][j];
		strassen(n / 2, temp1, temp2, m4);
		///////////////////////
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp1[i][j] = a1[i][j] + a1[i][j + n / 2];
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp2[i][j] = b1[i + n / 2][j + n / 2];
		strassen(n / 2, temp1, temp2, m5);
		/////////////////////
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp1[i][j] = a1[i + n / 2][j] - a1[i][j];
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp2[i][j] = b1[i][j] + b1[i][j + n / 2];
		strassen(n / 2, temp1, temp2, m6);
		///////////////////////////
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp1[i][j] = a1[i][j + n / 2] - a1[i + n / 2][j + n / 2];
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			temp2[i][j] = b1[i + n / 2][j] + b1[i + n / 2][j + n / 2];
		strassen(n / 2, temp1, temp2, m7);
		////////////////////////////

		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			c1[i][j] = m1[i][j] + m4[i][j] - m5[i][j] + m7[i][j];
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			c1[i][j + n / 2] = m3[i][j] + m5[i][j];

		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			c1[i + n / 2][j] = m2[i][j] + m4[i][j];
		for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
			c1[i + n / 2][j + n / 2] = m1[i][j] + m3[i][j] - m2[i][j] + m6[i][j];

	}
}

void matrix::init()
{

	int i, j;
	do{
		printf("행렬 크기를 결정 (2의 제곱수)\n");
		scanf("%d", &n);
		if (n > MAX_SIZE) continue;
		i = n;
		j = 0;
		do{
			i = i / 2;
		} while (i != 1);
		if (j == 0)break;
	} while (1);
	srand((unsigned)time(NULL));

	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
	{
		a[i][j] = rand() % 10;
		b[i][j] = rand() % 10;
	}
}

void matrix::multiplication()
{
	double start, stop, timer;
	start = clock();
	int i, j, k;
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++)
		result[i][j] = 0;
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++){
		result[i][j] = 0;
		for (k = 0; k < n; k++)
			result[i][j] = result[i][j] + (a[i][k] * b[k][j]);
	}
	stop = clock();
	timer = ((double)(stop - start)) / CLK_TCK;
	printf("timer : \n", timer);

}

const void matrix::print()
{
	int i, j;
	printf(" 2개의 n*n 행렬\n");
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++){
		printf(" %d", a[i][j]);
	}
	for (j = 0; j < n; j++)
	{
		printf(" %d", b[i][j]);
	}
	printf(" \n");
}

const void matrix::print(char *msg)
{
	int i, j;
	printf(" %s \n", msg);
	for (i = 0; i < n; i++)
	for (j = 0; j < n; j++){
		printf(" %d", result[i][j]);
	}

	printf(" \n");
}
void main()
{
	matrix m;
	m.init();
	m.print();
	m.multiplication();
	m.print("표준 알고리즘 ");
	m.strassen_start();
	m.print("쉬트라센 알고리즘");
}