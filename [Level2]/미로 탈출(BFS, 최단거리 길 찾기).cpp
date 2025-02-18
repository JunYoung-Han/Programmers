#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>

/*
	문제 풀이

	DFS로 풀어보기

	1. 레버로 가는 최단 시간

	2. 출구로 가는 최단 시간

	아 DFS가 아니라 BFS 로 풀어야댐
	최단거리를 구할거기 때문에.

*/

using namespace std;

struct Node
{
	int x, y, dist;
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

vector<string> M;
vector<vector<bool>> Visited;

int BFS(char target, int x, int y)
{
	queue<Node> q;
	q.push({ x, y, 0 });
	Visited[y][x] = true;

	while (q.empty() == false)
	{
		Node curr = q.front();
		q.pop();

		// 목표 도달 시 거리 반환
		if (M[curr.y][curr.x] == target)
			return curr.dist;

		// 맵 범위 체크
		for (int i = 0; i < 4; i++)
		{
			int nextX = curr.x + dx[i];
			int nextY = curr.y + dy[i];

			if (nextX < 0 || nextX >= M[0].size() || nextY < 0 || nextY >= M.size())
				continue;

			if (M[nextY][nextX] == 'X' || Visited[nextY][nextX])
				continue;

			Visited[nextY][nextX] = true;
			// 이웃들을 push 한다.
			q.push({ nextX, nextY, curr.dist + 1 });
		}
	}
	return -1;
}


//int DFS(char target, int x, int y, int depth)
//{
//	if (M[y][x] == target)
//		return depth;
//
//	Visited[y][x] = true;
//	int answer = INT_MAX;
//	for (int i = 0; i < 4; i++)
//	{
//		int tempX = x + dx[i];
//		int tempY = y + dy[i];
//		if (tempX < 0 || tempX >= M[0].size() || tempY < 0 || tempY >= M.size())
//			continue;
//
//		if (M[tempY][tempX] == 'X' || Visited[tempY][tempX])
//			continue;
//
//		int temp = DFS(target, tempX, tempY, depth + 1);
//		if (temp != -1)
//			answer = min(answer, temp);
//	}
//	Visited[y][x] = false;
//
//	return answer == INT_MAX ? -1 : answer;
//}


int solution(vector<string> maps) {
	int answer = 0;
	M = maps;
	Visited.resize(maps.size(), vector<bool>(maps[0].size(), false));

	int startX = 0;
	int startY = 0;
	int leverX = 0;
	int leverY = 0;
	for (int i = 0; i < maps.size(); i++)
	{
		for (int j = 0; j < maps[i].size(); j++)
		{
			if (maps[i][j] == 'S')
			{
				startX = j;
				startY = i;
			}
			else if (maps[i][j] == 'L')
			{
				leverX = j;
				leverY = i;
			}
		}
	}


	int toStart = BFS('L', startX, startY);
	if (toStart == -1)
		return -1;

	for (auto& row : Visited)
		fill(row.begin(), row.end(), false);

	int toEnd = BFS('E', leverX, leverY);
	if (toEnd == -1)
		return -1;

	answer = toStart + toEnd;
	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution({ "SOOOL","XXXXO","OOOOO","OXXXX","OOOOE" });
	//solution({ "LOOXS","OOOOX","OOOOO","OOOOO","EOOOO" });

	return 0;
}