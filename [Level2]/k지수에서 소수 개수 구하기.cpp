#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// 2022 KAKAO BLIND RECRUITMENT
/*
	문제풀이
	// 1. k 진수로 바꾸기
	// 2. 바꾼 거에서 0 기준으로 끊어서 하나씩 체크
	// 3. 소수 판별하기

	// 0만날 때 까지 temp에 저장, 마지막idx면 바로 0 검사하고 바로 넣기
	// 0만나면 temp 저장값을 소수 판별
	// 소수이면 카운트 증가.
	// ㄴ 이때 temp 비워주기
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