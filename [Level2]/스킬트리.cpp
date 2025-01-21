#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <queue>

using namespace std;

/*
	문제풀이

	특정 숫자가 나왔을 때 가능한지 보면 된다.
	스킬트리의 문자가 아니면 그냥 넘긴다.
	스킬트리의 문자가 나왔을 경우.
	ㄴ 해당 문자가 가능한지 체크한다.

*/

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++)
	{
		int enableOrder = 0;
		bool isEnable = true;
		string checkStr = skill_trees[i];
		for (int j = 0; j < checkStr.length(); j++)
		{
			int findOrder = skill.find(checkStr[j]);
			if (findOrder != string::npos)
			{
				if (findOrder == enableOrder)
					enableOrder++;
				else
				{
					isEnable = false;
					break;
				}
			}
		}
		if (isEnable)
			answer++;
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution("CBD", { "BACDE", "CBADF", "AECB", "BDA" });

	return 0;
}