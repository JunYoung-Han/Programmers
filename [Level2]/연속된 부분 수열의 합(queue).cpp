#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

/*
	����Ǯ��

	queue�� ���ڸ� �ְ�,
	queue ���� ���� �� sum�� ���Ѵ�.
	1. sum�� k �� ���,
	�� sum�� �ʱ�ȭ�ϰ�, q.pop ����, �ش� idx ����.
	�� �ش� �ε������� �ٽ� queue ���� ����
	2. sum�� k �̻��� ���
	�� queue�� ���� k���� �۰ų� ������ �� ���� pop �Ѵ�.
	�� �۾��� ���� ���� �ε����� ����

	���� ����
	- �ٵ� ���� ��� ���� ���̽��� vecIdx�� �����ؼ� sorting ���� �ʿ� ����, �׶� �׶� answer�� �������ָ� �ȴ�.
	- for�� �ȿ� ������ �� �� ��Ȯ�� �ڵ� ���� ����
	- �ʱ� answer �� idx ���� �ִ�� �ֱ� ���� answer[1]�� �ִ밪 ��������

*/

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer(2);
	answer[1] = 1000000;

	queue<int> q;
	int sum = 0;
	int sIdx = 0;
	for (int i = 0; i < sequence.size(); i++)
	{
		q.push(sequence[i]);
		sum += sequence[i];

		if (sum > k)
		{
			while (sum > k)
			{
				sum -= q.front();
				q.pop();
				sIdx++;
			}
		}
		if (sum == k)
		{
			if (answer[1] - answer[0] > i - sIdx)
			{
				answer[0] = sIdx;
				answer[1] = i;
			}
			sum -= q.front();
			q.pop();
			sIdx++;
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution({ 1, 1, 1, 2, 3, 4, 5 }, 5);

	return 0;
}