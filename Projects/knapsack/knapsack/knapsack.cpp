#include<iostream>
#include<cstring>
#define MAX_ITEMS 20
#define MAX_CAPACITY 100000
#define DEFAULT 0

using namespace std;

int cache[2][MAX_CAPACITY];


int bigger(int v1, int v2){ return (v1 > v2) ? v1 : v2; }

//cache의 DEFAULT를 0으로 설정해주어야 구현에 분기가 줄어든다.
//sliding window를 사용하기 위해, 행의 index에 %2 연산을 해준다.
int mkCACHE(int item, int cap , Material a){
	int i, j;
	for (i = 0; i <= item; i++){
		for (j = 0; j <= cap; j++){
			//가방의 무게제한보다 i번째 짐의 무게가 더 크다면 어차피 i번짐은 챙기지 못하므로,
			//cache[i][j]는 i번 짐을 챙기지 않았을 때의 최대 가치합과 같다.

			if (j < a.weight[i]){ cache[i % 2][j] = cache[0 + 1 - i % 2][j]; }
			//그 외의 경우,
			//cache[i][j]는 i번 짐을 챙겼을 때와 아닐 때 중, 더 큰 최대가치의 합과 같다.
			else{ cache[i % 2][j] = bigger(cache[0 + 1 - i % 2][j], cache[0 + 1 - i % 2][j - weight[i]] + value[i]); }
		}
	}
	return cache[ind % 2][cap];
}

//i > 0 이고 w > 0일 때, 전체 무게가 w가 넘지 않도록 i번째까지의 항목 중에서 얻어진 최고의 이익(optimal profit)을 P[i][w]라고 하면, 다음의 재귀 관계식을 얻을 수 있다.
//
//
//P[i - 1][w]는 i번째 항목을 포함시키지 않는 경우의 최고 이익이다.
//pi + P[i - 1][w - wi]는 i번째 항목을 포함시키는 경우의 최고 이익이다.
//위의 재귀 관계식이 최적화 원칙을 만족하는 지는 쉽게 알 수 있다.
//그러면 어떻게 P[n][W]값을 구할 수 있을까 ?
//다음과 같은 2차원 배열을 만든 후, 각 항을 계산하여 채워 넣으면 된다.
//int P[0..n][0..W]
//여기서 P[0][w] = 0, P[i][0] = 0으로 놓으면 되므로, 계산해야 할 항목의 수는 nW  (nW)이다.

int knapsack(int a, int b)
{

}

int main(void){
	int T, item, capacity;
	cin >> T;
	int* p[2];
	p[0] = new int[T];
	p[1] = new int[T];
	for (int i = 0; i < T; i++)
	{
		int weight;
		int value;
		cin >> weight;
		cin >> value;

		p[0][i] = weight; // 이상하지만 앞을 바꾸는걸로
		p[1][i] = value;
	}
	
	cout << endl << "ITEM / CAPACITY" << endl;
	cin >> item;
	cin >> capacity;

	int ** A;

	int *A = new int[item];

	for (int i = 0; i < item; i++)
	{
		A[i] = new int[capacity];
	}
	A[item][capacity] = { 0 };


	int Temp = 0;

	for (int i = 0; i < item; i++)
	{
		if (p[0][i] <= capacity)
		{
			A[i][p[0][i]] = 1;
		}
	}

	for (int )

	while (T--){
		for (int i = 0; i < 2; i++){ memset(cache[i], DEFAULT, sizeof(int)*MAX_CAPACITY); }
		cin >> item >> capacity;
		for (int i = 0; i < item; i++){ cin >> weight[i] >> value[i]; }
		cout << mkCACHE(item - 1, capacity) << endl;
	}
	return 0;
}