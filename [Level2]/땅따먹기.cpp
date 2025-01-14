#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 2022 KAKAO BLIND RECRUITMENT
/*
	문제풀이
	시간 복잡도를 미리 고려해라.
	ㄴ DFS 완전 탐색은 안된다.

	nlogn 이나 n 의 복잡도 활용 (DP)
*/

// vector<vector<int>> vec;
// int answer = 0;
//void DFS(int val, int depth, int lastStep)
//{
//	if (depth == vec.size() - 1)
//	{
//		answer = max(answer, val);
//		return;
//	}
//
//	for (int i = 0; i < vec[depth + 1].size(); i++)
//	{
//		if (lastStep == i)
//			continue;
//
//		DFS(val + vec[depth + 1][i], depth + 1, i);
//	}
//}

int solution(vector<vector<int>> land)
{
	vector<vector<int>> dp(land.size(), vector<int>(4));
	int answer = 0;

	dp[0][0] = land[0][0];
	dp[0][1] = land[0][1];
	dp[0][2] = land[0][2];
	dp[0][3] = land[0][3];
	for (int i = 1; i < land.size(); i++)
	{
		dp[i][0] = land[i][0] + max(max(dp[i - 1][1], dp[i - 1][2]), dp[i - 1][3]);
		dp[i][1] = land[i][1] + max(max(dp[i - 1][0], dp[i - 1][2]), dp[i - 1][3]);
		dp[i][2] = land[i][2] + max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][3]);
		dp[i][3] = land[i][3] + max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
	}
	int last = land.size() - 1;
	answer = max(max(max(dp[last][0], dp[last][1]), dp[last][2]), dp[last][3]);

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	//solution({ 9, 1, 5, 3, 6, 2 });
	solution({ {1,2,3,5} ,{5,6,7,8},{4,3,2,1} });

	return 0;
}