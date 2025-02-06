#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

/*
	문제 풀이

	노드는 총 n 개
	특정 wire를 끊었을 때, 각 집단을 순회하며 노드의 개수를 구해야한다.
	끊은 wire의 각 노드를 시작으로 순회하여 개수를 구한다.
	차이가 0이면 바로 return 한다.

	처음만나면 이웃들을 저장

*/

using namespace std;

map<int, vector<int>> m;
int GetNodeCountFromStart(const vector<vector<int>>& wires, int startNode, int excludeNode)
{
	int cnt = 1;
	queue<int> friends;
	map<int, bool> visited;

	friends.push(startNode);
	while (friends.empty() == false)
	{
		int front = friends.front();
		friends.pop();
		
		if (visited[front] || excludeNode == front)
			continue;

		for (int i = 0; i < m[front].size(); i++)
		{
			if (visited[m[front][i]] || excludeNode == m[front][i])
				continue;

			cnt++;
			friends.push(m[front][i]);
			visited[front] = true;
		}
	}

	return cnt;
}


int solution(int n, vector<vector<int>> wires) {
	int answer = n;

	for (int i = 0; i < wires.size(); i++)
	{
		m[wires[i][0]].push_back(wires[i][1]);
		m[wires[i][1]].push_back(wires[i][0]);
	}

	for (int i = 0; i < wires.size(); i++)
	{
		int countA = GetNodeCountFromStart(wires, wires[i][0], wires[i][1]);
		int countB = n - countA;
		if (countA == countB)
			return 0;

		answer = min(answer, abs(countA - countB));
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution(9, { {1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9} });

	return 0;
}