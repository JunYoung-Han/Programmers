#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// 2018 KAKAO BLIND RECRUITMENT
/*
	문제풀이
	거의 구현 문제이다. 단어 조합을 2개 조합부터 검사하기 시작한다.
	1. 해당 조합이 있으면 2개에서 3개 조합으로 다시 체크
	2. 1번을 해당 조합이 없을 때까지 반복
	3. 해당 조합이 없으면 조합을 사전에 추가하고 while 종료
	4. 이때 바깥 for 순회의 i 증가를 조합수 - 2 만큼 증가시킨다.
	ㄴ 조합한 단어의 마지막이 조합의 첫번째가 되어 다시 진행되어야 하기 때문
	ㄴ 조합수 - 2  인 이유는 만약, 조합 개수가 2개이면  for 문에서 자동으로 1 추가되어 조합의 마지막 글자부터 다시 시작되기 때문.

	느낀점
	차분히 방향부터 제대로 잡고 코드를 짜야되는데, 얼추 이러면 되겠다 라고 생각하니 되돌아가느라 시간이 더 걸렸다. 처음부터 제대로 풀었으면 시간이 절반정도로 줄었을 것 같다.
	풀이 방향을 제대로 세우고 코드를 적자.
*/

vector<int> solution(string msg) {
	vector<int> answer;

	// msg를 순회하면서 진행.
	map<string, int> alpha;
	char cur = 'A';
	for (int i = 0; i < 26; i++)
	{
		string str;
		str += cur + i;
		alpha.insert({ str, i + 1 });
	}

	for (int i = 0; i < msg.size(); i++)
	{
		// 2개 조합부터 있으면, -> 3개조합 테스트.
		// 걸릴때 까지 하는거다.
		int sumWordCount = 2;
		while (true)
		{
			string str;
			for (int k = 0; k < sumWordCount; k++)
				str += msg[i + k];
			// str: sumWordCount 개수 조합

			// 있으면 sumWordCount++ 해서 다시 체크 
			if (alpha.find(str) != alpha.end())
			{
				sumWordCount++;
				continue;
			}
			else
			{
				// 없으면 조합을 사전에 추가
				alpha.insert({ str,  alpha.size() + 1 });
				str.pop_back();
				answer.push_back(alpha[str]);
				i += sumWordCount - 2;
				break;
			}
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution("TOBEORNOTTOBEORTOBEORNOT");
	solution("TOBEORNOTTOBEORTOBEORNOT");

	return 0;
}