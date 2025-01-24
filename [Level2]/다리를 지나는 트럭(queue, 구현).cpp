#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

/*
	문제풀이

	1. 다리에 차가 있는 경우
	ㄴ 해당 차량의 잔여 거리를 -1로 바꾼다.
	ㄴ 이때 남은 거리가 < 0 되면 다리를 건넌 처리

	2. 대기하는 차량이 다리 입장 가능한지 체크 후 다리 입장
	ㄴ 다리에 몇대 있는지 검사 + 무게 최대 이하면 옮기기

*/


int solution(int bridge_length, int weight, vector<int> truck_weights)
{
	int answer = 0;

	queue<pair<int, int>> wait; // idx, weight
	map<int, int> map; // idx, 잔여거리
	for (int i = 0; i < truck_weights.size(); i++)
	{
		wait.push(make_pair(i, truck_weights[i]));
		map[i] = bridge_length;
	}

	queue<pair<int, int>> onBridgeCar;// idx, weight
	int done = 0;
	while (true)
	{
		// 다리에 있는 차량 이동
		int onBridgeCarLength = onBridgeCar.size();
		if (onBridgeCarLength > 0)
		{
			for (int i = 0; i < onBridgeCarLength; i++)
			{
				auto front = onBridgeCar.front();
				onBridgeCar.pop();
				map[front.first] -= 1;
				// 다리 안 건넌 상태면 다시 push
				if (map[front.first] >= 0)
					onBridgeCar.push(front);
				else
					done++;
			}
		}

		// 대기 차량 다리로 옮기기
		// 다리에 공간과 무게가 충분한지 체크
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
					// 다리에 올라가는 처리
					wait.pop();
					onBridgeCar.push(front);
					map[front.first] -= 1;
				}

			}
			else
			{
				// 다리에 올라가는 처리
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