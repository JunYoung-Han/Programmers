#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

/*
	문제풀이

	BFS 문제.

*/
//
//// 상향식으로 푼 형식
//int solution(int x, int y, int n) {
//	int answer = -1;
//
//	// 너비 탐색
//	// 중복 되는 값은 visited 처리 해주기
//	map<int, bool> visited;
//	queue<pair<int, int>> q;
//	q.push(make_pair(x, 0));
//	while (q.empty() == false)
//	{
//		auto val = q.front();
//		q.pop();
//		if (visited[val.first])
//			continue;
//
//		if (val.first == y)
//			return val.second;
//
//		visited[val.first] = true;
//		if (visited[val.first * 3] == false && val.first * 3 <= y)
//			q.push(make_pair(val.first * 3, val.second + 1));
//		if (visited[val.first * 2] == false && val.first * 2 <= y)
//			q.push(make_pair(val.first * 2, val.second + 1));
//		if (visited[val.first + n] == false && val.first + n <= y)
//			q.push(make_pair(val.first + n, val.second + 1));
//	}
//
//	return answer;
//}

// 하향식
int solution(int x, int y, int n) {
	int answer = -1;

	// 너비 탐색
	// 중복 되는 값은 visited 처리 해주기
	map<int, bool> visited;
	queue<pair<int, int>> q;
	q.push(make_pair(y, 0));
	while (q.empty() == false)
	{
		auto val = q.front();
		int num = val.first;
		int cnt = val.second;
		q.pop();
		if (visited[num])
			continue;

		if (num == x)
			return cnt;

		visited[num] = true;
		if (num % 3 == 0 && visited[num / 3] == false)
			q.push(make_pair(num / 3, cnt + 1));
		if (num % 2 == 0 && visited[num / 2] == false)
			q.push(make_pair(num / 2, cnt + 1));
		if (num - n >= x && visited[num - n] == false)
			q.push(make_pair(num - n, cnt + 1));
	}

	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution(10, 40, 5);

	return 0;
}