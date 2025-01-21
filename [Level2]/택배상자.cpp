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

	stack�� Ȱ���Ѵ�.

	order�� ����� i�� ���������� i�� stack�� ����
	order�� ��ġ�ϸ� answer ����
	order�� ��ġ���� ������ i�� ����� stack���� ���� �� �ִ��� üũ
	�� ���� �� ������ stack�� ������ answer ����
	�� ���� �� ������ i�� stack�� �ֱ�

	order�� �� ��ġ���� ��,
	���� order�� stack.top�� ��.
	�� ���� ���� �� ���� or stack ��ﶧ���� �ݺ�
*/

int solution(vector<int> order) {
	int answer = 0;

	stack<int> stack;

	int curOrder = 0;
	for (int j = 1; j <= order.size(); j++)
	{
		if (order[curOrder] == j)
		{
			curOrder++;
			answer++;
		}
		else
		{
			if (stack.empty() == false && stack.top() == order[curOrder])
			{
				stack.pop();
				curOrder++;
				answer++;
			}
			else
			{
				stack.push(j);
			}
		}

		// ����, top�� ������ �ݺ��ؼ� üũ�ؾ��Ѵ�.

		while (stack.empty() == false)
		{
			int topVal = stack.top();
			if (topVal == order[curOrder])
			{
				stack.pop();
				curOrder++;
				answer++;
			}
			else
				break;
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution({ 4, 3, 1, 2, 5 });
	solution({ 5, 4, 3, 2, 1 });
	// 1, 2, 3, 4 ���� stack�� ����
	// 5�� �� ���� ��ġ�ϹǷ� ����
	// ���� order�� ���� ����(4) �� stack�� ���� ��ġ�ϹǷ� ��
	// �� or

	return 0;
}