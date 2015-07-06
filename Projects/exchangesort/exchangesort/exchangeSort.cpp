#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 1000
#define LOW 0
void exSort(int n, int a[MAX])
{
	int i, j,temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

/*
모든 경우 분석(Every-case analysis)
복잡도는 입력 크기에만 종속(dependent)적임
입력 값과는 무관(independent)하게 복잡도는 항상 일정
예: 평균을 구하라.

최악의 경우 분석(Worst-case analysis)
복잡도는 입력 크기와 입력 값 모두에 종속
단위연산이 수행되는 횟수가 최대(최악)인 경우 선택



문제: 크기가 n인 배열 S의 모든 수를 더하라.
입력: 양수 n, 배열 S[1..n]
출력: 배열 S에 있는 모든 수의 합
알고리즘:
number sum (int n, const number S[])
{
index i;
number result;

result = 0;
for (i = 1; i <= n; i++)
result = result + S[i];
return result;
}

단위연산: 덧셈
입력크기: 배열의 크기 n
모든 경우 분석:
배열 내용에 상관없이 for-루프가 n번 반복된다.
각 루프마다 덧셈이 1회 수행된다.
따라서, n에 대해서 덧셈이 수행되는 총 횟수는 T(n) = n 이다.

단위연산: 지정문 (for-루프의 첨자 지정문 포함)
입력크기: 배열의 크기 n
모든 경우 분석:
배열 내용에 상관없이 for-루프가 n번 반복된다.
따라서, 지정문이T(n) = n + n + 1번 수행된다.









void exchangesort (int n, keytype S[])
{
index i, j;

for (i = 1; i <= n-1; i++)
for (j = i+1; j <= n; j++)
if (S[j] < S[i])
exchange S[i] and S[j];
}

단위연산: 조건문 (S[j]와 S[i]의 비교)
입력크기: 정렬할 항목의 수 n
모든 경우 분석:
j-루프가 수행될 때마다 조건문을 1번씩 수행
조건문의 총 수행횟수
i = 1	      :  j-루프  n – 1 번 수행
i = 2	      :  j-루프  n – 2 번 수행
i = 3	      :  j-루프  n – 3 번 수행
i = n – 1         :  j-루프  1 번 수행
따라서

T(n)=(n-1)+(n-2)+....+1 = (n-1)*n/2

단위연산: 교환하는 연산  (exchange S[j] and S[i])
입력크기: 정렬할 항목의 수 n
최악의 경우 분석:
조건문의 결과에 따라서 교환 연산의 수행여부가 결정된다.
최악의 경우	= 조건문이 항상 참(true)이 되는 경우			      	= 입력 배열이 거꾸로 정렬되어 있는 경우

T(n)=(n-1)*n/2


단위연산: 배열의 아이템과 키 x와 비교 연산 (S[location] != x)
입력크기: 배열 안에 있는 아이템의 수 n
최악의 경우 분석:
x가 배열의 마지막 아이템이거나, x가 배열에 없는 경우, 단위 연산이 n번 수행된다.
따라서,

W(n)=n

단위연산: 배열의 아이템과 키 x와 비교 연산 (S[location] != x)
입력크기: 배열 안에 있는 아이템의 수 n
가정:배열의 아이템이 모두 다르다.
평균의 경우 분석(경우 1): x가 배열 S안에 있는 경우만 고려
에 대해서 x가 배열의 k번째 있을 확률 = 1/n
x가 배열의 k번째 있다면, x를 찾기 위해서 수행하는 단위연산의 횟수 = k
따라서,

A(n)=sigma(k=1->n)(k*1/n)=(1/n)*sigma(k=1->n)k=(1/n)*n(n+1)/2=(n+1)/2






정의: 점근적 상한(Asymptotic Upper Bound)
주어진 복잡도 함수 f(n)에 대해서 g(n)이 (f(n))에 포함되면 다음을 만족한다.
n >= N인 모든 정수 n에 대해서 g(n) <= c * f(n)이 성립하는 실수 c > 0와 음이 아닌 정수 N이 존재한다.

g(n) 이 O(f(n))에 포함되는것 읽는 방법:g(n)은  f(n)의 Big O이다.



Consider a function f(n) that, for all n=bk for all k Z+,satisfies the recurrence relation: (n=bk 일 때, 다음 점화 관계가 성립하면)
f(n) = af(n/b) + cnd
with a≥1, integer b>1, real c>0, d≥0.  Then:

f(n) 포함 O(n^d) if a<b^d
f(n) 포함 O(n^d*logn) if a=b^d
f(n) 포함 O(n^log아래b위a if a>b^d

example)
Complexity of fast multiplication was:		T(n)=3T(n/2)+(n)
Thus, a=3, b=2, d=1.  So a > bd, so case 3 of the master theorem applies, so:

T(n)=O(n^log아래b위a)=O(n^log 2 3)

which is O(n1.58…).

예제: Merge Sort합병 정렬의 복잡도는 얼마인가(비교 수를 추정하라)?
이진 탐색의 점화 관계: T(n) = 2T(n/2)+cn  (n 이 짝수라 가정)
매스터 정리로 보면, a = 2, b = 2, d = 1로서,a = 2 = bd인 두 번째 경우에 해당한다.
결국, 다음과 같은 과정에 의해 O(nlogn)이 된다.

*/
int location(int low,int high, int s[], int x)
{
	int mid;
	if (low > high)
		return -1;
	else
	{
		mid = (low + high) / 2;
		if (x == s[mid])
		{
			return mid;
		}
		else if (x < s[mid])
			return location(low, mid - 1, s, x);
		else if (x > s[mid])
			return location(mid + 1, high, s, x);
	}
}
//int binsearch(int* a, int x, int high)
//{
//	int location = 0;
//	int mid;
//	int low = 0;
//	while (low <= high && location == 0)
//	{
//		mid = (low + high) / 2;
//		if (x == a[mid])
//			location = mid + 1;
//		else if (x < a[mid])
//			high = mid - 1;
//		else
//		{
//			low = mid + 1;
//		}
//	}
//	return location;
//}
int merge(int a, int b, int c[], int d[], int e[])
{
	return 0;
}
void mergesort(int n, int a[])
{
	const int h = n / 2;
	const int m = n - h;
	int *u, *v;
	u = new int[h];
	v = new int[m];
	if (n > 0)
	{
		for (int i = 0; i < h; i++)
		{
			u[i] = a[i];
		}
		for (int j = h ; j < n; j++)
		{
			v[j] = a[j];
		}
		mergesort(h, u);
		mergesort(m, v);
		//merge(h, m, u, v, a);
	}
	delete[] u;
	delete[] v;
}

int main(void)
{
	int* s;
	s = new int[1000];
	int k;
	srand(time(NULL));
	cout << "put in one number" << endl;
	cin >> s[0];
	for (int i = 1; i < MAX; i++)
	{
		s[i] = rand();
	}


	exSort(MAX, s);
	for (int n = 0; n < MAX; n++)
	{
		cout << s[n] << " ";
	}
	int num;
	cin >> num;
	int asdf;
	asdf=location(LOW,MAX, s, num);

	if (asdf!=-1)
		cout << "Out of 1000 numbers... the number is in the  " << asdf << " th" << endl;
	else
		cout << "It is not in the list" << endl;

	mergesort(MAX, s);
	delete[] s;
	return 0;
}