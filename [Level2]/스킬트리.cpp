#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <queue>

using namespace std;

/*
	����Ǯ��

	Ư�� ���ڰ� ������ �� �������� ���� �ȴ�.
	��ųƮ���� ���ڰ� �ƴϸ� �׳� �ѱ��.
	��ųƮ���� ���ڰ� ������ ���.
	�� �ش� ���ڰ� �������� üũ�Ѵ�.

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