#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

/*
	����Ǯ��

	1. �ش� ���簢�� ������ ���� ��� ������?
	�� �´ٸ� �ϳ��� ����� -> �̶� �ϳ��� ������� �Ǵ��Ѵ�.
	�� �ٸ��ٸ� 4��� �ؼ� 1�� �ݺ�.
	
	// �ϳ��� ������ �Ǵ��ϱ�
	�� �ش� ������ Ư�� ���ڷ� ǥ���Ѵ�. => -1 �� ��ȯ
	�� ������ ������ �ش� ���� ��ü�� �����Ѵ�.
	���� ���� ���� �Ǵ��ϱ�
	�� ù��° ���� ���� areaUnit = arr.size()
	�� �ι�° ���� ���� areaUnit = areaUnit / 2;
	=> areaUnit == 1 �̰ų�, ���� ������ ��� ���࿵���̶�� stop
	
	������ ���� 0, 1 �� ���� ���� ���ں� ���� ����
	
	���� �׳� ���߼�ȸ �ϸ鼭 ������ üũ�ذ��µ�, DFS�� Ǯ�� �� �� ������ �ۼ� �� �� �־���.

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
		// areaUnit ũ���� ������ ���� �׷� ���� �Ǵ� �� üũ
		for (int startRow = 0; startRow < n; startRow += k) {
			for (int startCol = 0; startCol < n; startCol += k) {

				// k x k ���� ��ȸ
				int initVal = arr[startRow][startCol];
				if (initVal == -1)
					continue;

				bool isGroup = true;
				for (int i = 0; i < k; ++i) {
					for (int j = 0; j < k; ++j) {
						// �迭 ������ �ʰ����� �ʴ��� Ȯ��
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

				// �׷��̸� ���� ���ڷ� ó��
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