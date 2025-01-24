#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

/*
	����Ǯ��

	���� ���ؼ� 2�� ���� �� queue �� ������ ���� ���ڸ� ���Ѵ�.
	�� �̶� 2�� �ȳ������� -1 ����
	�� ���� �ϳ��� ���ݰ����� ũ�� ����

*/

int solution(vector<int> queue1, vector<int> queue2) {

	long targetSum = 0;
	int answer = 0;
	queue<int> q1;
	queue<int> q2;
	long sum = 0;
	for (int i = 0; i < queue1.size(); i++)
	{
		sum += queue1[i] + queue2[i];
		q1.push(queue1[i]);
		q2.push(queue2[i]);
	}
	if (sum % 2 != 0)
		return -1;

	targetSum = sum / 2;
	for (int i = 0; i < queue1.size(); i++)
	{
		if (queue1[i] > targetSum || queue2[i] > targetSum)
			return -1;
	}

	long sum1 = 0;
	for (int i = 0; i < q1.size(); i++)
	{
		int front = q1.front();
		sum1 += front;
		q1.pop();
		q1.push(front);
	}
	long sum2 = 0;
	for (int i = 0; i < q2.size(); i++)
	{
		int front = q2.front();
		sum2 += front;
		q2.pop();
		q2.push(front);
	}

	int limit = q1.size() + q2.size() + 1;
	while (sum1 != sum2)
	{
		if (answer > limit)
			return -1;

		if (sum1 < sum2)
		{
			// q2���� q1�� �ű�� case
			sum1 += q2.front();
			sum2 -= q2.front();
			q1.push(q2.front());
			q2.pop();
		}
		else
		{
			// q1���� q2���� �ű�� case
			sum1 -= q1.front();
			sum2 += q1.front();
			q2.push(q1.front());
			q1.pop();
		}
		answer++;
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution({ 3, 2, 7, 2 }, { 4, 6, 5, 1 });

	return 0;
}