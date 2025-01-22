#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 2022 KAKAO BLIND RECRUITMENT
/*
	����Ǯ��
	�������� �ȵ�

	Stack�� Ȱ���Ѵ�.
	���� �ε����� ���ÿ� �ְ�, ���� ���� ���ÿ� �� �ִ� �ε��� ���� ���� ���Ѵ�.

*/

vector<int> solution(vector<int> numbers) {
	vector<int> answer(numbers.size(), -1);
	stack<int> stack; // �ٲ��� ���� idx ����
	for (int i = 0; i < numbers.size(); i++)
	{
		while (stack.empty() == false)
		{
			if (numbers[stack.top()] >= numbers[i])
				break;
			else
			{
				answer[stack.top()] = numbers[i];
				stack.pop();
			}

		}
		stack.push(i);
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution({ 9, 1, 5, 3, 6, 2 });
	solution({ 2, 3, 3, 5 });

	return 0;
}