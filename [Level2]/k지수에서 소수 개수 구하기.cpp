#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 2022 KAKAO BLIND RECRUITMENT
/*
	����Ǯ��
	// 1. k ������ �ٲٱ�
	// 2. �ٲ� �ſ��� 0 �������� ��� �ϳ��� üũ
	// 3. �Ҽ� �Ǻ��ϱ�

	// 0���� �� ���� temp�� ����, ������idx�� �ٷ� 0 �˻��ϰ� �ٷ� �ֱ�
	// 0������ temp ���尪�� �Ҽ� �Ǻ�
	// �Ҽ��̸� ī��Ʈ ����.
	// �� �̶� temp ����ֱ�
*/
bool CheckIsPrimeNumber(long long num)
{
	if (num <= 1)
		return false;
	for (long long i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

int solution(int n, int k) {
	int answer = 0;

	string kFormation;
	while (n > 0)
	{
		int rest = n % k;
		kFormation += to_string(rest);
		n /= k;
	}
	reverse(kFormation.begin(), kFormation.end());

	string temp;
	for (long long i = 0; i < kFormation.length(); i++)
	{
		if (kFormation[i] != '0')
			temp += kFormation[i];

		if (kFormation[i] == '0' || i == kFormation.length() - 1)
		{
			if (temp == "" || temp == "0")
				continue;
			long long num = stoll(temp);
			if (CheckIsPrimeNumber(num))
				answer++;
			temp = "";
		}
	}
	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution(437674, 3);

	return 0;
}