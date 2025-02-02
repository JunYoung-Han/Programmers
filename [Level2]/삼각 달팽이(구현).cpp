#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>

using namespace std;

/*
	문제풀이

	// ex
	1
	2 9
	3 10 8
	4 5  6 7

	=> x만 증가, y는 0
	0,0
	1,0
	2,0
	3,0
	4,0
	5,0

	=> x는 최대에서 고정 y는 증가
	5,1
	5,2
	5,3
	5,4
	5,5

	=> x,y 둘다 감소
	4,4
	3,3
	2,2
	1,1

	///

	=> x는 증가 (n - y 까지), y는 고정
	2,1
	3,1
	4,1

	=> x는 고정, y는 증가
	4,2
	4,3

	=> x,y 둘다 감소
	3,2

	///
	index 이동 방향
	(1, 0) => 1차원 index 증가
	(0, 1) => 2차원 index 증가
	(-1, -1) => 1,2차원 index 감소
	방향으로 회전하면서 값을 방문하고,
	방문한 값을 만나면 방향 전환
*/

enum Direction
{
	Down = 0,
	Right,
	Up
};

int dirI[] = { 1, 0, -1 };
int dirJ[] = { 0, 1, -1 };

vector<int> solution(int n) {
	vector<int> answer;

	vector<vector<int>> vec;
	for (int i = 0; i < n; i++)
	{
		vector<int> temp(i + 1);
		vec.push_back(temp);
	}

	int length = n * (n + 1) / 2;
	Direction dir = Down;
	int idxI = 0;
	int idxJ = 0;
	int val = 1;
	while (val <= length)
	{
		// index 범위 넘거나, 이미 값이 차있으면 next Dir
		if (idxI >= vec.size() || idxJ >= vec[idxI].size() || vec[idxI][idxJ] != 0)
		{
			idxI -= dirI[dir];
			idxJ -= dirJ[dir];
			dir = Direction((int)dir + 1);
			if (dir > Up)
				dir = Down;
		}
		else
		{
			vec[idxI][idxJ] = val;
			val++;
		}

		idxI += dirI[dir];
		idxJ += dirJ[dir];
	}

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
			answer.push_back(vec[i][j]);
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution(5);

	return 0;
}