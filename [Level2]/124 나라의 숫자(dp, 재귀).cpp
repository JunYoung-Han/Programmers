#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

/*
	문제풀이

	1. 먼저 Head와 number를 구별해는 함수
	2. head 부분으로 사전 순 정렬
	// ㄴ 이때 소문자로 체크, 동일한 경우, 입력순서로
	3. 이후 Number로 정렬
	// ㄴ 0023 같은 숫자와 12를 비교하는 함수 만들기

	실수 조심!!!
	sort 할거면 sort 대상의 vector의 값으로 이루어진 compare 함수를 만들어야 한다.
	나는 sort는 인덱스만 저장된 벡터를 하고 compare 함수는 해당 인덱스를 참조하는 map에서 값을 가져와 비교하는 식으로 했다.
	이러면 안된다!!!

*/

using namespace std;

unordered_map<int, string> dp;

string solve(int n) {
	if (dp.count(n)) return dp[n];

	if (n < 4) return vector<string>{"4", "1", "2", "4"} [n] ;

	return dp[n] = solve((n - 1) / 3) + solve(n % 3);
}

string solution(int n) {
	return solve(n);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	solution(1);

	return 0;
}