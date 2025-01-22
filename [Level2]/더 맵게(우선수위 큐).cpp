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

	// queue���� �ϳ��� �̾Ƽ� k���� ������
	// ������ ������ new�Լ� �¿�
	// �� �̶� ������ ������ -1 ����
	// new ���� queue�� �־�
	// k �̻��� ���� ������ ����
	// �̰� queue�� ����� ������ �ݺ�

*/

int answer = 0;
int MixScoville(int smaller, int bigger)
{
	answer++;
	int newScoville = smaller + bigger * 2;
	return newScoville;
}

int solution(vector<int> scoville, int K) {

	priority_queue<int, vector<int>, greater<int>> queue;
	for (int i = 0; i < scoville.size(); i++)
		queue.push(scoville[i]);

	while (queue.empty() == false)
	{
		int val1 = queue.top();
		if (val1 < K)
		{
			queue.pop();
			if (queue.empty())
				return -1;

			int val2 = queue.top();
			queue.pop();

			int newVal = MixScoville(val1, val2);
			queue.push(newVal);
		}
		else
			break;
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution({ 9, 1, 5, 3, 6, 2 });
	solution({ 1, 2, 3, 9, 10, 12 }, 7);

	return 0;
}