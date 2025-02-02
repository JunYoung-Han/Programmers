#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

/*
	����Ǯ��

	��ȸ�ϸ鼭 stack�� ���ڸ� �ְ�,
	���� stack ���� ��ȸ�ϴ°� �� ũ�� ����

*/

using namespace std;

string solution(string number, int k) {
	string answer = "";

	stack<string> s;
	int minusCnt = 0;
	for (int i = 0; i < number.length(); i++)
	{
		string c;
		c += number[i];
		while (s.empty() == false && minusCnt < k)
		{
			string t = s.top();
			if (stoi(t) < stoi(c))
			{
				s.pop();
				minusCnt++;
			}
			else
				break;
		}
		s.push(c);
	}
	while (s.empty() == false)
	{
		answer += s.top();
		s.pop();
	}
	reverse(answer.begin(), answer.end());
	answer = answer.substr(0, answer.size() - (k - minusCnt));
	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution("333222111", 4);

	return 0;
}