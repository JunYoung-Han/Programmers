#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>

/*
	���� Ǯ��

	���� �� n ��
	Ư�� wire�� ������ ��, �� ������ ��ȸ�ϸ� ����� ������ ���ؾ��Ѵ�.
	���� wire�� �� ��带 �������� ��ȸ�Ͽ� ������ ���Ѵ�.
	���̰� 0�̸� �ٷ� return �Ѵ�.

	ó�������� �̿����� ����

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