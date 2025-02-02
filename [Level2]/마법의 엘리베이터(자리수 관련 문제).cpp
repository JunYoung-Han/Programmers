#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

/*
	���� Ǯ��

	���� �ڸ����� �ڸ��� �÷����� ��ȸ
	1. 5 �̸��� ���, �ش� �ڸ����� ����ŭ + ���ֱ�
	2. 5 �ʰ��� ���,
	���� +(10 - �ش� �ڸ����� ��)
	���� ���ְ� �ش� �ڸ��� + 1�� �ڸ����� ���� +1 ���ش�.
	3. 5 �� ���
	- �ش� �ڸ��� +1 �ڸ����� ���� 5 �̻��� ��� -> +5, 2�� ���̽� ���ְ� (ex. 95)
	- �ش� �ڸ��� +1 �ڸ����� ���� 5 �̸� �� ��� -> +5 ���ش�. (ex. 45)
	
	* ���� ��Ʈ
	�ش� �ڸ����� 5�� ���, �� ���ڸ����� ���� ���� �б������ �ȴٴ� ������ ���ϰ� 5�̻��� ���̽��� �����ϰ� Ǫ���� �ð��� ��ü�ƴ�.
	�ڸ����� ���� 5�� ��� +(10 - 5)�� +5�� ���� �����ϱ� ������ ���ڸ����� ���� �б������ �Ѵ�.

	* ���� ����
	���� string���� �ٲ㼭 ��ư� while�� �� �ʿ� ����, ������ �����ϸ� �� ����������.
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
	//		// 10 �̻��� �� ���, �ڸ��� 1 �Ѱܼ� +1 ���ش�
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