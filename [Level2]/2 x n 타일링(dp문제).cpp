#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

/*
	문제풀이

	dp 문제였던 거 같은데..
	// 1칸 남았을 경우에 다음에 올 가지 수 는 1가지
	// 2칸 남았을 경우, 다음에 올 가지 수는 2가지
	// 3칸 남았을 경우, 다음에 올 가지 수 는 3가지

*/


int solution(int n) {
	int answer = 0;

	vector<long long> d(n + 1);
	d[0] = 0;
	d[1] = 1;
	d[2] = 2;
	d[3] = 3;

	for (long long i = 4; i <= n; i++)
		d[i] = (d[i - 2] * 2 + d[i - 3]) % 1000000007;

	answer = d[n];
	return answer;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution(59812);

	return 0;
}