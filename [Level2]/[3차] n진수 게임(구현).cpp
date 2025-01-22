#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 2018 KAKAO BLIND RECRUITMENT
/*
	문제풀이
	// 1. 숫자 몇까지 n진법을 변환할 것인지 구해야함
	// 2. 변환하는 방법 세우기
	// 3. 순회하면서 몇번째 자리수를 가져와야하는지 구해야한다.

	풀이 방법
	// 1. 인원 m, 구할 숫자 개수: t
	// ㄴ 변환하여 수집한 숫자의 개수가 t * m 보다 커지면 그만 수집한다.
	// ㄴ 변환하면서 체크해야함
	// 2. 변환하는 함수 (TranferToNFormation)
	// 3. 자리수 가져오기
*/
string num = "0123456789ABCDEF";
string TranferToNFormation(int curNum, int nFormation)
{
	//curNum 를 n진법변환하여 집어넣는다.
	// 1. 몫을 구해
	// // 몫이 나눠지면 -> 나머지를 저장
	// // 몫이 안나눠지면 -> 나머지 저장 , 몫 저장
	// 저장된 애를 뒤집으면 변환 완료.
	// 이때 m이나 n 이 10 이상 부터인 경우 A 로 치환

	string transfered;
	if (curNum == 0)
		return "0";
	while (curNum > 0)
	{
		transfered += num[curNum % nFormation];
		curNum /= nFormation; // 몫
	}
	reverse(transfered.begin(), transfered.end());
	return transfered;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	int maxSize = t * m;
	int idx = 0;
	string transfer;
	while (true)
	{
		transfer += TranferToNFormation(idx, n);
  		if (transfer.length() > maxSize)
			break;
		idx++;
	}

	int cnt = 0;
	for (int i = 0; i < transfer.length(); i++)
	{
		if (answer.length() == t)
			break;
		cnt++;
		if (cnt == p)
			answer += transfer[i];
		if (cnt == m)
			cnt = 0;
	}
	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution(2, 4, 2, 1);
	solution(16, 16, 2, 2);

	return 0;
}