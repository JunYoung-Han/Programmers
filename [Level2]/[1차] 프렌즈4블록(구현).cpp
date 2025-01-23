#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

/*
	문제풀이

	// 2x2 체크 함수
	// m(행)을 내리는 동작

	1. 조건을 만족하는 블록들을 캐싱한다.
	ㄴ 조건을 만족하는 블록이 없으면 종료한다.
	2. 해당 좌표의 블록을 삭제하고
	3. 해당 블록과 동일한 열의 높은 행에 있던 블록들의 위치를 옮긴다.
	4. 1~3 반복한다.


*/


int answer = 0;
vector<vector<bool>> vec;
int m, n = 0;
bool CheckCondition(vector<string> board)
{
	vec = vector<vector<bool>>(m, vector<bool>(n, false));
	bool rtn = false;
	// 순회하면서 해당 블록이 만족하는 블록인지 체크
	// LT, RT, LB, RB를 체크해서 캐싱해둔다.
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

	while (CheckCondition(board)) // 맞는 곳은 true 로 바뀜
	{
		DeleteBoard(board);// true 인곳은 위에 행으로 가져와 채우기
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