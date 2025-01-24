#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

/*
	문제풀이

	1. 해당 정사각형 영역의 값이 모두 같은가?
	ㄴ 맞다면 하나로 만들기 -> 이때 하나의 개수라고 판단한다.
	ㄴ 다르다면 4등분 해서 1번 반복.
	
	// 하나의 개수로 판단하기
	ㄴ 해당 영역을 특정 숫자로 표기한다. => -1 로 전환
	ㄴ 영역을 잡으면 해당 영역 전체를 봐야한다.
	영역 단위 별로 판단하기
	ㄴ 첫번째 영역 단위 areaUnit = arr.size()
	ㄴ 두번째 영역 단위 areaUnit = areaUnit / 2;
	=> areaUnit == 1 이거나, 남은 영역이 모두 압축영역이라면 stop
	
	마지막 남은 0, 1 과 영역 단위 숫자별 개수 세기
	
	나는 그냥 이중순회 하면서 영역을 체크해갔는데, DFS로 풀면 좀 더 간단히 작성 할 수 있었다.

	#include <string>
	#include <vector>
	
	using namespace std;
	
	vector<vector<int>> MAP;
	
	void DFS(int x, int y, int Size, vector<int> &answer)
	{
		if (Size == 1)
		{
			if (MAP[x][y] == 0)
			{
				answer[0]++;
				return;
			}
			answer[1]++;
			return;
		}
	
		bool Zero, One;
		Zero = One = true;
		for (int i = x; i < x + Size; i++)
		{
			for (int j = y; j < y + Size; j++)
			{
				if (MAP[i][j] == 0) One = false;
				if (MAP[i][j] == 1) Zero = false;
			}
		}
	
		if (Zero == true)
		{
			answer[0]++;
			return;
		}
		if (One == true)
		{
			answer[1]++;
			return;
		}
	
		DFS(x, y, Size / 2, answer);
		DFS(x, y + Size / 2, Size / 2, answer);
		DFS(x + Size / 2, y, Size / 2, answer);
		DFS(x + Size / 2, y + Size / 2, Size / 2, answer);
	}
	
	vector<int> solution(vector<vector<int>> arr)
	{
		vector<int> answer(2, 0);
		MAP = arr;
		DFS(0, 0, arr.size(), answer);
		return answer;
	}
*/

int areaUnit;
int zeroGrpCnt = 0;
int oneGrpCnt = 0;
void CheckAnyGroup(int& k, vector<vector<int>>& arr)
{
	int n = arr.size();
	while (k > 1)
	{
		// areaUnit 크기의 영역의 값의 그룹 여부 판단 및 체크
		for (int startRow = 0; startRow < n; startRow += k) {
			for (int startCol = 0; startCol < n; startCol += k) {

				// k x k 내부 순회
				int initVal = arr[startRow][startCol];
				if (initVal == -1)
					continue;

				bool isGroup = true;
				for (int i = 0; i < k; ++i) {
					for (int j = 0; j < k; ++j) {
						// 배열 범위를 초과하지 않는지 확인
						int row = startRow + i;
						int col = startCol + j;
						if (row < n && col < n)
						{
							if (initVal != arr[row][col])
							{
								isGroup = false;
								break;
							}
						}
					}
					if (isGroup == false)
						break;
				}

				// 그룹이면 같은 숫자로 처리
				if (isGroup)
				{
					if (initVal == 0)
						zeroGrpCnt++;
					else
						oneGrpCnt++;

					for (int i = 0; i < k; ++i) {
						for (int j = 0; j < k; ++j) {
							int row = startRow + i;
							int col = startCol + j;
							if (row < n && col < n)
								arr[row][col] = -1;
						}
					}
				}
			}
		}
		k /= 2;
	}
}


vector<int> solution(vector<vector<int>> arr) {
	vector<int> answer(2);
	areaUnit = arr.size();

	CheckAnyGroup(areaUnit, arr);
	answer[0] = zeroGrpCnt;
	answer[1] = oneGrpCnt;

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] == 0)
				answer[0]++;
			else if (arr[i][j] == 1)
				answer[1]++;
		}
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution({
		{1,1,1,1,1,1,1,1} ,
		{0,1,1,1,1,1,1,1},
		{0,0,0,0,1,1,1,1},
		{0,1,0,0,1,1,1,1},
		{0,0,0,0,0,0,1,1},
		{0,0,0,0,0,0,0,1},
		{0,0,0,0,1,0,0,1},
		{0,0,0,0,1,1,1,1}
		});

	return 0;
}