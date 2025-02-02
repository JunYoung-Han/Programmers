#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

/*
	문제 풀이

	일의 자리부터 자리수 늘려가며 순회
	1. 5 미만일 경우, 해당 자리수의 값만큼 + 해주기
	2. 5 초과일 경우,
	ㄴㄴ +(10 - 해당 자리수의 값)
	ㄴㄴ 해주고 해당 자리수 + 1의 자리수에 값을 +1 해준다.
	3. 5 일 경우
	- 해당 자리수 +1 자리수의 값이 5 이상인 경우 -> +5, 2번 케이스 해주고 (ex. 95)
	- 해당 자리수 +1 자리수의 값이 5 미만 인 경우 -> +5 해준다. (ex. 45)
	
	* 오답 노트
	해당 자리수가 5인 경우, 그 앞자리수의 값에 따라 분기해줘야 된다는 생각을 못하고 5이상인 케이스만 생각하고 푸느라 시간이 지체됐다.
	자리수의 값이 5인 경우 +(10 - 5)와 +5의 값이 동일하기 때문에 앞자리수에 따라 분기해줘야 한다.

	* 개선 사항
	굳이 string으로 바꿔서 어렵게 while문 할 필요 없이, 정수로 구현하면 더 간단해진다.
*/

using namespace std;

int solution(int storey) {
	int answer = 0;

	string val = to_string(storey);
	int length = val.length();
	for (int i = 0; i < length + 1; i++)
	{
		int tmp = storey % 10;
		if (tmp < 5)
			answer += tmp;
		else if (tmp > 5)
		{
			answer += (10 - tmp);
			storey += 10;
		}
		else if (tmp == 5)
		{
			answer += 5;
			int temp = storey / 10 % 10;
			if (temp >= 5)
				storey += 10;
		}
		storey /= 10;
	}

	//string val = to_string(storey);
	//reverse(val.begin(), val.end());
	//val += '0';
	//for (int i = 0; i < val.length(); i++)
	//{
	//	if (val[i] < '5')
	//		answer += val[i] - '0';
	//	else if (val[i] > '5')
	//	{
	//		answer += (10 - (val[i] - '0'));
	//		// 10 이상이 될 경우, 자리수 1 넘겨서 +1 해준다
	//		int n = 1;
	//		while (true)
	//		{
	//			if (val[i + n] + 1 == 10 + '0')
	//			{
	//				val[i + n] = '0';
	//				n++;
	//			}
	//			else
	//			{
	//				val[i + n] += 1;
	//				break;
	//			}
	//		}
	//	}
	//	else if (val[i] == '5')
	//	{
	//		answer += 5;
	//		if (val[i + 1] >= '5')
	//		{
	//			int n = 1;
	//			while (true)
	//			{
	//				if (val[i + n] + 1 == 10 + '0')
	//				{
	//					val[i + n] = '0';
	//					n++;
	//				}
	//				else
	//				{
	//					val[i + n] += 1;
	//					break;
	//				}
	//			}
	//		}
	//	}
	//}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution(95);

	return 0;
}