#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <map>

using namespace std;

/*
	����Ǯ��

	// ex
	1
	2 9
	3 10 8
	4 5  6 7

	=> x�� ����, y�� 0
	0,0
	1,0
	2,0
	3,0
	4,0
	5,0

	=> x�� �ִ뿡�� ���� y�� ����
	5,1
	5,2
	5,3
	5,4
	5,5

	=> x,y �Ѵ� ����
	4,4
	3,3
	2,2
	1,1

	///

	=> x�� ���� (n - y ����), y�� ����
	2,1
	3,1
	4,1

	=> x�� ����, y�� ����
	4,2
	4,3

	=> x,y �Ѵ� ����
	3,2

	///
	index �̵� ����
	(1, 0) => 1���� index ����
	(0, 1) => 2���� index ����
	(-1, -1) => 1,2���� index ����
	�������� ȸ���ϸ鼭 ���� �湮�ϰ�,
	�湮�� ���� ������ ���� ��ȯ
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
		// index ���� �Ѱų�, �̹� ���� �������� next Dir
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