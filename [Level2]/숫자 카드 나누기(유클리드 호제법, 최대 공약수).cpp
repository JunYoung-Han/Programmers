#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

/*
	문제 풀이

	- 유클리드 호제법을 통해 최대공약수 구하기

	1. ArrayN 의 n 개의 숫자에 최대 공약수가 있는지 확인,
	ㄴ 최대 공약수 : k
	2. ArrayM 원소중에 k로 나눠지는게 있으면 false

	3. ArrayN과 ArrayM 위치 바꿔서 한번 더 함
	4. 2번과 3번 값 비교해서 큰 거.

*/

using namespace std;

int GCD(int a, int b)
{
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}

	return a;
}

int solution(vector<int> arrayA, vector<int> arrayB)
{
	int answer = 0;

	int gcd = arrayA[arrayA.size() - 1];
	for (int i = arrayA.size() - 2; i >= 0; i--)
	{
		gcd = GCD(gcd, arrayA[i]);
		if (gcd == 1)
			break;
	}

	if (gcd != 1)
	{
		for (int i = 0; i < arrayB.size(); i++)
		{
			if (arrayB[i] % gcd == 0)
			{
				gcd = 1;
				break;
			}
		}
	}

	int gcd2 = arrayB[arrayB.size() - 1];
	for (int i = arrayB.size() - 2; i >= 0; i--)
	{
		gcd2 = GCD(gcd2, arrayB[i]);
		if (gcd2 == 1)
			break;
	}

	if (gcd2 != 1)
	{
		for (int i = 0; i < arrayA.size(); i++)
		{
			if (arrayA[i] % gcd2 == 0)
			{
				gcd2 = 1;
				break;
			}
		}
	}
	answer = max(gcd, gcd2);

	if (answer == 1)
		return 0;

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution({ 10, 20 }, { 5, 17 });

	return 0;
}