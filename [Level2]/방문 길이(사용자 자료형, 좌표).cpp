#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
Pos�� Line ����ü�� ���� ������ �����ߴ�.
dirs ������� �̵��� line���� �����صд�.
�̶� line�� ������ hash�� ���� string���� �����Ѵ�.
hash�Լ��� �ܼ��� "(���� Pos) + (ū Pos)" �� ���ڿ��� �ٲپ �����ߴ�.
*/

struct Pos
{
	int x = 0;
	int y = 0;

	int sum()
	{
		return x + y;
	}
};

struct Line
{
	Pos prev;
	Pos cur;

	string GetHash() 
	{
		Pos pos1;
		Pos pos2;
		if (prev.sum() < cur.sum())
		{
			pos1 = prev;
			pos2 = cur;
		}
		else
		{
			pos2 = prev;
			pos1 = cur;
		}
		string hash = to_string((pos1.x)) + to_string((pos1.y)) + to_string((pos2.x)) + to_string((pos2.y));
		return hash;
	}
};

int solution(string dirs) {
	int answer = 0;
	unordered_set<string> lines;
	Pos curPos;
	for (int i = 0; i < dirs.size(); i++)
	{
		// -> �̳�, <- �̳� ���� �����̸� �ߺ��� ���̴�.
		Line line;
		line.prev = curPos;
		char dir = dirs[i];
		if (dir == 'U')
		{
			if (curPos.y == 5)
				continue;
			curPos.y = curPos.y + 1;
		}
		else if (dir == 'D')
		{
			if (curPos.y == -5)
				continue;
			curPos.y = curPos.y - 1;
		}
		else if (dir == 'L')
		{
			if (curPos.x == -5)
				continue;
			curPos.x = curPos.x - 1;
		}
		else if (dir == 'R')
		{
			if (curPos.x == 5)
				continue;
			curPos.x = curPos.x + 1;
		}
		line.cur = curPos;
		lines.insert(line.GetHash());
	}
	answer = lines.size();
	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution("LULLLLLLU");

	return 0;
}