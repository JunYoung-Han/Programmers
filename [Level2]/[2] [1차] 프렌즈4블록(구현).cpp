#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

/*
	����Ǯ��

	// 2x2 üũ �Լ�
	// m(��)�� ������ ����

	1. ������ �����ϴ� ��ϵ��� ĳ���Ѵ�.
	�� ������ �����ϴ� ����� ������ �����Ѵ�.
	2. �ش� ��ǥ�� ����� �����ϰ�
	3. �ش� ��ϰ� ������ ���� ���� �࿡ �ִ� ��ϵ��� ��ġ�� �ű��.
	4. 1~3 �ݺ��Ѵ�.


*/


int answer = 0;
vector<vector<bool>> vec;
int m, n = 0;
bool CheckCondition(vector<string> board)
{
	vec = vector<vector<bool>>(m, vector<bool>(n, false));
	bool rtn = false;
	// ��ȸ�ϸ鼭 �ش� ����� �����ϴ� ������� üũ
	// LT, RT, LB, RB�� üũ�ؼ� ĳ���صд�.
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].length(); j++)
		{
			char alpha = board[i][j];
			if (alpha == '-')
				continue;

			// LT
			if (i - 1 >= 0 && j - 1 >= 0)
			{
				if (alpha == board[i - 1][j - 1] && alpha == board[i][j - 1] && alpha == board[i - 1][j])
				{
					vec[i][j] = true;
					vec[i - 1][j - 1] = true;
					vec[i - 1][j] = true;
					vec[i][j - 1] = true;
					rtn = true;
				}
			}
			// RT
			if (i - 1 >= 0 && j + 1 < n)
			{
				if (alpha == board[i - 1][j + 1] && alpha == board[i][j + 1] && alpha == board[i - 1][j])
				{
					vec[i][j] = true;
					vec[i - 1][j + 1] = true;
					vec[i - 1][j] = true;
					vec[i][j + 1] = true;
					rtn = true;
				}
			}
			// LB
			if (i + 1 < m && j - 1 >= 0)
			{
				if (alpha == board[i + 1][j - 1] && alpha == board[i][j - 1] && alpha == board[i + 1][j])
				{
					vec[i][j] = true;
					vec[i + 1][j - 1] = true;
					vec[i + 1][j] = true;
					vec[i][j - 1] = true;
					rtn = true;
				}
			}
			// RB
			if (i + 1 < m && j + 1 < n)
			{
				if (alpha == board[i + 1][j + 1] && alpha == board[i][j + 1] && alpha == board[i + 1][j])
				{
					vec[i][j] = true;
					vec[i + 1][j + 1] = true;
					vec[i + 1][j] = true;
					vec[i][j + 1] = true;
					rtn = true;
				}
			}
		}
	}

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			if (vec[i][j])
				answer++;
		}
	}

	return rtn;
}

void DeleteBoard(vector<string>& board)
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].length(); j++)
		{
			if (vec[i][j])
			{
				int row = i;
				while (true)
				{
					if (row - 1 < 0)
						break;

					board[row][j] = board[row - 1][j];
					board[row - 1][j] = '-';
					row--;
				}
			}
		}
	}
}

int solution(int M, int N, vector<string> board) {
	m = M;
	n = N;

	while (CheckCondition(board)) // �´� ���� true �� �ٲ�
	{
		DeleteBoard(board);// true �ΰ��� ���� ������ ������ ä���
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution(6, 6, { "TTTANT",
					 "RRFACC",
					 "RRRFCC",
					 "TRRRAA",
					 "TTMMMF",
					 "TMMTTJ" });

	return 0;
}