#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

/*
	����Ǯ��

	1. �ٸ��� ���� �ִ� ���
	�� �ش� ������ �ܿ� �Ÿ��� -1�� �ٲ۴�.
	�� �̶� ���� �Ÿ��� < 0 �Ǹ� �ٸ��� �ǳ� ó��

	2. ����ϴ� ������ �ٸ� ���� �������� üũ �� �ٸ� ����
	�� �ٸ��� ��� �ִ��� �˻� + ���� �ִ� ���ϸ� �ű��

*/


int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;

	queue<pair<int, int>> wait; // idx, weight
	map<int, int> map; // idx, �ܿ��Ÿ�
	for (int i = 0; i < truck_weights.size(); i++)
	{
		wait.push(make_pair(i, truck_weights[i]));
		map[i] = bridge_length;
	}

	queue<pair<int, int>> onBridgeCar;// idx, weight
	int done = 0;
	while (true)
	{
		// �ٸ��� �ִ� ���� �̵�
		int onBridgeCarLength = onBridgeCar.size();
		if (onBridgeCarLength > 0)
		{
			for (int i = 0; i < onBridgeCarLength; i++)
			{
				auto front = onBridgeCar.front();
				onBridgeCar.pop();
				map[front.first] -= 1;
				// �ٸ� �� �ǳ� ���¸� �ٽ� push
				if (map[front.first] >= 0)
					onBridgeCar.push(front);
				else
					done++;
			}
		}

		// ��� ���� �ٸ��� �ű��
		// �ٸ��� ������ ���԰� ������� üũ
		if (wait.empty() == false)
		{
			onBridgeCarLength = onBridgeCar.size();
			if (onBridgeCarLength > 0)
			{
				int sumWeight = 0;
				for (int i = 0; i < onBridgeCarLength; i++)
				{
					auto front = onBridgeCar.front();
					onBridgeCar.pop();
					sumWeight += front.second;
					onBridgeCar.push(front);
				}

				auto front = wait.front();
				if (front.second + sumWeight <= weight)
				{
					// �ٸ��� �ö󰡴� ó��
					wait.pop();
					onBridgeCar.push(front);
					map[front.first] -= 1;
				}

			}
			else
			{
				// �ٸ��� �ö󰡴� ó��
				auto front = wait.front();
				wait.pop();
				onBridgeCar.push(front);
				map[front.first] -= 1;
			}
		}

		answer++;

		if (done == truck_weights.size())
			break;
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution(2, 10, { 7, 4, 5, 6 });

	return 0;
}